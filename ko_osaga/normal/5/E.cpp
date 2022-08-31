#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

pi a[1000005];
int n;

struct rmq{
    int tree[2100000], lim;
    void init(int n, pi *a){
        for(lim = 1; lim <= n; lim<<=1);
        for(int i=1; i<=n; i++){
            tree[i+lim] = a[i].first;
        }
        for(int i=lim; i; i--){
            tree[i] = max(tree[2*i],tree[2*i+1]);
        }
    }
    int q(int s, int e){
        s += lim;
        e += lim;
        int r = 0;
        while(s<e){
            if(s%2 == 1) r = max(r,tree[s++]);
            if(e%2 == 0) r = max(r,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) r = max(r,tree[s]);
        return r;
    }
}rmq;

struct disj{
    int pa[1000005], size[1000005];
    void init(int n){
        for(int i=0; i<=n; i++) pa[i] = i,size[i] = 1;
    }
    int find(int x){
        return pa[x] = (pa[x]==x ? x : find(pa[x]));
    }
    void uni(int p, int q){
        p = find(p);
        q = find(q);
        if(p == q) return;
        pa[p] = q;
        size[q] += size[p];
    }
}disj;

int vis[1000005];

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    rmq.init(n,a);
    disj.init(n);
    sort(a+1,a+n+1);
    long long ret = 0;
    for (int i=1; i<=n; ) {
        int e = i;
        while (a[e].first == a[i].first && e <= n) {
            e++;
        }
        if(e < n){
            ret += (e - i) * 2;
        }
        else if(e == n){
            ret += e - i;
        }
        for (int j=i; j<e-1; j++) {
            if(rmq.q(a[j].second,a[j+1].second) <= a[j].first){
                disj.uni(a[j].second,a[j+1].second);
            }
        }
        if(i + 1 != e){
            if(rmq.q(a[e-1].second,n) <= a[e-1].first && rmq.q(1,a[i].second) <= a[e-1].first){
                disj.uni(a[e-1].second,a[i].second);
            }
        }
        for (int j=i; j<e; j++) {
            int t = disj.find(a[j].second);
            if(vis[t]) continue;
            vis[t] = 1;
            ret += (1ll * disj.size[t] * (disj.size[t]-1)) / 2;
        }
        i = e;
    }
    printf("%I64d",ret);
}