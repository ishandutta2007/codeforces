#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, num;
int par[maxN];
int find(int i){ return (par[i] = (i - par[i]) ? find(par[i]) : i);}
void unite(int i, int j){ par[find(i)] = find(j);}
bool sameset(int i, int j){ return (find(i) == find(j));}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> num;
        if(!sameset(i, num)) unite(i, num);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(par[i] == i) ans++;
        // cout << par[i] << " ";
    }
    cout << ans;
}