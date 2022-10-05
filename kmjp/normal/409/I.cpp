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
#include <time.h>
#include <unistd.h>

string S;
vector<int> V;
vector<int> E[1024];
vector<int> R[1024];
int inin[1024];
int vis[1024];
int num[1024];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S;
    S=S.substr(2);
    j=0;
    FOR(i,S.size()) {
        if(S[i]=='_') j++;
        else V.push_back(j),j=0;
        if(S[i]==')') break;
    }
    i+=3;
    x=j=0;
    for(;i<S.size();i++) {
        if(S[i]=='_') j++;
        else if(S[i]=='<') x=j,j=0;
        else if(S[i]=='>') x=-j,j=0;
        else {
            if(x>0) {
                E[x].push_back(j);
                R[j].push_back(x);
                inin[j]++;
            }
            else {
                E[j].push_back(-x);
                R[-x].push_back(j);
                inin[-x]++;
            }
            j=0;
            if(S[i]=='.') break;
        }
    }
    set<int> Q;
    MINUS(num);
    FOR(i,1024) if(inin[i]==0) Q.insert(i);
    
    while(!Q.empty()) {
        int k=*Q.begin();
        Q.erase(Q.begin());
        num[k]=0;
        FOR(i,R[k].size()) num[k]=max(num[k],num[R[k][i]]+1);
        if(num[k]>=10) return _P("false\n");
        FOR(i,E[k].size()) if(--inin[E[k][i]]==0) Q.insert(E[k][i]);
    }
    
    FOR(i,V.size()) if(num[V[i]]==-1) return _P("false\n");
    FOR(i,V.size()) _P("%d",num[V[i]]);
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