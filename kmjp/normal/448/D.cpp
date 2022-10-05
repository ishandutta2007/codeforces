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

ll N,M,K;

ll num(ll V) {
    ll ret=0;
    if(V<=0) return 0;
    for(ll x=1;x<=N;x++) ret+=min(V/x,M);
    return ret;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    ll L=0,R=1LL<<50;
    
    FOR(i,100) {
        ll M=(L+R)/2;
        if(num(M)>=K) R=M;
        else L=M+1;
    }
    
    //L-=3;
    //while(num(L)<K) L++;
    cout << L <<endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}