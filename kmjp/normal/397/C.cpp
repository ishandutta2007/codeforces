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

int N;
ll A[1001],t;
ll mo=1000000007;
map<ll,int> M;

ll combi(ll N_, ll C_) {
    int i;
    const int num=20000;
    static ll rev[num+1],revt[num+1];
    
    if(rev[1]==0) {
        rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[mo%i]*(mo-mo/i)%mo;
        revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%mo;
    }
    ll ret=revt[C_];
    FOR(i,C_) ret = (ret * ((N_-i)%mo))%mo;
    return ret;
}
ll hcomb(int P_,int Q_) { return combi(P_+Q_-1,Q_);}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N;
    FOR(i,N) {
        cin>>t;
        for(ll a=2;a*a<=t;a++) {
            while(t%a==0) t/=a,M[a]++;
        }
        if(t>1) M[t]++;
    }
    
    
    ll ret=1;
    ITR(it,M) {
        ret = (ret * hcomb(N,it->second)) % mo;
    }
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}