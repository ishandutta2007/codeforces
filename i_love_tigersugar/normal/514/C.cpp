#include<bits/stdc++.h>
#define MAX   600600
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int pw[NMOD][MAX];
void precount(void) {
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,MAX-1) pw[j][i]=(1LL*pw[j][i-1]<<8)%mod[j];
    }
}
struct Hash {
    int val[NMOD];
    Hash() {
        memset(val,0,sizeof val);
    }
    Hash(int c,int pos) {
        REP(i,NMOD) val[i]=1LL*c*pw[i][pos]%mod[i];
    }
    Hash operator + (const Hash &x) const {
        Hash res;
        REP(i,NMOD) {
            res.val[i]=val[i]+x.val[i];
            if (res.val[i]>=mod[i]) res.val[i]-=mod[i];
        }
        return (res);
    }
    Hash operator - (const Hash &x) const {
        Hash res;
        REP(i,NMOD) {
            res.val[i]=val[i]-x.val[i];
            if (res.val[i]<0) res.val[i]+=mod[i];
        }
        return (res);
    }
    bool operator < (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (val[i]<x.val[i]);
        return (false);
    }
};
set<Hash> allHash[MAX];
Hash getHash(const string &s) {
    Hash res;
    REP(i,s.size()) res=res+Hash(s[i],i);
    return (res);
}
void getChange(const string &s) {
    Hash str=getHash(s);
    REP(i,s.size()) FOR(j,'a','c') if (j!=s[i]) allHash[s.size()].insert(str-Hash(s[i],i)+Hash(j,i));
}
void process(void) {
    int n,q;
    cin>>n>>q;
    REP(love,n) {
        string s;
        cin>>s;
        getChange(s);
    }
    REP(love,q) {
        string s;
        cin>>s;
        printf("%s\n",allHash[s.size()].find(getHash(s))==allHash[s.size()].end()?"NO":"YES");
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    ios::sync_with_stdio(false);cin.tie(NULL);
    precount();
    process();
    return 0;
}