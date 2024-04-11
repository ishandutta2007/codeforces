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

ll N,M,L,R,P;
ll XL[160001],XR[160001];
vector<ll> S[100001];

vector<ll> enumdiv(ll n) {
    vector<ll> V;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) V.push_back(i);
        while(n%i==0) n/=i;
    }
    if(n>1) V.push_back(n);
    return V;
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M>>L>>R>>P;
    
    ll ret=0;
    // right&&down
    if(L==1) ret=(N*(M+1) + M*(N+1))%P;
    S[1].push_back(0);
    for(i=1;i<=N;i++) S[1].push_back((N+1-i)%P);
    for(i=2;i<=M;i++) {
        S[i].push_back(0);
        for(j=1;j*i<=N;j++) S[i].push_back((S[i].back()+S[1][j*i])%P);
    }
    for(i=1;i<=N;i++) S[1][i]=(S[1][i]+S[1][i-1])%P;
    for(y=R-1;y>0;y--) {
        XL[y]=XL[y+1];
        XR[y]=XR[y+1];
        while(XL[y]*XL[y]+y*(ll)y<L*L) XL[y]++;
        while(XR[y]*XR[y]+y*(ll)y<=R*R) XR[y]++;
        XR[y]--;
    }
    for(y=1;y<=min(M,R);y++) {
        ll line=0;
        if(XL[y]==0) XL[y]++;
        if(XL[y]>N) continue;
        if(XR[y]>N) XR[y]=N;
        
        vector<ll> D = enumdiv(y);
        FOR(i,1<<D.size()) {
            k=1;
            l=(__builtin_popcount(i)%2)?-1:1;
            FOR(j,D.size()) if(i&(1<<j)) k*=D[j];
            line += l*(S[k][XR[y]/k]-S[k][(XL[y]-1)/k]);
            line %= P;
            if(line<0) line+=P;
        }
        
        ret+=(line*2)%P*(M+1-y);
        ret%=P;
        if(ret<0) ret+=P;
        
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}