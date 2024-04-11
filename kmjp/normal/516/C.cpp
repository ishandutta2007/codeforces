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

int N,M;
ll D[202000],H[202000];
ll DS[201000];

template<class V,int NV> class SegTree_Pair {
public:
    vector<pair<V,int> > val;
    static V const def=0;
    pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
    SegTree_Pair(){
        val.resize(NV*2);
        int i;
        FOR(i,NV) val[i]=make_pair(def,NV+i);
        for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
    };
    pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
        if(r<=x || y<=l) return make_pair(def,NV);
        if(x<=l && r<=y) return val[k];
        return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
    }
    void update(int entry, V v) {
        entry += NV;
        val[entry]=make_pair(v,entry);
        while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
    }
};

int A[101000],B[101000];
int AD=1<<22;
SegTree_Pair<ll,1<<22> LT,RT;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,N) cin>>D[i], D[i+N]=D[i];
    FOR(i,N) cin>>H[i], H[i+N]=H[i];
    D[2*N-1]=0;
    FOR(i,200100) DS[i+1]=DS[i]+D[i];
    FOR(i,200100) LT.update(i,DS[200100]-DS[i]+2*H[i]);
    FOR(i,200100) RT.update(i,DS[i]+2*H[i]);
    
    FOR(i,M) {
        cin>>x>>y;
        x--,y--;
        if(x<=y) A[i]=y+1, B[i]=N+x-1;
        else A[i]=y+1,B[i]=x-1;
        
        pair<ll,int> lc,rc,a1,a2;
        lc=LT.getval(A[i],B[i]+1);
        rc=RT.getval(A[i],B[i]+1);
        
        ll ret;
        if(lc.second!=rc.second) {
            ret = lc.first+rc.first-DS[200100];
        }
        else {
            ll ret1,ret2;
            a1=RT.getval(A[i],lc.second-AD);
            a2=RT.getval(lc.second-AD+1,B[i]+1);
            
            ret1 = lc.first + max(a1.first,a2.first);
            
            a1=LT.getval(A[i],lc.second-AD);
            a2=LT.getval(lc.second-AD+1,B[i]+1);
            ret2 = rc.first + max(a1.first,a2.first);
            
            ret=max(ret1,ret2)-DS[200100];
        }
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