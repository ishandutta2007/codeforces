#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int mx,mn,res=0;
    REP(i,nextint()) {
        int t=nextint();
        if (i>0) {
            if (t>mx) {
                res++;
                mx=t;
            }
            if (t<mn) {
                res++;
                mn=t;
            }
        }
        else mx=mn=t;
    }
    printf("%d",res);
    return 0;
}