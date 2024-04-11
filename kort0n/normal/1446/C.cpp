#include <bits/stdc++.h>
//#include <atcoder/all>
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

ll g(ll x) {
    if(x == 0) return 0;
    return 1 + g(x / 2);
}

ll f(vector<ll> a) {
    if(a.empty()) return 0;
    if(a.size() == 1) return 1;
    //cerr << "---------------------" << endl;
    map<ll, vector<ll>> mp;
    for(auto tmp : a) {
        mp[g(tmp)].push_back(tmp);
    }
    vector<vector<ll>> v;
    for(auto tmp : mp) {
        v.push_back(tmp.second);
    }
    ll ret = 0;
    /*
    for(auto tmp : mp) {
        auto v = tmp.second;
        cerr << "---" << tmp.first << "---" << endl;
        cerr << "{";
        for(int i = 0; i < v.size(); i++) {
            cerr << v[i] << " ";
        }
        cerr << "}" << endl;
    }
    */
    for(int i = 0; i < v.size(); i++) {
        vector<ll> u;
        ll d = g(v[i][0]);
        for(auto tmp : v[i]) {
            ll q = tmp;
            if(d) q -= (1 << (d - 1));
            u.push_back(q);
        }
        //cerr << v[i].size() << " " << u.size() << endl;
        ll tmp = f(u);
        if(i >= 1) tmp++;
        tmp += (v.size() - 1 - i);
        chmax(ret, tmp);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll ans = f(a);
    cout << N - ans << endl;
    return 0;
}