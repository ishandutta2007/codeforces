#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int ceil(int a,int b) {
    return (a/b+(a%b>0));
}
int main(void) {
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int res=n*a;
    REP(i,n+1) {
        int tmp=i*a+ceil(n-i,m)*b;
        if (tmp<res) res=tmp;
    }
    printf("%d",res);
    return 0;
}