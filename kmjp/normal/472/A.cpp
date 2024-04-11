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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

// NP,prime,div
void cprime() {
    int i,j;
    for(i=2;i<prime_max;i++) if(divp[i]==0) {
        //M[i]=NP;
        prime[NP++]=i;
        for(j=i;j<prime_max;j+=i) divp[j]=i;
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    int N;
    
    cprime();
    cin>>N;
    for(i=4;i<=N/2;i++) {
        if(divp[i]!=i && divp[N-i]!=N-i) return _P("%d %d\n",i,N-i);
    }
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}