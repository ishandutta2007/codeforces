#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T = 1;
ll N,M;
const ll MOD = 1000000007;
const int MAXN = 600105;
ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN],finv[MAXN];
ll bin (ll a, ll b){
    if(b > a)return 0;
    return (((fact[a]*finv[b])%MOD)*finv[a-b])%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    finv[MAXN-1] = inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i > 0; i--)finv[i-1] = (finv[i]*i)%MOD;
}
int uf[MAXN];
int sz[MAXN];
bool act[MAXN];
bool p[MAXN];
int find(int n){
    if(uf[n] != n)uf[n] = find(uf[n]);
    return uf[n];
}

void uni(int a, int b){
    a = find(a); b = find(b);
    if(a == b)return;
    if(sz[a] < sz[b])swap(a,b);
    uf[b] = a;
    act[a] = 1;
    p[a]|=p[b];
    sz[a]+=sz[b];
}
void solve(){
    cin >> N >> M;
    vi sol;
    for(int i = 0; i < MAXN; i++){
        sz[i] = 1; uf[i] = i;
    }
    int k,a,b;
    for(int i = 0; i < N; i++){
        cin >> k;
        if(k == 1){
            cin >> a;
            a = find(a);
            act[a] = 1;
            if(p[a] == 0){
                sol.pb(i+1);
                p[a] = 1;
            }
        }else{
            cin >> a >> b;
            a = find(a); b = find(b);
            if(a!=b && (p[a]==0||p[b]==0)){sol.pb(i+1);uni(a,b);}
        }
    }
    set<int> sos;
    for(int i = 1; i <= M; i++){
        if(act[find(i)])sos.insert(find(i));
    }
    ll ans = 1,tmp;
    for(auto x: sos){
        //cout << x << " ";
        tmp = 0;
        if(p[x])ans*=fexp(2,sz[x]);
        else {
            for(int i = 0; i <= sz[x]; i+=2){
                tmp+=bin(sz[x],i);
                tmp%=MOD;
            }
            ans*=tmp;
        }
        ans%=MOD;
    }
    cout << ans << " "<<sol.size()<<"\n";
    for(auto x: sol)cout << x << " ";
    cout << "\n";
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    f_init();
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}