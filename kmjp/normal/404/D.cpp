#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int L;
string S;

ll mo=1000000007;
ll dp[1000002][4][4];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>S;
    L=S.size();
    
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    FOR(i,L) {
        if(S[i]=='0' || S[i]=='?') {
            dp[i+1][1][0]=(dp[i+1][1][0]+dp[i][3][1])%mo;
            dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][0][0])%mo;
            dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][1][0])%mo;
            dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][2][0])%mo;
        }
        if(S[i]=='1' || S[i]=='?') {
            dp[i+1][3][1]=(dp[i+1][3][1]+dp[i][3][3])%mo;
            dp[i+1][3][1]=(dp[i+1][3][1]+dp[i][1][3])%mo;
            dp[i+1][3][1]=(dp[i+1][3][1]+dp[i][2][3])%mo;
            dp[i+1][0][1]=(dp[i+1][0][1]+dp[i][0][0])%mo;
            dp[i+1][0][1]=(dp[i+1][0][1]+dp[i][1][0])%mo;
            dp[i+1][1][1]=(dp[i+1][1][1]+dp[i][3][1])%mo;
        }
        if(S[i]=='2' || S[i]=='?') {
            dp[i+1][3][2]=(dp[i+1][3][2]+dp[i][3][3])%mo;
            dp[i+1][3][2]=(dp[i+1][3][2]+dp[i][1][3])%mo;
            dp[i+1][3][2]=(dp[i+1][3][2]+dp[i][2][3])%mo;
        }
        if(S[i]=='*' || S[i]=='?') {
            dp[i+1][1][3]=(dp[i+1][1][3]+dp[i][0][1])%mo;
            dp[i+1][1][3]=(dp[i+1][1][3]+dp[i][1][1])%mo;
            dp[i+1][2][3]=(dp[i+1][2][3]+dp[i][3][2])%mo;
            dp[i+1][3][3]=(dp[i+1][3][3]+dp[i][1][3])%mo;
            dp[i+1][3][3]=(dp[i+1][3][3]+dp[i][2][3])%mo;
            dp[i+1][3][3]=(dp[i+1][3][3]+dp[i][3][3])%mo;
        }
    }
    
    ll ret=dp[L][0][0]+dp[L][1][0]+dp[L][3][1]+dp[L][1][3]+dp[L][2][3]+dp[L][3][3];
    cout << ret%mo << endl;
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}