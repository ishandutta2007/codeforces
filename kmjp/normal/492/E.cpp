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

ll N,M,DX,DY;
ll X[1001000],Y[1001000];
int rev[1001000];
int num[1001000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>DX>>DY;
    FOR(i,N) rev[DX*i%N]=i;
    
    FOR(i,M) {
        cin>>X[i]>>Y[i];
        num[((Y[i]-DY*rev[X[i]])%N+N)%N]++;
    }
    x=0;
    FOR(i,N) if(num[i]>num[x]) x=i;
    _P("%d %d\n",0,x);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}