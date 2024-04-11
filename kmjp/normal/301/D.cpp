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

int N,M;
int A[200005],rev[200005];
vector<int> P[200005];
int L[200005],R[200005],ret[200005],num[200005];
vector<int> Q[200005];

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,18> bt;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i],rev[A[i]]=i;
    FOR(i,N) {
        for(j=A[i];j<=N;j+=A[i]) {
            if(rev[j]<=i) P[i].push_back(rev[j]);
            else P[rev[j]].push_back(i);
        }
    }
    
    FOR(i,M) {
        cin>>L[i]>>R[i];
        Q[R[i]-1].push_back(i);
    }
    
    FOR(i,N) {
        if(P[i].size()<1000000) {
            ITR(it,P[i]) bt.update(*it+1,1);
        }
        FOR(j,Q[i].size()) ret[Q[i][j]]=bt.total((1<<18)-1)-bt.total(L[Q[i][j]]-1);
    }
    
    FOR(i,M) cout << ret[i] << endl;
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}