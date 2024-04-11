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

int N,A[100001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    sort(A,A+N);
    
    if(N==1) return _P("-1\n");
    if(A[0]==A[N-1]) return _P("1\n%d\n",A[0]);
    if(N==2 && (A[1]-A[0])%2==0) return _P("3\n%d %d %d\n",A[0]-(A[1]-A[0]),A[0]+(A[1]-A[0])/2,A[1]+(A[1]-A[0]));
    
    
    int mi=A[1]-A[0];
    FOR(i,N-1) mi=min(mi,A[i+1]-A[i]);
    x=-1;
    FOR(i,N-1) {
        if(A[i+1]-A[i]==mi) continue;
        else if(A[i+1]-A[i]==2*mi && x==-1) x=i;
        else return _P("0\n");
    }
    if(x==-1) _P("2\n%d %d\n",A[0]-mi,A[N-1]+mi);
    else _P("1\n%d\n",A[x]+mi);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}