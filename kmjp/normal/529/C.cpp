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

int H,W,K,Q;
int X[202000],Y[202000];
int X1[202000],Y1[202000];
int X2[202000],Y2[202000];
int ok[202000];
vector<int> evR[210000],evQ[210000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>W>>H>>K>>Q;
    FOR(i,K) cin>>X[i]>>Y[i];
    FOR(i,Q) cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
    
    FOR(k,2) {
        SegTree_1<int,1<<20> miny;
        FOR(i,210000) evR[i].clear(),evQ[i].clear();
        FOR(i,K) evR[Y[i]].push_back(i);
        FOR(i,Q) evQ[Y2[i]].push_back(i);
        for(i=1;i<=W;i++) miny.update(i,0);
        for(i=1;i<=H;i++) {
            FORR(r,evR[i]) miny.update(X[r],i);
            FORR(r,evQ[i]) ok[r] |= miny.getval(X1[r],X2[r]+1)>=Y1[r];
        }
        
        swap(W,H);
        FOR(i,K) swap(X[i],Y[i]);
        FOR(i,Q) swap(X1[i],Y1[i]);
        FOR(i,Q) swap(X2[i],Y2[i]);
    }
    FOR(i,Q) cout << (ok[i]?"YES":"NO") << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}