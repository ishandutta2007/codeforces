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
ll a[201000];
vector<ll> edges[201000];
ll ans;
ll d[201000];
ll N;

void f() {
    queue<ll> que[3];
    for(int i = 0; i < N; i++) {
        d[i] = edges[i].size();
        if(d[i] == 1) {
            que[a[i]].push(i);
        }
    }
    for(ll t = 1; ; t++) {
        ll T = (t % 2) + 1;
        while(!que[0].empty() or !que[T].empty()) {
            ll now;
            if(!que[0].empty()) {
                now = que[0].front();
                que[0].pop();
            } else {
                now = que[T].front();
                que[T].pop();
            }
            for(auto to : edges[now]) {
                d[to]--;
                if(d[to] == 1) {
                    que[a[to]].push(to);
                }
            }
        }
        if(que[0].empty() and que[1].empty() and que[2].empty()) {
            chmin(ans, t);
            return;
        }
    }
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    ans = INF;
    f();
    for(int i = 0; i < N; i++) {
        if(a[i] == 2) a[i] = 1;
        else if(a[i] == 1) a[i] = 2;
    }
    f();
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}