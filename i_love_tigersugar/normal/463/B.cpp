#include<algorithm>
#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int res=0;
    REP(zz,nextint()) res=max(res,nextint());
    printf("%d",res);
}