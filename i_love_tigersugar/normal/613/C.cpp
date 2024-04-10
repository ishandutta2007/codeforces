#include<bits/stdc++.h>
#define MAX   100100
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
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
int a[MAX],n,cnt[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void noCase(void) {
    printf("0\n");
    FOR(i,1,n) REP(love,a[i]) printf("%c",'a'+i-1); printf("\n");
}
void oddCase(void) {
    int gcdAll=a[1];
    FOR(i,1,n) gcdAll=gcd(gcdAll,a[i]);
    int oddID=0;
    FOR(i,1,n) if (a[i]%2!=0) oddID=i;
    printf("%d\n",gcdAll);
    REP(love,gcdAll) {
        printf("%c",'a'+oddID-1);
        FOR(i,1,n) if (i!=oddID) REP(love,a[i]/gcdAll/2) printf("%c",'a'+i-1);
        REP(love,a[oddID]/gcdAll-1) printf("%c",'a'+oddID-1);
        FORD(i,n,1) if (i!=oddID) REP(love,a[i]/gcdAll/2) printf("%c",'a'+i-1);
    }
    printf("\n");
}
bool ok(int x,int sum) {
    bool haveOdd=false;
    FOR(i,1,n) {
        if (a[i]%(sum/x)!=0) return (false);
        if (a[i]/(sum/x)%2!=0) {
            if (haveOdd) return (false);
            haveOdd=true;
        }
    }
    return (true);
}
void evenCase(void) {
    int gcdAll=a[1];
    FOR(i,1,n) gcdAll=gcd(gcdAll,a[i]);
    int sum=0;
    FOR(i,1,n) sum+=a[i];
    REP(i,sum) {
        int t=gcd(2*i,sum);
        for (int j=1;1LL*j*j<=t;j=j+1) if (t%j==0) {
            cnt[j]++;
            if (1LL*j*j!=t) cnt[t/j]++;
        }
    }
    int best=-1;
    FOR(i,1,sum) if (sum%i==0 && ok(i,sum))
        if (best<0 || cnt[i]>cnt[best]) best=i;
    string res;
    FOR(i,1,n) REP(love,a[i]/(sum/best)/2) res.push_back('a'+i-1);
    string tmp=res;
    FOR(i,1,n) if (a[i]/(sum/best)%2!=0) res.push_back('a'+i-1);
    reverse(ALL(tmp));
    res+=tmp;
    cout<<cnt[best]<<"\n";
    REP(love,sum/best) cout<<res;
    cout<<"\n";
}
void process(void) {
    int cntOdd=0;
    FOR(i,1,n) if (a[i]%2!=0) cntOdd++;
    if (cntOdd>1) noCase();
    else if (cntOdd>0) oddCase();
    else evenCase();
}
int main(void) {
    init();
    process();
    return 0;
}