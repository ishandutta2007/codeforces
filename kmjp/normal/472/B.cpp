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

int N,K;
int F[2005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N) cin>>F[i];
    sort(F,F+N);
    reverse(F,F+N);
    int tot=0;
    
    for(i=0;i<N;i+=K) tot += (F[i]-1)*2;
    cout << tot << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}