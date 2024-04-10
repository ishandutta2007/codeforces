#include<cstdio>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int s[MAX],d[MAX],n,k;
int ceil(int x,int y) {
    return (x/y+(x%y>0));
}
void process(void) {
    int res=0;
    int tmp=0;
    int rem=0;
    n=nextint();
    k=nextint();
    FOR(i,1,n) d[i]=nextint();
    FOR(i,1,n) {
        s[i]=nextint();
        if (tmp<s[i]) tmp=s[i];
        rem+=s[i];
        res+=d[i];
        if (rem<d[i]) {
            res+=ceil(d[i]-rem,tmp)*k;
            rem+=ceil(d[i]-rem,tmp)*tmp;
        }
        rem-=d[i];
    }
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}