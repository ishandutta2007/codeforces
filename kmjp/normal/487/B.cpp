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
    static V const def=1000000;
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

int N,S,L;
ll A[100005];
set<pair<ll,int> > SS;
int RR[100005];
int ret[100005];
SegTree_1<int,1<<18> st;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>S>>L;
    
    int fin=0;
    FOR(i,N) {
        RR[i]=N;
        cin>>A[i];
        SS.insert(make_pair(A[i],i));
        while(SS.rbegin()->first - SS.begin()->first>S) {
            if(SS.begin()->second<SS.rbegin()->second) {
                j=SS.begin()->second;
                SS.erase(SS.begin());
            }
            else {
                j=SS.rbegin()->second;
                SS.erase(*SS.rbegin());
            }
            for(;fin<=j;fin++) RR[fin]=i;
        }
    }
    
    MINUS(ret);
    ret[N]=0;
    st.update(N,0);
    
    for(i=N-1;i>=0;i--) {
        ret[i]=1000000;
        l = i+L;
        r = RR[i];
        if(l>r) continue;
        j = st.getval(l,r+1);
        if(j>=0) {
            ret[i]=1+j;
            st.update(i,ret[i]);
        }
    }
    if(ret[0]>=1000000) cout << -1 <<endl;
    else cout<<ret[0]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}