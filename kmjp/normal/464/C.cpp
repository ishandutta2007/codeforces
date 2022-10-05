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

string S;
ll mo=1000000007;

int N;
string qs[100005];
ll memo[20][100005];
ll dig[20][100005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>qs[0];
    cin>>N;
    N++;
    qs[0]="0->"+qs[0];
    for(i=1;i<N;i++) cin>>qs[i];
    FOR(i,10) memo[i][N]=i,dig[i][N]=10;
    
    for(i=N-1;i>=0;i--) {
        FOR(j,10) memo[j][i]=memo[j][i+1],dig[j][i]=dig[j][i+1];
        int from=qs[i][0]-'0';
        
        memo[from][i]=0;
        dig[from][i]=1;
        for(j=qs[i].size()-1;j>=3;j--) {
            int nn=qs[i][j]-'0';
            memo[from][i]=(memo[from][i]+memo[nn][i+1]*dig[from][i])%mo;
            dig[from][i]=(dig[from][i]*dig[nn][i+1])%mo;
        }
        
    }
    
    cout << memo[0][0] << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}