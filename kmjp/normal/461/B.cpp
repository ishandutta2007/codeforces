#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int C[100002],K;
vector<int> E[100002];
ll mo=1000000007;
ll memo[1000002][2];

ll rev(ll a) {
    ll r=1, n=mo-2;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N;
    FOR(i,N-1) {
        cin>>x;
        E[x].push_back(i+1);
    }
    
    FOR(i,N) cin>>C[i];
    for(int cur=N-1;cur>=0;cur--) {
        memo[cur][1]=1;
        FOR(i,E[cur].size()) memo[cur][1]=memo[cur][1]*memo[E[cur][i]][1]%mo;
        if(C[cur]) {
            memo[cur][0]=memo[cur][1];
        }
        else {
            FOR(i,E[cur].size()) memo[cur][0]+=(memo[cur][1]*memo[E[cur][i]][0])%mo*rev(memo[E[cur][i]][1])%mo;
            memo[cur][0]%=mo;
            memo[cur][1]=(memo[cur][1]+memo[cur][0])%mo;
        }
    }
    cout<<memo[0][0]<<endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}