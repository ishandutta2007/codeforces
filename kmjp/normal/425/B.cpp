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

int H,W,K,ret;
int A[101][101];

void solve() {
    int f,i,j,k,l,x,y;
    int mi=0;
    cin>>H>>W>>K;
    FOR(y,H) FOR(x,W) cin>>A[y][x];
    
    if(W<=K*2+1) {
        ret=K+1;
        for(int mask=0;mask<1<<W;mask++) {
            int tot=0;
            FOR(y,H) {
                int c=0;
                FOR(x,W) c += (A[y][x]!=((mask>>x)&1));
                tot+=min(c,W-c);
            }
            ret = min(ret,tot);
        }
    }
    else {
        FOR(y,H) {
            int c=0;
            FOR(x,W) c += A[y][x]!=A[0][x];
            if(c>W-c) {
                FOR(x,W) A[y][x]^=1;
            }
        }
        ret=0;
        FOR(x,W) {
            int c=0;
            FOR(y,H) c+=A[y][x];
            ret+=min(c,H-c);
        }
    }
    
    if(ret>K) _P("-1\n");
    else _P("%d\n",ret);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}