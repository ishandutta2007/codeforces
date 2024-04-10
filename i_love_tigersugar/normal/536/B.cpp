#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
char s[MAX];
int z[MAX];
int m,n,len;
int a[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    len=strlen(s);
    FOR(i,1,m) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
}
void ZAlgorithm(void) {
    int L=0;
    int R=0;
    FOR(i,1,len-1) {
        if (i>R) {
            L=R=i;
            while (R<len && s[R-L]==s[R]) R++;
            z[i]=R-L;
            R--;
        }
        else {
            int k=i-L;
            if (z[k]<R-i+1) z[i]=z[k];
            else {
                L=i;
                while (R<len && s[R-L]==s[R]) R++;
                z[i]=R-L;
                R--;
            }
        }
    }
    z[0]=len;
}
bool preSuf(int i) {
    return (z[len-i]>=i);
}
void process(void) {
    FOR(i,2,m) {
        int cur=a[i];
        int prev=a[i-1];
        if (prev+len-1<cur) continue;
        if (!preSuf(len-cur+prev)) {
            printf("0\n");
            return;
        }
    }
    int res=1;
    FOR(i,1,n) {
        int id=upper_bound(a+1,a+m+1,i)-a-1;
        if (id<1 || a[id]+len-1<i) res=26LL*res%mod;
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    ZAlgorithm();
    process();
    return 0;
}