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

int L;
string S;
ll A[4];

ll mo=1000000007;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>L>>S;
    FOR(i,L) {
        A[0]+=S[i]=='A';
        A[1]+=S[i]=='T';
        A[2]+=S[i]=='G';
        A[3]+=S[i]=='C';
    }
    sort(A,A+4);
    x=1;
    if(A[3]==A[2]) x++;
    if(A[3]==A[1]) x++;
    if(A[3]==A[0]) x++;
    ll ret=1;
    FOR(i,L) ret=ret*x%mo;
    
    cout<<ret << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}