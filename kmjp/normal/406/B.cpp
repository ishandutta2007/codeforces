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

int N;
int M[1000002];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N;
    ll tot=0;
    FOR(i,N) {
        cin>>x;
        M[x]=1;
    }
    j=0;
    for(i=1;i<=500000;i++) {
        if(M[i]==1 && M[1000001-i]==0) {
            M[1000001-i]=2;
        }
        else if(M[i]==0 && M[1000001-i]==1) {
            M[i]=2;
        }
        else if(M[i]==1 && M[1000001-i]==1) {
            j++;
        }
    }
    for(i=1;i<=500000;i++) if(j&&M[i]==0&&M[1000001-i]==0) j--,M[i]=M[1000001-i]=2;
    _P("%d\n",count(M,M+1000002,2));
    for(i=1;i<=1000000;i++) if(M[i]==2) _P("%d ",i);
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