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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
int N;
vector<int> paths[205000];
ll depth[205000], SIZE[205000];
vector<ll> a;

void dfs(int now, int from) {
    SIZE[now] = 1;
    for(auto to : paths[now]) {
        if(to == from) continue;
        depth[to] = depth[now] + 1;
        dfs(to, now);
        SIZE[now] += SIZE[to];
    }
    a.push_back(depth[now] - SIZE[now] + 1);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll K;
    cin >> K;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(0, -1);
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0; i < K; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}