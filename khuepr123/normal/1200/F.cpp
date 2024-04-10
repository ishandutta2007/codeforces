#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)

const int mod = 1e9 + 7;
const int maxN = 2520005;
int n, a[maxN];
int x, y, z, k;
int nx[maxN];
int m;
int ed[15];
int rem[10005][15];
int bb[10005];
int dp[maxN];

map<int, int> mp;
bitset<maxN> used;
int root;

int cx = 2520000;

int calc(int node){
    if(dp[node]) return dp[node];
    used[node] = 1;
    mp[node / 2520]++;
    if(dp[nx[node]]) return dp[node] = dp[nx[node]];
    if(used[nx[node]]){
        while(root != nx[node]){
            int wtf = root / 2520;
            mp[wtf]--;
            if(mp[wtf] == 0) mp.erase(wtf);
            root = nx[root];
        }
        return dp[node] = mp.size();
    }
    else return dp[node] = calc(nx[node]);
}

signed main(){
    // freopen("inp.doc", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for1(i, 1, n){
        cin >> a[i]; a[i] %= 2520;
        if(a[i] < 0) a[i] += 2520;
    }
    for1(i, 0, 2519){
        for1(j, 1, 10){
            rem[i][j] = i % j;
        }
    }
    for1(i, 0, 10000){
        bb[i] = (i % 2520);
    }
    for1(i, 1, n){
        cin >> m;
        for1(j, 0, m - 1){
            cin >> ed[j];
        }
        for1(j, 0, 2519){
            int faka = bb[j + a[i]];
            nx[(i - 1) * 2520 + j] =
            (ed[rem[faka][m]] - 1) * 2520 + faka;
        }
    }
    // (n * 2520 node);
    n *= 2520;
    int o; cin >> o;
    int act = 0;
    while(o--){
        // ++act; if(act > 1 && n == cx) return 0;
        cin >> x >> y; y %= 2520;
        if(y < 0) y += 2520;
        // if(n == cx){
            // cout << x << " " << y << endl;
            // continue;
        // }
        root = (x - 1) * 2520 + y;
        mp.clear();
        cout << calc(root) << endl;
    }
}