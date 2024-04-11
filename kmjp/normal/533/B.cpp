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

int N;
vector<int> E[202000];
int P[202000];
ll A[202000];
ll T[2][202000];
ll ma;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>P[i]>>A[i];
    for(i=1;i<N;i++) E[P[i]-1].push_back(i);
    
    for(i=N-1;i>=0;i--) {
        T[1][i]=-1LL<<60;
        FORR(r,E[i]) {
            ll p0=T[0][i],p1=T[1][i];
            T[0][i]=max(p0+T[0][r],p1+T[1][r]);
            T[1][i]=max(p1+T[0][r],p0+T[1][r]);
        }
        T[1][i]=max(T[1][i],T[0][i]+A[i]);
    }
    cout<<max(T[0][0],T[1][0])<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}