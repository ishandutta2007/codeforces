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

ll N,A,B;
ll P[100005];
map<int,int> M;
int R[100005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>A>>B;
    
    FOR(i,N) cin>>P[i], M[P[i]]=i;
    
    if(A==B) {
        FOR(i,N) if(M.count(A-P[i])==0) return _P("NO\n");
        _P("YES\n");
        FOR(i,N) _P("0 ");
        return _P("\n");
    }
    
    queue<int> F;
    FOR(i,N) {
        R[i] = (M.count(A-P[i])<<0)+(M.count(B-P[i])<<1);
        if(R[i]==1 || R[i]==2) F.push(i);
        if(R[i]==0) return _P("NO\n");
    }
    
    while(F.size()) {
        int cur=F.front();
        F.pop();
        
        if(R[cur]==1) {
            if(M.count(A-P[cur])==0) return _P("NO\n");
            i=M[A-P[cur]];
            if(R[i]==2) return _P("NO\n");
            if(R[i]==3) R[i]=1, F.push(i);
            if(M.count(B-P[cur])) {
                j=M[B-P[cur]];
                if(R[j]==2) return _P("NO\n");
                if(R[j]==3) R[j]=1, F.push(j);
            }
        }
        if(R[cur]==2) {
            if(M.count(B-P[cur])==0) return _P("NO\n");
            i=M[B-P[cur]];
            if(R[i]==1) return _P("NO\n");
            if(R[i]==3) R[i]=2, F.push(i);
            if(M.count(A-P[cur])) {
                j=M[A-P[cur]];
                if(R[j]==1) return _P("NO\n");
                if(R[j]==3) R[j]=2, F.push(j);
            }
        }
    }
    
    FOR(i,N) if(R[i]!=1 && R[i]!=2) {
        if(P[i]*2==A) R[i]=1;
        if(P[i]*2==B) R[i]=2;
        if(R[i]!=1 && R[i]!=2) return _P("NO\n");
    }
    _P("YES\n");
    FOR(i,N) _P("%d%s", R[i]-1,(i<N-1)?" ":"\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}