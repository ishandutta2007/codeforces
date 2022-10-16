#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod=(int)1e9+7;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int cnt[MAX];
void process(void) {
    int n;
    scanf("%d",&n);
    REP(love,n) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    bool haveOdd=false;
    REP(i,MAX) if (cnt[i]%2!=0) haveOdd=true;
    if (haveOdd) {
        bool firstOdd=true;
        int mul=1;
        REP(i,MAX) if (cnt[i]>0) {
            if (firstOdd && cnt[i]%2!=0) {
                mul=1LL*mul*((cnt[i]+1)/2)%(mod-1);
                firstOdd=false;
            } else mul=1LL*mul*(cnt[i]+1)%(mod-1);
        }
        int res=1;
        REP(i,MAX) if (cnt[i]>0) res=1LL*res*pw(i,1LL*mul*cnt[i]%(mod-1))%mod;
        printf("%d\n",res);
    } else {
        int mul=1;
        REP(i,MAX) if (cnt[i]>0) mul=1LL*mul*(cnt[i]+1)%(mod-1);
        int res=1;
        REP(i,MAX) if (cnt[i]>0) res=1LL*res*pw(i,1LL*cnt[i]/2*mul%(mod-1))%mod;
        printf("%d\n",res);
    }
}
int main(void) {
    process();
    return 0;
}