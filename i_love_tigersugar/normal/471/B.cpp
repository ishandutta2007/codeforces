#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int h[MAX],p[MAX],n;
bool cmp(const int &x,const int &y) {
    return (h[x]<h[y]);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&h[i]);
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
}
void triple(void) {
    FOR(i,1,n-2) if (h[p[i]]==h[p[i+1]] && h[p[i]]==h[p[i+2]]) {
        printf("YES\n");
        FOR(j,1,n) printf("%d ",p[j]); printf("\n");
        swap(p[i],p[i+1]);
        FOR(j,1,n) printf("%d ",p[j]); printf("\n");
        swap(p[i],p[i+2]);
        FOR(j,1,n) printf("%d ",p[j]); printf("\n");
        exit(0);
    }
}
void twoPairs(void) {
    FOR(i,1,n) FOR(j,i+2,n-1) if (h[p[i]]==h[p[i+1]] && h[p[j]]==h[p[j+1]]) {
        printf("YES\n");
        FOR(k,1,n) printf("%d ",p[k]); printf("\n");
        swap(p[i],p[i+1]);
        FOR(k,1,n) printf("%d ",p[k]); printf("\n");
        swap(p[j],p[j+1]);
        FOR(k,1,n) printf("%d ",p[k]); printf("\n");
        exit(0);
    }
}
int main(void) {
    init();
    triple();
    twoPairs();
    printf("NO");
    return 0;
}