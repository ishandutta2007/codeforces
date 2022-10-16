#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
vector<l_l> IN[501000];
vector<l_l> v;

l_l f(ll border) {
    //cerr << "-------" << border << "-------" << endl;
    vector<ll> x;
    for(int i = 0; i < v.size(); i++) {
        x.push_back(v[i].first);
        x.push_back(v[i].first + border);
        if(v[i].first - border >= 0) x.push_back(v[i].first - border);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    /*
    for(auto tmp : x) {
        cerr << tmp << " ";
    }
    cerr << endl;
    */
    for(auto b : x) {
        //cerr << "b = " << b << endl;
        ll maxi = 5e5;
        ll mini = 0;
        if(b == 0) mini = 1;
        for(auto tmp : v) {
            ll bnow = tmp.first;
            ll nnow = tmp.second;
            if(abs(bnow - b) > border) maxi = -1;
            if(b >= bnow) {
                ll delta = b - bnow;
                chmin(maxi, nnow + border);
                chmax(mini, nnow - (border - delta));
            } else {
                ll delta = bnow - b;
                chmax(mini, nnow - border);
                chmin(maxi, nnow + (border - delta));
            }
            //cerr << bnow << " " << nnow << " " << mini << " " << maxi << endl;
        }
        if(maxi >= mini) {
            //cerr << border << " " << b << " " << mini << " " << maxi << endl;
            return {b, mini};
        }
    }
    return {-1, -1};
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        ll A = 0;
        ll B = 0;
        string S;
        cin >> S;
        for(auto c : S) {
            if(c == 'B') B++;
            else A++;
        }
        IN[B].push_back({B, A});
    }
    for(int i = 0; i <= 5e5; i++) {
        if(IN[i].empty()) continue;
        if(IN[i].size() == 1) {
            v.push_back(IN[i][0]);
            continue;
        }
        sort(IN[i].begin(), IN[i].end());
        v.push_back(IN[i][0]);
        v.push_back(IN[i].back());
    }
    cerr << v.size() << endl;
    ll ok = 5e5;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        auto tmp = f(mid);
        if(tmp.first == -1) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    auto ans = f(ok);
    cout << ok << endl;
    for(int i = 0; i < ans.first; i++) cout << "B";
    for(int i = 0; i < ans.second; i++) cout << "N";
    cout << endl;
    return 0;
}