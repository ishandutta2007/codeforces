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

int N,A[100001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    x=y=-1;
    FOR(i,N-1) {
        if(x==-1 && y==-1 && A[i]>A[i+1]) x=i;
        if(x>=0 && y==-1 && A[i]<A[i+1]) y=i;
        if(y>=0 && A[i]>A[i+1]) return _P("no\n");
    }
    if(x==-1 && y==-1) return _P("yes\n1 1\n");
    else if(y==-1) {
        if(x==0) return _P("yes\n1 %d\n",N);
        if(A[x-1]<A[N-1]) return _P("yes\n%d %d\n",x+1,N);
    }
    else if(x==0 && A[0]<A[y+1]) return _P("yes\n1 %d\n",y+1);
    else if(A[x-1]<A[y] && A[x]<A[y+1]) return _P("yes\n%d %d\n",x+1,y+1);
    return _P("no\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}