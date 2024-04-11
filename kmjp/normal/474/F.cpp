#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
    vector<V> val;
    static V const def=-1;
    V comp(V l,V r){ 
        if(l==def) return r;
        if(r==def) return l;
        return __gcd(l,r);
    };
    
    SegTree_1(){val=vector<V>(NV*2,def);};
    V getval(int x,int y,int l=0,int r=NV,int k=1) {
        if(r<=x || y<=l) return def;
        if(x<=l && r<=y) return val[k];
        return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
    }
    void update(int entry, V v) {
        entry += NV;
        val[entry]=v;
        while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
    }
};

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> bt;

int N,T;
ll S[100500],L[100500],R[100500];
int LP[100500],RP[100500];
SegTree_1<ll,1<<18> st;
int res[100001];
vector<int> del[100001];
vector<int> QQ[100001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>S[i], st.update(i+1,S[i]);
    FOR(i,N) {
        LP[i]=RP[i]=i+1;
        for(j=18;j>=0;j--) {
            x=LP[i]-(1<<j);
            if(x>0 && st.getval(x,i+1)%S[i]==0) LP[i]=x;
            x=RP[i]+(1<<j);
            if(x<=N && st.getval(i+1,x+1)%S[i]==0) RP[i]=x;
        }
        LP[i]--;
        RP[i]--;
    }
    cin>>T;
    FOR(i,T) {
        cin>>L[i]>>R[i];
        L[i]--,R[i]--;
        QQ[R[i]].push_back(i);
    }
    
    FOR(i,N) {
        bt.update(LP[i],1);
        del[RP[i]].push_back(i);
        FOR(j,QQ[i].size()) res[QQ[i][j]]=bt.total(i+1)-bt.total(L[QQ[i][j]]);
        ITR(it,del[i]) bt.update(LP[*it],-1), bt.update(*it+1,1);
    }
    
    FOR(i,T) _P("%d\n",res[i]);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}