#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
    vector<V> val;
    static V const def=1<<20;
    V comp(V l,V r){ return min(l,r);};
    
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

int N,M;
int D[505000];
int L[505000],R[505000],nex[505000],ret[505000];
pair<int,int> P[505000];
SegTree_1<int,1<<19> st;

map<ll,int> V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,N) {
        cin>>x;
        D[i]=1<<20;
        nex[i]=-1;
        if(V.count(x)) D[i]=i-V[x], nex[V[x]]=i;
        st.update(i+1,D[i]);
        V[x]=i;
    }
    FOR(i,M) cin>>L[i]>>R[i], P[i]=make_pair(L[i],i);
    x=0;
    sort(P,P+M);
    FOR(i,M) {
        while(x<P[i].first-1) {
            if(nex[x]!=-1) D[nex[x]]=1<<20, st.update(nex[x]+1,D[nex[x]]);
            x++;
        }
        ret[P[i].second]=st.getval(L[P[i].second],R[P[i].second]+1);
    }
    FOR(i,M) _P("%d\n",(ret[i]>=1<<20)?-1:ret[i]);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}