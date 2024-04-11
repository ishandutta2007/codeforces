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

double memo[105][105][105];

double dpdp(int R,int S,int P) {
    if(R==0) return 0;
    if(S+P==0) return 1;
    double& ret=memo[R][S][P];
    if(memo[R][S][P]>=0) return ret;
    ret = 0;
    if(R&&S) ret += dpdp(R,S-1,P)*R*S;
    if(S&&P) ret += dpdp(R,S,P-1)*S*P;
    if(R&&P) ret += dpdp(R-1,S,P)*R*P;
    ret /= (R*S+S*P+R*P);
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    FOR(x,101) FOR(y,101) FOR(i,101) memo[x][y][i]=-1;
    cin>>x>>y>>i;
    _P("%.12lf %.12lf %.12lf\n",dpdp(x,y,i),dpdp(y,i,x),dpdp(i,x,y));
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}