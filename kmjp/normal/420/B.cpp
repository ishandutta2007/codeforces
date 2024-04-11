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
char hoge[100001];
int msg[100001];

int ok[100005];
int inin[100005];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    
    
    FOR(i,N) ok[i]=0;
    FOR(i,M) {
        string SS;
        cin>>SS>>x;
        if(SS[0]=='+' && ok[x-1]==0) ok[x-1]=1;
        if(SS[0]=='-' && ok[x-1]==0) ok[x-1]=2;
        hoge[i]=SS[0];
        msg[i]=x-1;
    }
    
    FOR(i,N) inin[i]=1;
    
    set<int> S;
    FOR(i,N) if(ok[i]==2) S.insert(i);
    
    if(S.size()>0) {
        FOR(i,N) if(ok[i]==1) inin[i]=0;
    }
    
    set<int> sg;
    
    FOR(i,M) {
        if(hoge[i]=='+') {
            S.insert(msg[i]);
            if(S.size()==1) sg.insert(msg[i]);
            if(S.size()>1) inin[msg[i]]=0;
        }
        else {
            if(S.size()==1) sg.insert(msg[i]);
            if(S.size()>1) inin[msg[i]]=0;
            S.erase(msg[i]);
        }
    }
    
    if(sg.size()>1) {
        FOR(i,N) if(ok[i]) inin[i]=0;
    }
    
    if(S.size()>0) {
        FOR(i,N) if(ok[i] && S.find(i)==S.end()) inin[i]=0;
    }
    
    _P("%d\n",count(inin,inin+N,1));
    FOR(i,N) if(inin[i]) _P("%d ",i+1);
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