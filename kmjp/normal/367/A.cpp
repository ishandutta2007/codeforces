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

string S;
int N,M;
int X[100001],Y[100001],Z[100001];

int dodo(int xx,int yy,int zz) {
    if(xx+yy+zz<3) return 1;
    if(xx==zz && xx==yy) return 1;
    
    if(xx==zz && xx==yy+1) return 1;
    if(xx==zz+1 && xx==yy+1) return 1;
    if(zz==yy && zz==xx+1) return 1;
    if(zz==yy+1 && zz==xx+1) return 1;
    if(yy==xx && yy==zz+1) return 1;
    if(yy==xx+1 && yy==zz+1) return 1;
    return 0;
}

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>S>>M;
    N=S.size();
    FOR(i,N) {
        X[i+1]=X[i];
        Y[i+1]=Y[i];
        Z[i+1]=Z[i];
        if(S[i]=='x') X[i+1]++;
        if(S[i]=='y') Y[i+1]++;
        if(S[i]=='z') Z[i+1]++;
    }
    
    FOR(i,M) {
        cin>>l>>r;
        if(dodo(X[r]-X[l-1],Y[r]-Y[l-1],Z[r]-Z[l-1])) _P("YES\n");
        else _P("NO\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}