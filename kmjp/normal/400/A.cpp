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

void solve() {
    int f,i,j,k,l,x,y;
    cin>>f;
    while(f--) {
        string S;
        cin>>S;
        int ok[13],num=0;
        ZERO(ok);
        for(i=1;i<=12;i++) if(12%i==0) {
            j=12/i;
            FOR(x,j) {
                int n=0;
                for(y=x;y<12;y+=j) if(S[y]=='O') n++;
                if(n==0) ok[i]=1;
            }
        }
        _P("%d",count(ok+1,ok+13,1));
        for(i=1;i<=12;i++) if(ok[i]) _P(" %dx%d",i,12/i);
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