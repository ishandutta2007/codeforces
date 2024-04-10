// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
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
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 2e5 + 10;
int n , m , fa[N] , cir[N] , u[N] , v[N] , w[N] , id[N];
int F(int x){return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n+1) fa[i] = i , cir[i] = false;
    rep(i,0,m) scanf("%d%d%d",u+i,v+i,w+i),id[i]=i;
    sort(id,id+m,[&](int a,int b){return w[a]>w[b];});
    int ans=0;
    rep(c,0,m){
        int i=id[c];
        int u=F(::u[i]);
        int v=F(::v[i]);
        int w=::w[i];
        if(u==v){
            if(cir[u]==0) cir[u]=1,ans+=w;
        } else {
            if(cir[u]&&cir[v]) continue;
            fa[v] = u;
            cir[u] |= cir[v];
            ans+=w;
        }
    }
    printf("%d\n",ans);
    return 0;
}