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

int N,M;
char mat[106][106];

void dodo(int Y,int X) {
    char c='A';
    while((Y>0&&c==mat[Y-1][X]) || (X>0&&c==mat[Y][X-1]) || (Y<N-1&&c==mat[Y+1][X]) || (X<M-1&&c==mat[Y][X+1])) c++;
    
    int sz,x,y;
    for(sz=2;sz<=100;sz++) {
        if(Y+sz>N || X+sz>M) break;
        FOR(x,sz) if(mat[Y+sz-1][X+x]!='$') goto out;
        FOR(y,sz) if(mat[Y+y][X+sz-1]!='$') goto out;
        if(c=='A' && Y>=1 && mat[Y-1][X+sz-1]=='A') goto out;
        if(c=='B' && (Y==0 || mat[Y-1][X+sz-1]!='A')) goto out;
        if(c=='C') goto out;
    }
    out:
    sz--;
    FOR(y,sz) FOR(x,sz) mat[Y+y][X+x]=c;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    ZERO(mat);
    FOR(y,N) FOR(x,M) mat[y][x]='$';
    FOR(y,N) FOR(x,M) if(mat[y][x]=='$') dodo(y,x);
    
    FOR(y,N) cout << mat[y] << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}