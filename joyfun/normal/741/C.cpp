#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010 << 1;
int a[N] , b[N] , n , vis[N] , col[N];
vi g[N];

void link(int a,int b){
    g[a].pb(b);
    g[b].pb(a);
}

int main(){
    scanf("%d",&n);
    rep(i,0,n) link(i<<1 , i<<1|1);
    rep(i,0,n){
        scanf("%d%d",a + i,b + i);
        a[i]-- , b[i]--;
        link(a[i] , b[i]);
    }
    rep(i,0,n+n) if(!vis[i]){
        vi v;
        int c = i;
        while(!vis[c]) {
            v.pb(c);
            vis[c] = true;
            int u = 0;
            for(auto e : g[c]) if(!vis[e]){
                u = e;
                break;
            }
            c = u;
        }
        rep(i,0,sz(v)) col[v[i]] = i&1;
    }
    rep(i,0,n) printf("%d %d\n",col[a[i]] + 1 , col[b[i]] + 1);
    return 0;
}