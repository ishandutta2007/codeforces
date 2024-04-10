#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 2005;
const ll oo = 1e18 + 7;
int n, a[maxN][maxN], m;
int z;
int mincheck[2];
int dist[maxN][maxN];
int ans = oo;
 
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, -1, 0, 1};
 
 
void cop(){
    for1(i, 1, n){
        for1(j, 1, m){
            dist[i][j] = -1;
        }
    }
}
 
void show(){
    for1(i, 1, n){
        for1(j, 1, m){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
void dfs(int x, int y, int ind){
    queue<ii> q;
    q.push(ii(x, y));
    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();
        if(a[x][y] == -1) continue;
        if(a[x][y] > 0){
            mincheck[ind] = min(mincheck[ind], a[x][y] + dist[x][y]);
        }
        for1(i, 0, 3){
            if(dist[x + xx[i]][y + yy[i]] == -1){
                dist[x + xx[i]][y + yy[i]] = dist[x][y] + z;
                q.push(ii(x + xx[i], y + yy[i]));
            }
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> z;
    mincheck[0] = oo;
    mincheck[1] = oo;
    for1(i, 1, n){
        for1(j, 1, m){
            cin >> a[i][j];
        }
    }
    cop();
    dist[1][1] = 0;
    dfs(1, 1, 0);
    ans = dist[n][m];
    // show();
    if(ans == -1) ans = oo;
    cop();
    dist[n][m] = 0;
    dfs(n, m, 1);
    if(ans == oo &&(mincheck[0] == oo || mincheck[1] == oo)) cout << "-1\n";
    else cout << min(mincheck[0] + mincheck[1], ans) << endl;
}