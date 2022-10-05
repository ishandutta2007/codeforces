#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

string S,T;
int LS,LT;
int AP[1000002],BP[1000002];
int mat[1000002][3][3];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>S>>T;
    LS=S.size();
    LT=T.size();
    FOR(i,LS) S[i]=(S[i]=='R')?0:(S[i]=='G')?1:2;
    FOR(i,LT) T[i]=(T[i]=='R')?0:(T[i]=='G')?1:2;
    
    for(i=1;i<LT;i++) {
        memmove(mat[i+1],mat[i],sizeof(mat[i]));
        mat[i+1][T[i]][T[i-1]]++;
    }
    
    x=y=0;
    FOR(i,LS) AP[i]=x, x+=(x<LT&&S[i]==T[x]);
    FOR(i,LT) BP[i]=y, y+=(y<LS&&S[y]==T[i]);
    
    ll ret=0;
    y=0;
    FOR(i,LS) {
        x=AP[i];
        while(y<LT && i>=BP[y]) y++;
        
        ret+=y-x;
        if(i>0 && S[i-1]!=S[i]) ret -= mat[y][S[i-1]][S[i]]-mat[x][S[i-1]][S[i]];
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