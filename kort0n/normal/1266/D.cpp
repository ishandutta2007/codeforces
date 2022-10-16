#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
typedef pair<l_l, ll> lll;
ll Out[105000];
vector<ll> Plus, Minus;
vector<lll> ans;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    while(M--) {
        ll a, b, c;
        cin >> a >> b >> c;
        Out[a] += c;
        Out[b] -= c;
    }
    for(int i = 1; i <= N; i++) {
        if(Out[i] > 0) Plus.push_back(i);
        if(Out[i] < 0) Minus.push_back(i);
    }
    while(!Plus.empty()) {
        int p = Plus.back();
        int m = Minus.back();
        Plus.pop_back();
        Minus.pop_back();
        ll delta = min(Out[p], -Out[m]);
        ans.push_back({{p, m}, delta});
        Out[p] -= delta;
        Out[m] += delta;
        if(Out[p]) Plus.push_back(p);
        if(Out[m]) Minus.push_back(m);
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first.first << " " << tmp.first.second << " " << tmp.second << endl;
    }
    return 0;
}