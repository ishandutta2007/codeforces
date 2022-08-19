#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct rmq{
    int tree[270005], lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
        memset(tree,0x3f,sizeof(tree));
    }
    void add(int x, int v){
        x += lim;
        tree[x] = min(tree[x],v);
        while(x > 1){
            x >>= 1;
            tree[x] = min(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        int ret = 1e9;
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) ret = min(ret,tree[s++]);
            if(e%2 == 0) ret = min(ret,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = min(ret,tree[s]);
        return ret;
    }
}rmq, valmin;

struct rmq2{
    int tree[270005], lim;
    void init(int n){
        fill(tree,tree+270005,-2e9);
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = max(tree[x],v);
        while(x > 1){
            x >>= 1;
            tree[x] = max(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        int ret = -2e9;
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) ret = max(ret,tree[s++]);
            if(e%2 == 0) ret = max(ret,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = max(ret,tree[s]);
        return ret;
    }
}valmax;

int low[100005];
int n, l, s, a[100005];
int dp[100005];

int main(){
    scanf("%d %d %d",&n,&s,&l);
    valmin.init(n);
    valmax.init(n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        valmin.add(i,a[i]);
        valmax.add(i,a[i]);
    }
    int e = 1;
    for (int i=1; i<=n; i++) {
        e = max(e,i);
        while (e+1 <= n && 1ll * valmax.q(i,e+1) - 1ll * valmin.q(i,e+1) <= 1ll * s) {
            e++;
        }
        low[i] = e;
    }
    rmq.init(n+1);
    for (int i=n; i; i--) {
        if(low[i] == n) dp[i] = 1e9;
        if(low[i] == n && i + l - 1 <= n) dp[i] = 1;
        else dp[i] = rmq.q(i+l,low[i]+1) + 1;
        rmq.add(i,dp[i]);
    }
    if(dp[1] > 1e8) puts("-1");
    else printf("%d",dp[1]);
}