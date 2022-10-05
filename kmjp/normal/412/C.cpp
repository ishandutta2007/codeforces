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
int mask[100001];
char hoge[100001];
void solve() {
    int f,i,j,k,l,x,y;
    string S;
    cin>>N;
    FOR(i,N) {
        cin>>S;
        l=S.size();
        FOR(x,S.size()) {
            if(S[x]=='?') mask[x] |= 1<<30;
            else mask[x] |= 1<<(S[x]-'a');
        }
    }
    FOR(i,l) {
        x=__builtin_popcount(mask[i]&((1<<26)-1));
        if(x==0) hoge[i]='a';
        else if(x==1) {
            FOR(y,26) if(mask[i]&(1<<y)) hoge[i]='a'+y;
        }
        else hoge[i]='?';
    }
    _P("%s\n",hoge);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}