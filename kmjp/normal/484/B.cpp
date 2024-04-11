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

int N;
set<ll> S;
vector<ll> V;
int A[2000005];
int MI[2000005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>x, A[x]=1;
    for(i=1;i<=2000000;i++) MI[i]=A[i]?i:MI[i-1];
    
    int ma=0;
    FOR(i,1000001) if(A[i]) {
        for(j=2;j*i-1<=2000000;j++) {
            ma=max(ma,MI[j*i-1]%i);
        }
    }
    cout<<ma<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}