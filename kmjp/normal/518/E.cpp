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

int N,K;
ll A[301000];
int vis[301000];
int ma=1020000000;

void dodo(int L,int R) {
    int num=(R-L)/K;
    if(A[R]-A[L]<num) {
        _P("Incorrect sequence\n");
        exit(0);
    }
    num--;
    if(num>=1) {
        int rl=-num/2,rr=(num-1)/2;
        if(rl<A[L]+1) rl=A[L]+1,rr=rl+(num-1);
        if(rr>A[R]-1) rr=A[R]-1,rl=rr-(num-1);
        for(int i=1;L+i*K<R;i++) A[L+i*K]=rl+i-1;
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,K) A[i]=-ma;
    FOR(i,K) A[N+K+i]=ma;
    FOR(i,N) {
        cin>>s;
        if(s=="?") A[i+K]=-1<<30;
        else A[i+K]=atoi(s.c_str());
    }
    N+=2*K;
    FOR(i,N) if(vis[i]==0) {
        vis[i]=1;
        for(j=i+K;j<N;j+=K) {
            if(A[j]!=-1<<30) break;
            vis[j]=1;
        }
        if(j<N) dodo(i,j);
    }
    
    FOR(i,N-2*K) cout<<A[i+K]<<" ";
    cout<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}