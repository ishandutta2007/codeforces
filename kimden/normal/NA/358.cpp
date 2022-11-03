#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll n, xx, yy;

vector<pll> c;

int solve(vector<ll>& a, vector<ll>& b, vector<ll>& res1, vector<ll>& res2){
    vector<ll> sth(n, -1);
    for(int i = 0; i < n; ++i){
        if(a[i] <= i + 1){
            sth[i] = i;
        }else if(i){
            sth[i] = sth[i - 1];
        }
    }
    for(int j = 1; j < n; ++j){
        ll val = j + 1 - b[j];
        int L = 0;
        int R = j;
        int mid;
        if(a[0] > val){
            continue;
        }
        while(R - L > 1){
            mid = (R + L) / 2;
            if(a[mid] > val){
                R = mid;
            }else{
                L = mid;
            }
        }
        if(sth[L] != -1){
            int ii = sth[L];
            int jj = j;
            int cnt1 = a[ii];
            int cnt2 = b[jj];
            for(int i = 0; i <= jj; ++i){
                if(cnt1){
                    res1.push_back(c[i].second);
                    --cnt1;
                }else{
                    res2.push_back(c[i].second);
                    --cnt2;
                }
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> xx >> yy;
    vector<ll> a, b;
    c.resize(n);
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(rall(c));
    for(int i = 0; i < n; ++i){
        a[i] = (xx + c[i].first - 1) / c[i].first;
        b[i] = (yy + c[i].first - 1) / c[i].first;
    }
    vector<ll> res1, res2;
    if(solve(a, b, res1, res2)){
        cout << "Yes" << endl;
        cout << res1.size() << " " << res2.size() << endl;
        for(int i = 0; i < res1.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res1[i] + 1;
        }
        cout << endl;
        for(int i = 0; i < res2.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res2[i] + 1;
        }
        cout << endl;
    }else if(solve(b, a, res2, res1)){
        cout << "Yes" << endl;
        cout << res1.size() << " " << res2.size() << endl;
        for(int i = 0; i < res1.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res1[i] + 1;
        }
        cout << endl;
        for(int i = 0; i < res2.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res2[i] + 1;
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}