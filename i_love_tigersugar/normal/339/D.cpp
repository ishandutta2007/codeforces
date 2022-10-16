#include<bits/stdc++.h>
#define MAX   20
int t[1<<MAX];
int a[1<<MAX];
int m,n;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    int i;
    for (i=1;i<=(1<<n);i=i+1) scanf("%d",&a[i]);    
}
void update(int i,int h,int l,int r,int u,int val) {
    //printf("Updating %d %d %d %d %d\n",i,h,l,r,u);
    if (l>u) return;
    if (r<u) return;
    if (l>r) return;
    if (l==r) {
        t[i]=val;
        return; 
    }
    int m=(l+r)/2;
    update(2*i,h+1,l,m,u,val);
    update(2*i+1,h+1,m+1,r,u,val);
    if ((n-h)%2==0) t[i]=t[2*i]^t[2*i+1];
    else t[i]=t[2*i]|t[2*i+1];
}
void process(void) {
    int i,p,b;
    for (i=1;i<=(1<<n);i=i+1) update(1,0,1,1<<n,i,a[i]);
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&p);
        scanf("%d",&b);
        update(1,0,1,1<<n,p,b);
        printf("%d\n",t[1]);
    }   
}
int main(void) {
    init();
    process();
    return 0;
}