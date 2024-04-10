#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int n=nextint();
    int s=nextint();
    int res=-1;
    REP(zz,n) {
        int x=nextint();
        int y=nextint();
        if (x<=s && (y==0 || x<s) && (y?100-y:0)>res) res=y?100-y:0;
    }
    printf("%d",res);
    return 0;
}