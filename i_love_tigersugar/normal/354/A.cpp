#include<bits/stdc++.h>
#define MAX   100100
typedef long long ll;
int n,l,r,ql,qr;
int w[MAX];
int s[MAX];
ll best;
void init(void) {
    scanf("%d",&n); 
    scanf("%d",&l);
    scanf("%d",&r);
    scanf("%d",&ql);
    scanf("%d",&qr);
    int i;
    s[0]=0;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&w[i]);
        s[i]=s[i-1]+w[i];
    }
    best=(ll)1e13;
}
ll penalty(const int &nl,const int &nr) {
    if (nl==nr) return (0LL);
    if (nr>nl) return (1LL*qr*(nr-nl-1));
    if (nl>nr) return (1LL*ql*(nl-nr-1));
}
ll choose(const int &i) {
    ll ret=0LL;
    ret+=1LL*s[i]*l;
    ret+=1LL*(s[n]-s[i])*r;
    ret+=penalty(i,n-i);
    return (ret);
}
void process(void) {
    int i;
    ll t;
    for (i=0;i<=n;i=i+1) {
        t=choose(i);
        if (t<best) best=t;
    }
    printf("%I64d",best);
}
int main(void) {
    init();
    process();
    return 0;
}