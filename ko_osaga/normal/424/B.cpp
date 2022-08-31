#include <cstdio>
#include <cmath>
#include <algorithm>

struct A{
    int distance;
    int pple;
};
A data[10001];
int cmp(A t, A u){return t.distance < u.distance;}

int main(){
    int n,ppl,i;
    int t,u,v;
    scanf("%d%d",&n,&ppl);
    ppl=1000000-ppl;
    for (int i=0; i<n; i++) {
        scanf("%d %d %d",&t,&u,&v);
        data[i].distance=t*t+u*u;
        data[i].pple=v;
    }
    std::sort(data,data+n,cmp);
    for (i=0; i<n && ppl>0; i++) {
        ppl-=data[i].pple;
    }
    if(i==n && ppl>0) printf("-1");
    else printf("%.7lf",sqrt(data[i-1].distance));
}