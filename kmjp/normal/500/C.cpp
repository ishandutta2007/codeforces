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

int N,M;
int W[1020];
int B[1020];
int st[1020];
vector<int> V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,N) cin>>W[i];
    ll ret=0;
    FOR(i,M) {
        cin>>B[i];
        B[i]--;
        if(st[B[i]]==0) st[B[i]]=1, V.push_back(B[i]);
        FOR(x,V.size()) {
            if(V[x]!=B[i]) ret += W[V[x]];
            else break;
        }
        for(y=x;y>=1;y--) V[y]=V[y-1];
        V[0]=B[i];
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}