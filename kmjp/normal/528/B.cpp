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

int N;
ll L[202000],R[202000];
int ma;
vector<pair<ll,int> > E;
map<ll,int> XX;
vector<ll> V;
int mama[505000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>x>>y;
        L[i]=x-y;
        R[i]=x+y;
        XX[L[i]]=XX[R[i]]=0;
    }
    XX[-1LL<<40]=XX[1LL<<40]=0;
    ITR(it,XX) it->second=V.size(), V.push_back(it->first);
    FOR(i,N) {
        L[i]=XX[L[i]];
        R[i]=XX[R[i]];
        E.emplace_back(L[i],i);
    }
    sort(E.begin(),E.end());
    
    SegTree_1<int,1<<20> st;
    
    FORR(e,E) {
        i=e.second;
        x=st.getval(0,L[i]+1)+1;
        ma=max(ma,x);
        mama[R[i]]=max(mama[R[i]],x);
        st.update(R[i],mama[R[i]]);
    }
    cout<<ma<<endl;
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}