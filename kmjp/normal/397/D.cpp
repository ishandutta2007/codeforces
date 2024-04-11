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

ll isprime(ll a) {
    for(ll b=2;b*b<=a;b++) {
        if(a%b==0) return 0;
    }
    return 1;
}

void solve() {
    int f,i,j,k,l,x,y;
    int T;
    
    cin>>T;
    while(T--) {
        ll N,L,M;
        cin>>N;
        L=N,M=N+1;
        if(isprime(M)) {
            _P("%lld/%lld\n",M-2,2*M);
            continue;
        }
        while(isprime(L)==0) L--;
        while(isprime(M)==0) M++;
        ll aa=L*M-2*M+2*(N-L+1);
        ll bb=2*L*M;
        ll g=__gcd(aa,bb);
        _P("%lld/%lld\n",aa/g,bb/g);
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