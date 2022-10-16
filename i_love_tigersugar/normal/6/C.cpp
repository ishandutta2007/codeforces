#include<bits/stdc++.h>
#define MAX   100100
int t[MAX];
int s[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    int i;
    s[0]=0;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&t[i]);
        s[i]=s[i-1]+t[i];
    }
}
void process(void) {
    if (n==1) {
        printf("1 0");
        return;
    }
    int l,m,r;
    int sa,sb;
    l=1;r=n-1;
    while (true) {
        if (l==r) {
            printf("%d %d",r,n-r);
            return;
        }
        if (r-l==1) {
            sa=s[r-1];
            sb=s[n]-s[r];
            if (sa<=sb) printf("%d %d",r,n-r);
            else printf("%d %d",l,n-l);
            return;
        }
        m=(l+r)/2;
        sa=s[m-1];
        sb=s[n]-s[m];
        if (sa<=sb) l=m;
        else r=m;
    }
}
int main(void) {
    init();
    process();
    return 0;
}