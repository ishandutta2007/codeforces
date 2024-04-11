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

int N,A[101];
ll mat[61];
pair<int,int> P[101];

int mi;
int mip[101];
int cup[101];

void dfs(int cur,ll mask,int sum) {
    int i;
    if(sum>=mi) return;
    if(cur==N) {
        mi=sum;
        FOR(i,N) mip[i]=cup[i];
        return;
    }
    int tar=P[cur].second;
    if(mask) {
        for(i=58;i>0;i--) if((mask & (1LL<<i)) && abs(i+1-A[tar])<abs(1-A[tar])) {
            mask ^= 1LL<<i;
            cup[tar]=i+1;
            dfs(cur+1,mask & mat[i+1],sum+abs(cup[tar]-A[tar]));
        }
    }
    cup[tar]=1;
    dfs(cur+1,0,sum+abs(1-A[tar]));
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    mi=0;
    FOR(i,N) {
        cin>>A[i];
        P[i]=make_pair(A[i],i);
        mi+=A[i]-1;
        mip[i]=1;
    }
    for(x=1;x<=60;x++) for(y=1;y<=60;y++) if(__gcd(x,y)==1) mat[x] |= 1LL<<(y-1);
    sort(P,P+N);
    reverse(P,P+N);
    dfs(0,(1LL<<58)-1,0);
    FOR(i,N) _P("%d ",mip[i]);
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