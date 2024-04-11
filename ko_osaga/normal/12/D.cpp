#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct rmq{
    int tree[1050000], lim;
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void add(int x, int v){
        x += lim;
        tree[x] = max(tree[x],v);
        while(x){
            x >>= 1;
            tree[x] = max(tree[2*x],tree[2*x+1]);
        }
    }
    int q(int s, int e){
        int r = 0;
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) r = max(r,tree[s++]);
            if(e%2 == 0) r = max(r,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) r = max(r,tree[s]);
        return r;
    }
}rmq;

struct jasal{int p,q,r;}a[500005];
bool cmp(jasal a, jasal b){
    return a.p == b.p ? (a.q < b.q) : (a.p < b.p);
}

int n;
vector<int> px,py,pz;

int main(){
    scanf("%d",&n);
    px.push_back(-1);
    py.push_back(-1);
    pz.push_back(-1);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i].p);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i].q);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i].r);
    }
    for (int i=0; i<n; i++) {
        px.push_back(a[i].p);
        py.push_back(a[i].q);
        pz.push_back(a[i].r);
    }
    sort(px.begin(),px.end());
    sort(py.begin(),py.end());
    sort(pz.begin(),pz.end());
    for (int i=0; i<n; i++) {
        a[i].p = (int)(lower_bound(px.begin(),px.end(),a[i].p)-px.begin());
        a[i].q = (int)(lower_bound(py.begin(),py.end(),a[i].q)-py.begin());
        a[i].r = (int)(lower_bound(pz.begin(),pz.end(),a[i].r)-pz.begin());
    }
    rmq.init(n);
    sort(a,a+n,cmp);
    int cnt = 0;
    for (int i=n-1; i>=0; i--) {
        int e = i;
        while (a[e].p == a[i].p) e--;
        for (int j=i; j>e; j--) {
            if(rmq.q(a[j].q+1,n) > a[j].r) cnt++;
        }
        for (int j=i; j>e; j--) {
            rmq.add(a[j].q,a[j].r);
        }
        i = e+1;
    }
    printf("%d",cnt);
}