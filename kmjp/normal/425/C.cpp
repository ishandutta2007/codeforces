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

int N,M,S,E;
ll A[100001],B[100001];
vector<int> SB[100001];
int dpdp[401][100001];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M>>S>>E;
    FOR(i,N) cin>>A[i];
    FOR(i,M) {
        cin>>B[i];
        SB[B[i]].push_back(i);
    }
    FOR(x,301) FOR(y,100001) dpdp[x][y]=1000000;
    FOR(y,100001) dpdp[0][y]=0;
    int ma=0;
    FOR(x,301) {
        int mi=(x>0)?(dpdp[x][x-1]+1):0;
        for(y=x;y<N;y++) {
            vector<int>::iterator it=lower_bound(SB[A[y]].begin(),SB[A[y]].end(),mi);
            if(it==SB[A[y]].end()) {
                dpdp[x+1][y]=1000000;
            }
            else {
                dpdp[x+1][y]=*it;
                k=(x+1)*E+(y+1)+(*it+1);
                if(k<=S) ma=max(ma,x+1);
            }
            
            mi=min(mi,dpdp[x][y]+1);
        }
    }
    _P("%d\n",ma);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}