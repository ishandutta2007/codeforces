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


string S;
ll dp[1000001][7];
ll ret=0;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S;
    FOR(i,S.size()) {
        if(S[i]>='a' && S[i]<='z') {
            dp[i+1][0]=1+dp[i][0];
            dp[i+1][2]=dp[i][1]+dp[i][2];
            dp[i+1][4]=dp[i][3]+dp[i][4];
            ret+=dp[i+1][4];
        }
        else if(S[i]>='0' && S[i]<='9') {
            dp[i+1][0]=dp[i][0];
            dp[i+1][2]=dp[i][1]+dp[i][2];
        }
        else if(S[i]=='_') dp[i+1][0]=dp[i][0];
        else if(S[i]=='@') dp[i+1][1]=dp[i][0];
        else if(S[i]=='.') dp[i+1][3]=dp[i][2];
    }
    
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}