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

ll N,M,P;
int A[200010],B[200010];

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M>>P;
    FOR(i,N) cin>>A[i];
    FOR(i,M) cin>>B[i];
    set<int> Q;
    
    map<int,int> MM,MM2;
    FOR(j,M) MM2[B[j]]--;
    FOR(i,P) {
        if(i+(M-1)*P>=N) continue;
        MM=MM2;
        for(j=i;j<N;j+=P) {
            MM[A[j]]++;
            if(MM[A[j]]==0) MM.erase(A[j]);
            if(j-M*P>=0) {
                MM[A[j-M*P]]--;
                if(MM[A[j-M*P]]==0) MM.erase(A[j-M*P]);
            }
            if(MM.empty()) Q.insert(1+j-(M-1)*P);
        }
    }
    
    _P("%d\n",Q.size());
    ITR(it,Q) _P("%d ",*it);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}