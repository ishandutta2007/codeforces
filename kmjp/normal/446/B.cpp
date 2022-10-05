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

ll H,W,K,P;
int A[1001][1001];
priority_queue<ll> RR,CC;
ll RV[1001];
ll CV[1001];
ll SR,SC;

ll RS[1000001];
ll CS[1000001];


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>H>>W>>K>>P;
    FOR(y,H) FOR(x,W) cin>>A[y][x];
    FOR(y,H) FOR(x,W) RV[y]+=A[y][x],CV[x]+=A[y][x];
    FOR(y,H) RR.push(RV[y]);
    FOR(x,W) CC.push(CV[x]);
    
    FOR(i,K) {
        ll mr=RR.top();
        ll mc=CC.top();
        RS[i+1]=RS[i]+mr;
        CS[i+1]=CS[i]+mc;
        RR.pop();
        RR.push(mr-W*P);
        CC.pop();
        CC.push(mc-H*P);
    }
    
    ll ma=-1LL<<60;
    FOR(i,K+1) {
        ma=max(ma,RS[i]+CS[K-i]-P*i*(K-i));
    }
    
    cout << ma << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}