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

int L;
string S;
int num[2000003];
int D[1000001];

int ok(int sp) {
    ZERO(num);
    int x=1000000;
    int i;
    
    num[x]=1;
    FOR(i,L) {
        x+=(S[i]=='L')?-1:1;
        if(x>=1000000+sp) x=1000000+sp-1;
        num[x]++;
    }
    if(num[x]==1) return 1;
    return 0;
    
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S;
    L=S.size();
    
    // rev
    if(S[L-1]=='R') FOR(i,L) S[i]=(S[i]=='L')?'R':'L';
    
    if(ok(1<<30)) return _P("1\n");
    if(ok(1)==0) return _P("0\n");
    
    int LL=1,RR=L;
    FOR(i,30) {
        int mm=(LL+RR)/2;
        if(ok(mm)) LL=mm;
        else RR=mm-1;
    }
    
    while(ok(LL)) LL++;
    
    _P("%d\n",LL-1);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}