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
ll dist[105][105];
int p[1050000];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string S;
        cin >> S;
        S = "#" + S;
        for(int j = 1; j <= n; j++) {
            if(S[j] == '1') dist[i][j] = 1;
            else dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                chmin(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    int now = 1;
    int ans = 1;
    vector<int> v;
    v.push_back(p[1]);
    for(int i = 2; i <= m; i++) {
        if(dist[p[now]][p[i]] != i - now) {
            now = i - 1;
            //cerr << now << endl;
            v.push_back(p[now]);
            ans++;
        }
    }
    v.push_back(p[m]);
    ans++;
    cout << ans << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}