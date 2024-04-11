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

int N,K,Q;
int A[5010];
map<int,int> M;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N) {
        cin>>A[i];
        for(x=1;x<=K;x++) {
            if(M.count(A[i]*x)==0) M[A[i]*x]=x;
            M[A[i]*x]=min(M[A[i]*x],x);
        }
    }
    M[0]=0;
    
    cin>>Q;
    while(Q--) {
        int X;
        int mi=50;
        cin>>X;
        ITR(it,M) if(M.count(X-it->first)) mi=min(mi,it->second + M[X-it->first]);
        
        if(mi>K) mi=-1;
        cout<<mi<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}