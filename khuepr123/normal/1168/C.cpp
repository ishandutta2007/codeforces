/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

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
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int cls[maxN][19];
int nx[19];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n){
        cin >> a[i];
    }
    a[n + 1] = 524287;
    for1(j, 0, 18){
        nx[j] = n + 1;
        cls[n + 1][j] = n + 1;
    }
    for2(i, n, 1){
        for1(j, 0, 18) cls[i][j] = n + 1;
        for1(j, 0, 18){
            if(a[i] & (1 << j)){
                for1(g, 0, 18){
                    cls[i][g] = min(cls[i][g], cls[nx[j]][g]);
                }
                nx[j] = i;
                cls[i][j] = i;
            }
        }
    }
    while(o--){
        cin >> x >> y;
        bool win = 0;
        for1(j, 0, 18){
            if(a[y] & (1 << j)){
                if(cls[x][j] <= y) win = 1;
            }
        }
        if(win) cout << "Shi";
        else cout << "Fou";
        cout << endl;
    }
}