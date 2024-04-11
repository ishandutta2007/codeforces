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

int N,M;
ll NN[10000010];
ll SUM[10000010];

int NP,prime[10000];
const int prime_max = 10000;
void cprime() {
    static int p[prime_max];
    int i,j;
    NP=0;
    for(i=2;i<prime_max;i++) {
        if(p[i]) continue;
        prime[NP++]=i;
        for(j=i*2;j<prime_max;j+=i) p[j]=i;
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cprime();
    
    cin>>N;
    FOR(i,N) {
        cin>>x;
        FOR(j,NP) {
            if(prime[j]*prime[j]>x) break;
            if(x%prime[j]==0) {
                NN[prime[j]]++;
                while(x%prime[j]==0) x/=prime[j];
            }
        }
        if(x!=1) NN[x]++;
    }
    
    FOR(i,10000001) SUM[i+1]=SUM[i]+NN[i+1];
    cin>>M;
    FOR(i,M) {
        cin>>x>>y;
        if(x>10000000) {
            _P("0\n");
            continue;
        }
        if(y>10000000) y=10000000;
        _P("%lld\n",SUM[y]-SUM[x-1]);
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