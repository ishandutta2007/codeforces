#include<algorithm>
#include<cstdio>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int c[]={1,1,2,7,4};
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int x=10000;
    REP(i,5) x=min(x,nextInt()/c[i]);
    printf("%d",x);
    return 0;
}