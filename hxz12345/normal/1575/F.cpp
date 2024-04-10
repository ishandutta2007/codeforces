#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int M=1000000007;
const int maxn=1e5+10;
map<int,int> A,B;
ll k,f[maxn],p[maxn],jc[maxn],s[maxn];
int n,m;
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
ll inv(ll x){return pow_(x,M-2);}
ll C(int x,int y){return jc[x]*inv(jc[y]*jc[x-y]%M)%M;}
ll solve(int x){
    if (B.find(x)!=B.end()) return B[x];
    ll ret=0;
    for (int i=0;i<=m;i++) ret=(ret+p[i]*s[x+i])%M;
    return B[x]=ret;
}
int main(){
    cin >> n >> k;
    jc[0]=1; for (int i=1;i<=n;i++) jc[i]=jc[i-1]*i%M;
    for (int i=1;i<=n;i++){
        int x; cin >> x;
        A[x]++;
    }
    f[0]=k-1;
    for (int i=1;i<n;i++){
        ll p=inv(n)*i%M;
        ll q=inv(n)*(n-i)%M*inv(k-1)%M;
        f[i]=(p*f[i-1]+1)%M*inv(q)%M;
    }
    s[n]=0;
    for (int i=n;i;i--) s[i-1]=(s[i]+f[i-1])%M;
    m=A[-1];
    for (int i=0;i<=m;i++) p[i]=C(m,i)*pow_(k-1,m-i)%M*inv(pow_(k,m))%M;
    ll tot=k;
    ll ans=0;
    for (auto x:A){
        if (x.F==-1) continue;
        ans=(ans+solve(x.S))%M;
        tot--;
    }
    ans=(ans+tot*solve(0))%M;
    ans=(ans-(k-1)*s[0])%M;
    ans=ans*inv(k-1)%M;
    cout << (ans+M)%M << endl;
}