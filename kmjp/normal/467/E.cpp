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
    static V const def=10000000;
    V comp(V l,V r){ return min(l,r);};
    
    SegTree_1(){val.resize(NV*2); clear();};
    void clear() { int i; FOR(i,NV*2) val[i]=def;}
    
    V getval(int x,int y,int l,int r,int k) {
        if(r<=x || y<=l) return def;
        if(x<=l && r<=y) return val[k];
        return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
    }
    V getval(int x,int y) { return getval(x,y,0,NV,1);}
    void update(int entry, V v) {
        entry += NV;
        val[entry]=v;
        while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
    }
};

int N;
int A[600000],p[600000],n[600000];
map<int,int> M;
vector<int> R;
SegTree_1<int,1<<20> st;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    FOR(i,N) p[i]=M.count(A[i])?M[A[i]]:-1, M[A[i]]=i;
    M.clear();
    for(i=N-1;i>=0;i--) {
        n[i]=M.count(A[i])?M[A[i]]:N;
        M[A[i]]=i;
        st.update(i,n[i]);
    }
    int pre=-1;
    while(pre<N) {
        int mi=N;
        int V[4];
        for(i=pre+1;i<N;i++) {
            if(i>mi) break;
            if(p[i]<=pre) continue;
            if(p[p[i]]>pre && n[i]<mi){ //same
                V[0]=p[p[i]];
                V[1]=p[i];
                V[2]=i;
                mi=V[3]=n[i];
            }
            if(p[i]+2<=i) {
                while((j=st.getval(p[i]+1,i))<=i) {
                    st.update(p[j],10000000); //disable;
                }
                if((j=st.getval(p[i]+1,i))<mi){
                    V[0]=p[i];
                    V[1]=p[j];
                    V[2]=i;
                    mi=V[3]=j;
                }
            }
        }
        if(mi<N) R.insert(R.end(),V,V+4);
        pre=mi;
        if(i>=N) break;
        
    }
    
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%d ",A[R[i]]);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}