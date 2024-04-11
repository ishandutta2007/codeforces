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


int N,M;
int A[1000001];

ll hoge(ll pos) {
    int L=0,R=N-1;
    ll tot=0;
    while(L+M<=N-1 && A[L+M]<pos && L+M<=R) tot+=2*abs(A[L]-pos), L+=M;
    while(R-M>=0 && A[R-M]>pos && L<=R-M) tot+=2*abs(A[R]-pos), R-=M;
    
    if(A[R]>pos) tot+=2*(A[R]-pos);
    if(A[L]<pos) tot+=2*(pos-A[L]);
    return tot;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    
    ll L=-1000000000;
    ll R=1000000000;
    ll mi=1LL<<60;
    FOR(i,100) {
        ll po1=(L*2+R)/3;
        ll po2=(L+R*2)/3;
        
        ll tot1=hoge(po1);
        ll tot2=hoge(po2);
        mi=min(mi,tot1);
        mi=min(mi,tot2);
        if(tot1==tot2) L=po1,R=po2;
        if(tot1<tot2) R=po2;
        if(tot1>tot2) L=po1;
    }
    
    //FOR(i,7) mi=min(mi,hoge(L+i-3));
    //FOR(i,7) mi=min(mi,hoge(R+i-3));
    
    cout << mi << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}