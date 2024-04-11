#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
    vector<V> val;
    static V const def=0;
    V comp(V l,V r){ return max(l,r);};
    
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

SegTree_1<ll,1<<19> st;

int N;
ll P[202000],L[202000];
ll R[202000];
ll RN[20][202000],CN[20][202000];
ll mic[202000];
int Q;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>P[i]>>L[i];
    
    P[N]=1LL<<40;
    RN[0][N]=N;
    st.update(N+1,N);
    FOR(i,N+1) mic[i]=1LL<<40;
    for(i=N-1;i>=0;i--) {
        R[i]=lower_bound(P,P+N+1,P[i]+L[i]+1)-P;
        RN[0][i]=max(R[i],st.getval(0,R[i]+1));
        
        CN[0][i]=min(P[RN[0][i]]-P[i]-L[i],mic[RN[0][i]]);
        mic[RN[0][i]]=min(mic[RN[0][i]],CN[0][i]);
        st.update(i+1,RN[0][i]);
    }
    FOR(x,18) FOR(i,N+1) RN[x+1][i]=RN[x][RN[x][i]], CN[x+1][i]=CN[x][i]+CN[x][RN[x][i]];

    cin>>Q;
    while(Q--) {
        cin>>l>>r;
        l--,r--;
        ll ret=0;
        for(i=18;i>=0;i--) if(RN[i][l]<=r) ret+=CN[i][l], l=RN[i][l];
        while(RN[0][l]<=r) ret+=CN[0][l], l=RN[i][l];
        cout<<ret<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}