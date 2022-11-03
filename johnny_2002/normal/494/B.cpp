#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

string s,t;
int g[N]={0},r[N],n,m;
ll f[N]={0},p[N]={0};
void preKMP(){
    r[0]=r[1]=0;
    FOR(i,2,m){
        int re=r[i-1];
        while (re&&t[i-1]!=t[re]) re=r[re];
        if (t[i-1]==t[re]) r[i]=re+1;
        else r[i]=0;
    }
    //FOR(i,2,m) printf("%d ",r[i]);
}
void prepare(){
    cin>>s>>t;
    n=s.length();m=t.length();
    preKMP();
}
void solve(){
    int cur=0,L=0;
    FOR(i,1,n){
        while (cur&&s[i-1]!=t[cur]) cur=r[cur];
        if (s[i-1]==t[cur]) cur++;
        if (cur==m) L=i-m+1;
        if (L) g[i]=L;
    }
    //FOR(i,1,n) printf("%d ",g[i]);
    FOR(i,1,n){
        f[i]=f[i-1];
        if (g[i]) f[i]=(f[i]+p[g[i]-1]+g[i])%MOD;
        p[i]=(p[i-1]+f[i])%MOD;
    }
    //FOR(i,1,n) printf("%d ",f[i]);
    cout<<f[n];
}
int main(){
    prepare();
    solve();
}