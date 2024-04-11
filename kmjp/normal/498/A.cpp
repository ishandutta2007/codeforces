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

ll X[2],Y[2];
int N;
ll A[1000],B[1000],C[1000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>X[0]>>Y[0];
    cin>>X[1]>>Y[1];
    cin>>N;
    
    x=0;
    FOR(i,N) {
        cin>>A[i]>>B[i]>>C[i];
        ll aa=A[i]*X[0]+B[i]*Y[0]+C[i];
        ll bb=A[i]*X[1]+B[i]*Y[1]+C[i];
        if(aa<0 && bb>0) x++;
        if(aa>0 && bb<0) x++;
    }
    cout<<x<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}