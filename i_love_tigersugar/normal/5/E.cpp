#include<bits/stdc++.h>
#define MAX   1000100
const int INF=(int)2e9;
int l[MAX];
int r[MAX];
int c[MAX];
int a[MAX];
int h[MAX];
int n;
long long res;
void init(void) {
    int i,j,im;
    scanf("%d",&n);
    im=0;
    for (i=0;i<n;i=i+1) {
        scanf("%d",&a[i]);
        if (a[i]>a[im]) im=i;
    }
    i=im;
    j=1;
    while (j<=n) {
        h[j]=a[i];
        i=(i+1)%n;
        j=j+1;
    }
    h[0]=INF;
    h[n+1]=INF;
}
void count(void) {
    res=0LL;
    int i;
    for (i=n;i>=1;i=i-1) {
        r[i]=i+1;
        while (h[r[i]]<h[i]) r[i]=r[r[i]];
        if (h[r[i]]==h[i]) {
            c[i]=c[r[i]]+1;
            r[i]=r[r[i]];
        }
    }
    for (i=1;i<=n;i=i+1) {
        l[i]=i-1;
        while (h[l[i]]<=h[i]) l[i]=l[l[i]];
    }
    for (i=1;i<=n;i=i+1) {
        res+=c[i];
        if (l[i]>0) {
            if (l[i]==1 && r[i]>n) res++;
            else res+=2;
        }
    }
    printf("%I64d",res);
}
int main(void) {
    init();
    count();
    return 0;
}