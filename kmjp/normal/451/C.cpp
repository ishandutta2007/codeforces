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

int T;
ll N,K,D1,D2;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>T;
    FOR(i,T) {
        cin>>N>>K>>D1>>D2;
        int ok=0;
        FOR(j,4) {
            x=(j%2)?1:-1;
            y=(j/2)?1:-1;
            
            ll t=K+x*D1+y*D2;
            ll b=t/3;
            ll a=b-x*D1;
            ll c=b-y*D2;
            if(t%3==0 && a<=N/3 && a>=0 && b<=N/3 && b>=0 && c<=N/3 && c>=0) ok++;
        }
        if(N%3==0 && ok) _P("yes\n");
        else _P("no\n");
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