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

int N,K;
int A[3000];
ll mo=1000000007;

ll dpdp[2001][1<<12];
int next[1<<12][2];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    K--;
    FOR(i,N) cin>>A[i], A[i]/=2;
    
    ll ret=0;
    dpdp[0][0]=1;
    FOR(i,N) {
        if(A[i]==0) ret=ret*2%mo;
        for(int mask=0;mask<1<<K;mask++) {
            
            if(A[i]==1 || A[i]==0) {
                if(mask+1>=1<<K) ret+=dpdp[i][mask];
                else dpdp[i+1][mask+1]=(dpdp[i+1][mask+1]+dpdp[i][mask])%mo;
            }
            if(A[i]==2 || A[i]==0) {
                if(mask&1) {
                    dpdp[i+1][2]+=dpdp[i][mask];
                }
                else {
                    if(mask+2>=1<<K) ret+=dpdp[i][mask];
                    else dpdp[i+1][mask+2]=(dpdp[i+1][mask+2]+dpdp[i][mask])%mo;
                }
                
            }
            
        }
    }
    cout << ret%mo << endl;
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}