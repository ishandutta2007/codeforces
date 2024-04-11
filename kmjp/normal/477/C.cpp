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

string S,P;
int LS,LP;
int dpdp[2002][2002][2];
int res[2002];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S>>P;
    LS=S.size();
    LP=P.size();
    
    MINUS(dpdp);
    FOR(i,LS+1) FOR(j,LS+1) dpdp[i][j][0]=3000;
    FOR(i,LS+1) FOR(j,LS+1) dpdp[i][j][1]=-1;
    
    dpdp[0][0][0]=dpdp[0][0][1]=0;
    
    FOR(i,LS) FOR(j,LS) if(dpdp[i][j][1]>=0) {
        if(S[i]==P[j%LP]) {
            dpdp[i+1][j+1][0]=min(dpdp[i+1][j+1][0],dpdp[i][j][0]);
            dpdp[i+1][j+1][1]=max(dpdp[i+1][j+1][1],dpdp[i][j][1]);
        }
        if((j%LP)==0) dpdp[i+1][j][0]=min(dpdp[i+1][j][0],dpdp[i][j][0]);
        dpdp[i+1][j][0]=min(dpdp[i+1][j][0],dpdp[i][j][0]+1);
        dpdp[i+1][j][1]=max(dpdp[i+1][j][1],dpdp[i][j][1]+1);
    }
    FOR(i,LS+1) if(dpdp[LS][i][1]>=0) {
        for(j=dpdp[LS][i][0];j<=dpdp[LS][i][1];j++) res[j]=max(res[j],i/LP);
    }
    FOR(i,LS+1) _P("%d ",res[i]);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}