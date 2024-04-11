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

int P,X;
char S[1000005];
void solve() {
    int f,i,j,k,l,x,y;
    cin>>P>>X;
    
    ZERO(S);
    for(i=1;i<=9;i++) {
        int ng=0,y=0;
        S[P-1]='0'+i;
        for(x=P-1;x>=0;x--) {
            l=(S[x]-'0')*X+y;
            if(x==0) {
                if(l!=i || S[x]=='0') ng=1;
            }
            else {
                S[x-1]='0'+l%10;
                y=l/10;
            }
        }
        if(ng) continue;
        _P("%s\n",S);
        return;
    }
    _P("Impossible\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}