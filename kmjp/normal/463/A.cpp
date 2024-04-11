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
int N,S;
int X[101],Y[101];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>S;
    int ma=-1;
    FOR(i,N) {
        cin>>X[i]>>Y[i];
        if(X[i]<=S && Y[i]==0) ma=max(ma,0);
        if(X[i]<S && Y[i]!=0) ma=max(ma,100-Y[i]);
    }
    cout << ma << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}