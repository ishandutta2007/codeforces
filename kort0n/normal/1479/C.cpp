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
ll L, R;
vector<l_l> edges[40];
set<ll> st[40];
void f(int from, int to, ll c) {
    //cerr << "f: " << from << " " << to << " " << c << endl;
    assert(1 <= c and c <= 1e6);
    edges[from].push_back({to, c});
    for(auto tmp : st[from]) {
        ll newc = c + tmp;
        assert(st[to].find(newc) == st[to].end());
        st[to].insert(newc);
    }
}

using lll = pair<l_l, ll>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> L >> R;
    ll N = 23;
    st[0].insert(0);
    for(int i = 1; i < N - 1; i++) {
        f(0, i, 1);
        for(int j = 1; j < i; j++) {
            auto itr = st[i].end();
            itr--;
            ll maxi = *itr;
            itr = st[j].begin();
            ll mini = *itr;
            f(j, i, maxi - mini + 1);
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        cerr << i << " " << st[i].size() << endl;
    }
    */
    R++;
    for(int i = N - 2; i >= 0; i--) {
        if(st[i].size() > R - L) continue;
        auto itr = st[i].end();
        itr--;
        ll c = R - 1 - *itr;
        if(1 <= c and c <= 1e6) {
            f(i, N - 1, c);
            R -= st[i].size();
            //cerr << R << endl;
        }
    }
    assert(L == R);
    vector<lll> ans;
    for(int i = 0; i < N; i++) {
        for(auto tmp : edges[i]) {
            ans.push_back({{i, tmp.first}, tmp.second});
        }
    }
    cout << "YES" << endl;
    cout << N << " " << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first.first+1 << " " << tmp.first.second+1 << " " << tmp.second << endl;
    }
    return 0;
}