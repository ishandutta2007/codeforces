#include<bits/stdc++.h>
#define MAX   5050
using namespace std;
struct enve {
    int w,h,id;
    enve(){}
    void input(const int &i) {
        id=i;
        scanf("%d",&w);
        scanf("%d",&h);
    }
    bool operator < (const enve &x) const {
        if (w>x.w) return (true);
        if (w<x.w) return (false);
        return (h<x.h);
    }
};
int n,sz,e;
enve a[MAX];
int f[MAX];
int c[MAX];
int t[MAX];
int r[MAX];
void init(void) {
    scanf("%d",&n);
    int i;
    for (i=1;i<=n+1;i=i+1) a[i].input(i);
    sort(&a[1],&a[n+2]);
}
void LDS(void) {
    int i,l,m,r;
    bool cont=true;
    sz=1;
    c[sz]=1;
    f[1]=sz;
    if (a[1].id==1) {
        e=1;
        return;
    }
    for (i=2;cont;i=i+1) {
        if (a[i].id==1) {
            cont=false;
            e=i;
        }
        if (a[i].h>=a[c[1]].h) {
            f[i]=1;
            c[1]=i;
            continue;
        }
        if (a[i].h<a[c[sz]].h) {
            t[i]=c[sz];
            sz++;
            f[i]=sz;
            c[sz]=i;
            continue;
        }
        l=1;
        r=sz;
        while (true) {
            if (l==r) {
                m=r;
                break;
            }
            if (r-l==1) {
                if (a[i].h<a[c[r]].h) m=r;
                else m=l;
                break;
            }
            m=(l+r)/2;
            if (a[i].h<a[c[m]].h) l=m;
            else r=m-1;
        }
        f[i]=m+1;
        t[i]=c[m];
        if (a[c[m+1]].h<a[i].h) c[m+1]=i;
    }
}
void trace(void) {
    int i,j;
    printf("%d",f[e]-1);
    if (f[e]==1) return;
    printf("\n");
    j=0;
    i=t[e];
    while (true) {
        j++;
        r[j]=i;
        if (f[i]==1) break;
        i=t[i];
    }
    for (j=1;j<f[e];j=j+1) {
        if (j>1) printf(" ");
        printf("%d",a[r[j]].id-1);      
    }
}
int main(void) {
    init();
    LDS();
    trace();
    return 0;
}