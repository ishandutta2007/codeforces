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

template<class V,int NV> class SegTree_2 {
public:
    vector<V> val,ma,from;
    SegTree_2(){val.resize(NV*2,0); ma.resize(NV*2,0);from.resize(NV*2,-1); };
    void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
        if(l>=r) return;
        if(x<=l && r<=y) {
            val[k]+=v;
            ma[k]+=v;
            if(from[k]==-1) from[k]=r-1;
        }
        else if(l < y && x < r) {
            update(x,y,v,l,(l+r)/2,k*2);
            update(x,y,v,(l+r)/2,r,k*2+1);
            if(ma[k*2]>ma[k*2+1]) ma[k]=ma[k*2], from[k]=from[k*2];
            else  ma[k]=ma[k*2+1], from[k]=from[k*2+1];
            ma[k]+=val[k];
        }
        
    }
};

int N;
int L[101000],R[101000],V[101000];
vector<int> Vev[303000],Rev[303000];
SegTree_2<int,1<<20> st;
int ma=-1,LL,RR;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>L[i]>>V[i]>>R[i];
        Vev[V[i]].push_back(i);
        Rev[R[i]].push_back(i);
    }
    
    FOR(i,300100) if(Vev[i].size() || Rev[i].size()) {
        FOR(j,Vev[i].size()) st.update(L[Vev[i][j]],V[Vev[i][j]]+1,1);
        if(st.ma[1]>ma) ma=st.ma[1], LL=st.from[1],RR=i;
        FOR(j,Rev[i].size()) st.update(L[Rev[i][j]],V[Rev[i][j]]+1,-1);
    }
    
    vector<int> ret;
    FOR(i,N) if(LL<=V[i] && V[i]<=RR && L[i]<=LL && RR<=R[i]) ret.push_back(i+1);
    
    _P("%d\n",ret.size());
    ITR(it,ret) _P("%d ",*it);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}