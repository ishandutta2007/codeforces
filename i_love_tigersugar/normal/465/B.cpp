#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int res=0;
    int cnt=0;
    bool fst=true;
    REP(zz,nextint()) {
        int t=nextint()^1;
        if (t==0) cnt++;
        else {
            if (cnt>0) {
                res+=cnt;
                if (!fst) res++;
                fst=false;
            }
            cnt=0;
        }
    }
    if (cnt>0) {
        res+=cnt;
        if (!fst) res++;
    }
    printf("%d",res);
    return 0;
}