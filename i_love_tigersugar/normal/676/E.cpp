#include<bits/stdc++.h>
#define MAX   100100
#define NMOD   4
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
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod[]={(int)1e9+22772222,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
const int INF=(int)1e9+7;
const string yes="Yes";
const string no="No";
struct Hash {
    int val[NMOD];
    Hash(int x=0) {
        REP(i,NMOD) val[i]=(x%mod[i]+mod[i])%mod[i];
    }
    Hash operator + (const Hash &x) const {
        Hash res;
        REP(i,NMOD) res.val[i]=(val[i]+x.val[i])%mod[i];
        return (res);
    }
    Hash operator * (const Hash &x) const {
        Hash res;
        REP(i,NMOD) res.val[i]=1LL*val[i]*x.val[i]%mod[i];
        return (res);
    }
    bool operator == (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (false);
        return (true);
    }
};
int n,m,a[MAX];
int numFromStr(string s) {
    int sign=s[0]=='-'?-1:1;
    if (s[0]=='-') s.erase(0,1);
    int res=0;
    FORE(it,s) res=res*10+*it-'0';
    return (sign*res);
}
int getNumber(void) {
    string s; cin>>s;
    return (s=="?"?INF:numFromStr(s));
}
void init(void) {
    cin>>n>>m;
    REP(i,n+1) a[i]=getNumber();
}
bool process(void) {
    if (m==0) {
        if (a[0]!=INF) return (a[0]==0);
        bool nextMove=false;
        REP(i,n+1) if (a[i]!=INF) nextMove^=1;
        return (nextMove);
    }
    bool allDone=true;
    REP(i,n+1) if (a[i]==INF) allDone=false;
    if (!allDone) return (n%2);
    Hash res=0;
    FORD(i,n+1,0) res=res*m+a[i];
    return (res==0);
}
int main(void) {
    init();
    cout<<(process()?yes:no)<<endl;
    return 0;
}