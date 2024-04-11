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

int T;
int N, M;
ll b[3005], w[3005];
vector<ll> paths[3005];
vector<l_l> dp[3005];

void merge(vector<l_l> &a, vector<l_l> b) {
    vector<l_l> ret1(a.size() + b.size() - 1);
    for(int i = 0; i < ret1.size(); i++) {
        ret1[i] = {0, -1e17};
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            l_l tmp;
            tmp.first += a[i].first;
            tmp.first += b[j].first;
            tmp.second += a[i].second;
            tmp.second += b[j].second;
            chmax(ret1[i+j], tmp);
        }
    }
    vector<l_l> ret2(a.size() + b.size());
    for(int i = 0; i < ret2.size(); i++) {
        ret2[i] = {0, -1e17};
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            l_l tmp = a[i];
            tmp.first += b[j].first;
            if(b[j].second > 0) {
                tmp.first++;
            }
            chmax(ret2[i+j+1], tmp);
        }
    }
    for(int i = 0; i < ret1.size(); i++) {
        chmax(ret2[i], ret1[i]);
    }
    swap(ret2, a);
}

void f(int now, int from) {
    dp[now].push_back({0, w[now] - b[now]});
    for(auto to : paths[now]) {
        if(to == from) continue;
        f(to, now);
        merge(dp[now], dp[to]);
    }
    //cerr << "----" << now << "----" << endl;
    //for(auto val : dp[now]) cerr << "{" << val.first << ", " << val.second << "} ";
    //cerr << endl;
}

void solve() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
        paths[i].clear();
        dp[i].clear();
    }
    for(int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    f(1, -1);
    ll ans = dp[1][M-1].first;
    if(dp[1][M-1].second > 0) ans++;
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) solve();
    return 0;
}