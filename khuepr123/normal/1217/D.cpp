/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;
int ans[maxN];
vector<int> vc[maxN];
int cnt[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    for1(i, 1, m){
        cin >> x >> y;
        ans[i] = 2;
        if(x > y) ans[i] = 1;
        vc[x].pb(y);
        cnt[y]++;
    }
    queue<int> q;
    int vol = 0;;
    for1(i, 1, n){
        if(cnt[i] == 0) q.push(i);
    }
    while(!q.empty()){
        x = q.front(); q.pop(); ++vol;
        for(int cc : vc[x]){
            cnt[cc]--;
            if(cnt[cc] == 0) q.push(cc);
        }
    }
    if(vol == n){
        cout << 1 << endl;
        for1(i, 1, m) cout << "1 ";
    }
    else{
        cout << 2 << endl;
        for1(i, 1, m) cout << ans[i] << " ";
    }
}