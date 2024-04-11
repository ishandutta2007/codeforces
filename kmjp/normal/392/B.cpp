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

int T[3][3],N;
ll dpdp[41][3][3];

ll calc(int n,int s,int e) {
    int t=3-s-e;
    if(n==1) return min(T[s][e],T[s][t]+T[t][e]);
    if(dpdp[n][s][e]==-1) {
        int t=3-s-e;
        dpdp[n][s][e] = min(calc(n-1,s,t) + T[s][e] + calc(n-1,t,e),calc(n-1,s,e)+T[s][t]+calc(n-1,e,s)+T[t][e]+calc(n-1,s,e));
    }
    return dpdp[n][s][e];
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>T[0][0]>>T[0][1]>>T[0][2];
    cin>>T[1][0]>>T[1][1]>>T[1][2];
    cin>>T[2][0]>>T[2][1]>>T[2][2];
    cin>>N;
    
    FOR(i,N+1) FOR(x,3) FOR(y,3) dpdp[i][x][y]=-1;
    cout << min(calc(N,0,2),calc(N,0,1)+calc(N,1,2)) << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}