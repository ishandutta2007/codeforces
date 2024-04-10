#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using itn = int;

int dir(pll& p1, pll& p2, pll& p3){
    ll val = (p1.first - p2.first) * (p3.second - p2.second) - (p1.second - p2.second) * (p3.first - p2.first);
    if(val == 0) {
        return 0;
    }
    if(val > 0){
        return 1;
    }
    return -1;
}

vector<ld> solve(int sz){
    vector<pll> p(sz);
    for(int i = 0; i < sz; ++i){
        cin >> p[i].first >> p[i].second;
    }
    sort(all(p));
    vector<pll> upper, lower, upp, low;
    for(int i = 1; i < sz - 1; ++i){
        int val = dir(p[0], p[i], p[sz - 1]);
        if(val == 1){
            upper.push_back(p[i]);
        }else if(val == -1){
            lower.push_back(p[i]);
        }
    }
    upper.push_back(p[sz - 1]);
    reverse(all(lower));
    lower.push_back(p[0]);
    upp.push_back(p[0]);
    low.push_back(p[sz - 1]);
    if(upper.size() > 1){
        upp.push_back(upper[0]);
        for(int i = 1; i < upper.size(); ++i){
            while(upp.size() >= 2 && dir(upp[upp.size() - 2], upp[upp.size() - 1], upper[i]) != 1){
                upp.pop_back();
            }
            upp.push_back(upper[i]);
        }
        upp.pop_back();
    }
    if(lower.size() > 1){
        low.push_back(lower[0]);
        for(int i = 1; i < lower.size(); ++i){
            while(low.size() >= 2 && dir(low[low.size() - 2], low[low.size() - 1], lower[i]) != 1){
                low.pop_back();
            }
            low.push_back(lower[i]);
        }
        low.pop_back();
    }
    for(int i = 0; i < low.size(); ++i){
        upp.push_back(low[i]);
    }
    vector<ld> ans;
    for(int i = 0; i < upp.size(); ++i){
        int nxt = (i + 1) % upp.size();
        int prv = (i + (int)upp.size() - 1) % upp.size();
        ld d1 = hypot(upp[i].first - upp[prv].first, upp[i].second - upp[prv].second);
        ld d2 = hypot(upp[i].first - upp[nxt].first, upp[i].second - upp[nxt].second);
        ld d3 = hypot(upp[nxt].first - upp[prv].first, upp[nxt].second - upp[prv].second);
        ans.push_back(d1);
        ans.push_back((d1 * d1 + d2 * d2 - d3 * d3) / (2 * d1 * d2));
    }
    return ans;
}

const ld eps = 1e-14;

bool good(vector<ld>& a, vector<ld>& b){
    if(a.size() != b.size()){
        return false;
    }
    vector<ld> x;
    for(auto o: a){
        x.push_back(o);
    }
    x.push_back(1e16);
    for(auto o: b){
        x.push_back(o);
    }
    for(auto o: b){
        x.push_back(o);
    }
    vector<int> z(x.size(), 0);
    int l = -1, r = -1;
    for(int i = 1; i < x.size(); ++i){
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < x.size() && fabs(x[i + z[i]] - x[z[i]]) < eps){
            ++z[i];
        }
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    for(int i = a.size() + 1; i < x.size(); i += 2){
        if(z[i] >= a.size()){
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ld> a = solve(n);
    vector<ld> b = solve(m);
    if(good(a, b)){
        cout << "yEs" << endl;
    }else{
        cout << "nO" << endl;
    }
    return 0;
}