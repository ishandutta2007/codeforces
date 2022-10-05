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

int N,M,K;
string S[2001];
int num[2001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    FOR(y,N) cin>>S[y];
    for(y=1;y<N;y++) FOR(x,M) {
        if(S[y][x]=='U') if(y%2==0) num[x]++;
        if(S[y][x]=='R') {
            f=x+y;
            if(f<M) num[f]++;
        }
        if(S[y][x]=='L') {
            f=x-y;
            if(f>=0) num[f]++;
        }
    }
    
    FOR(x,M) _P("%d ",num[x]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}