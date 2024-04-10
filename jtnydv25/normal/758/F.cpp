#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

const int N = 1e7+10, M = 100000;
inline ll powr(ll a, ll b){
    if(a == 1) return 1;
    ll x = 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
inline ll invpowr(ll a, int n){
    ll mn = max(0LL,(ll)pow(a,1./n)-3);
    while(powr(mn,n) <= a) mn++;
    return mn - 1;
}
int mu[M];
vi divs[M];
inline int n_copr(int n, int m){ // number of numbers <= n, > m, coprime to m
    if(n<m) return 0;
    if(m==1) return n - 1;
    int ret = 0;
    for(int d:divs[m]) ret += mu[d]*(n/d - m/d);
    return ret;    
}
int main(){
    for(int i = 2;i<M;i++) if(!mu[i]) for(int j = i;j<M;j+=i) mu[j] = i;
    mu[1] = 1;    
    for(int i = 2;i<M;i++){
        int p = mu[i], x = i/p;
        mu[i] = (x%p==0?0:-mu[x]);
    }
    for(int i = 1;i<M;i++) if(mu[i]!=0) for(int j = i;j<M;j+=i) divs[j].eb(i);
    int L,R,n;
    cin>>n>>L>>R;   
    if(n >= 30){
        cout<<0;
        return 0;
    } 
    if(n == 1){
        cout<<R-L+1<<endl;
        return 0;
    }   
    if(n == 2){
        cout<<(R-L)*1ll*(R-L+1)<<endl;
        return 0;
    }
    ll pwr = 1;
    ll ans = 0;
    n--;
    for(int q = 1;pwr<=R;pwr = powr(q+1,n),q++){
        int prevmx = 0;
        ll prevcnt = 0,cnt;
        for(int j = pwr;j<=R;j+=pwr){
            int mx = invpowr(R/(j/pwr),n);
            if(mx == prevmx) cnt = prevcnt;
            else cnt = n_copr(mx,q);
            if(j >= L) ans += (cnt<<1);
            prevcnt = cnt; prevmx = mx;
        }
    }
    cout<<ans;
}