#include<bits/stdc++.h>
#define MAX   500500
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int pw[NMOD][MAX];
void precount(void) {
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,MAX-1) pw[j][i]=(1LL*pw[j][i-1]<<8)%mod[j];
    }
}
class FenwickTree {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int getSum(int l,int r) const {
        return (l==1?get(r):get(r)-get(l-1));
    }
};
struct Hash {
    int val[NMOD];
    Hash() {
        memset(val,0,sizeof val);
    }
    Hash add(int x,int pos) const {
        Hash res;
        REP(i,NMOD) res.val[i]=(val[i]+1LL*x*pw[i][pos])%mod[i];
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
    Hash multiply(int x) const {
        Hash res;
        REP(i,NMOD) res.val[i]=1LL*val[i]*pw[i][x]%mod[i];
        return (res);
    }
    bool operator == (const Hash &x) const {
        REP(i,NMOD) if (val[i]!=x.val[i]) return (false);
        return (true);
    }
};
struct Query {
    int l,r,val,pos;
    Query() {
        l=r=val=pos=0;
    }
    Query(int _l,int _r,int _val,int _pos) {
        l=_l;r=_r;val=_val;pos=_pos;
    }
    bool operator < (const Query &q) const {
        return (val<q.val);
    }
};
int n,q,totLen;
string str[MAX];
char allStr[MAX];
int fstPos[MAX],strID[MAX];
Hash hashStr[MAX];
int SA[MAX],SApos[MAX];
int rankSA[3][MAX];
pair<int,int> rangeMatch[MAX];
int answer[MAX];
vector<Query> query;
void init(void) {
    cin>>n>>q;
    FOR(i,1,n) cin>>str[i];
}
void prepareSA(void) {
    FOR(i,1,n) {
        fstPos[i]=totLen+1;
        REP(j,str[i].size()+1) strID[fstPos[i]+j]=i;
        REP(j,str[i].size()) allStr[++totLen]=str[i][j];
        allStr[++totLen]='$';
    }
    FOR(i,1,totLen) hashStr[i]=hashStr[i-1].add(allStr[i],i-1);
}
bool equalStr(int a,int b,int len) {
    if (a+len-1>totLen || b+len-1>totLen) return (false);
    Hash hA=hashStr[a+len-1]-hashStr[a-1];
    Hash hB=hashStr[b+len-1]-hashStr[b-1];
    if (a<b) hA=hA.multiply(b-a);
    if (b<a) hB=hB.multiply(a-b);
    return (hA==hB);
}
int samePrefix(int a,int b) {
    if (allStr[a]!=allStr[b]) return (0);
    if (equalStr(a,b,totLen-max(a,b)+1)) return (totLen-max(a,b)+1);
    int L=0;
    int R=totLen-max(a,b)+1;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (equalStr(a,b,R)?R:L);
        int M=(L+R)>>1;
        if (equalStr(a,b,M)) L=M; else R=M-1;
    }
}
int leftMatch(int id) {
    int L=1;
    int R=SApos[fstPos[id]];
    while (true) {
        if (L==R) return (L);
        if (R-L==1) return (equalStr(fstPos[id],SA[L],str[id].size())?L:R);
        int M=(L+R)>>1;
        if (equalStr(fstPos[id],SA[M],str[id].size())) R=M; else L=M+1;
    }
}
int rightMatch(int id) {
    int L=SApos[fstPos[id]];
    int R=totLen;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (equalStr(fstPos[id],SA[R],str[id].size())?R:L);
        int M=(L+R)>>1;
        if (equalStr(fstPos[id],SA[M],str[id].size())) L=M; else R=M-1;
    }
}
bool CompFirstChar(int x,int y) {
    return (allStr[x]<allStr[y]);
}
bool CompSuffix(int x,int y) {
    REP(i,2) if (rankSA[i][x]!=rankSA[i][y]) return (rankSA[i][x]<rankSA[i][y]);
    return (false);
}
void buildSA(void) {
    FOR(i,1,totLen) SA[i]=i;
    sort(SA+1,SA+totLen+1,CompFirstChar);
    FOR(i,1,totLen) rankSA[0][i]=allStr[i];
    for (int j=2;j<=2*totLen;j=j*2) {
        if (j>2) {
            rankSA[2][SA[1]]=0;
            FOR(i,2,totLen) {
                rankSA[2][SA[i]]=rankSA[2][SA[i-1]];
                if (CompSuffix(SA[i-1],SA[i])) rankSA[2][SA[i]]++;
            }
            FOR(i,1,totLen) rankSA[0][i]=rankSA[2][i];
        }
        FOR(i,1,totLen) rankSA[1][i]=i+j/2>totLen?-1:rankSA[0][i+j/2];
        sort(SA+1,SA+totLen+1,CompSuffix);
    }
    FOR(i,1,totLen) SApos[SA[i]]=i;
    FOR(i,1,n) rangeMatch[i]=make_pair(leftMatch(i),rightMatch(i));
}
void prepareQuery(void) {
    FOR(i,1,q) {
        int l,r,id;
        cin>>l>>r>>id;
        int L=rangeMatch[id].fi;
        int R=rangeMatch[id].se;
        query.push_back(Query(L,R,r,i));
        query.push_back(Query(L,R,l-1,-i));
    }
    sort(ALL(query));
}
bool CompPos(int x,int y) {
    return (strID[SA[x]]<strID[SA[y]]);
}
void answerQuery(void) {
    vector<int> pos;
    FOR(i,1,totLen) pos.push_back(i);
    sort(ALL(pos),CompPos);
    FenwickTree bit(totLen);
    int j=0;
    FORE(it,query) {
        while (j<pos.size() && strID[SA[pos[j]]]<=it->val) {
            bit.update(pos[j],1);
            j++;
        }
        int tmp=bit.getSum(it->l,it->r);
        if (it->pos>0) answer[it->pos]+=tmp;
        else answer[-it->pos]-=tmp;
    }
    FOR(i,1,q) printf("%d\n",answer[i]);
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    ios::sync_with_stdio(false);
    precount();
    init();
    prepareSA();
    buildSA();
    prepareQuery();
    answerQuery();
    return 0;
}