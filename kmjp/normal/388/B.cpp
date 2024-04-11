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

ll K;
int mat[1001][1001];

void solve() {
    int f,i,j,k,l,x,y,rr=0;
    
    cin>>K;
    K--;
    FOR(i,9) {
        FOR(j,(i==0) + K%10) mat[0][2+100*i+j]=1;
        FOR(j,9) {
            FOR(x,10) FOR(y,10) {
                if(j>=i && y!=0) continue;
                mat[2+100*i+j*10+x][2+100*i+j*10+10+y]=1;
            }
        }
        FOR(x,10) if(2+100*i+9*10+x<1000) mat[2+100*i+9*10+x][1]=1;
        K/=10;
    }
    
    
    _P("1000\n");
    FOR(y,1000) {
        FOR(x,1000) _P((mat[y][x] || mat[x][y])?"Y":"N");
        _P("\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}