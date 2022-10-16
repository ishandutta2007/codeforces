#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int res=0;
    REP(zz,nextint()) {
        int p=nextint();
        int q=nextint();
        if (p+2<=q) res++;
    }
    printf("%d",res);
    return 0;
}