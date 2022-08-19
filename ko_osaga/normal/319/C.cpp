#include <cstdio>
typedef long long lint;

lint a[100005],b[100005],d[100005];
lint la[100005], lb[100005];

int sz,p,n;
double cross(int x, int y){return (double)(lb[y] - lb[x]) / (la[x] - la[y]);}

void insert(lint p, lint q){
    la[sz] = p;
    lb[sz] = q;
    //  
    while(sz>1 && cross(sz-1,sz-2) > cross(sz-1,sz)){
        //  - (sz-1)  (sz-1) - (sz-2)   
        // sz-1   
        la[sz-1] = la[sz];
        lb[sz-1] = lb[sz];
        sz--;
    }
    sz++;
}

lint query(lint x){
    while (p+1 < sz && cross(p,p+1) <= x) p++;
    //  x     pop_front
    return lb[p] + la[p] * x;
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%I64d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%I64d",&b[i]);
    }
    insert(b[0],0);
    for (int i=1; i<n; i++) {
        d[i] = query(a[i]);
        insert(b[i],d[i]);
    }
    printf("%I64d",d[n-1]);
}