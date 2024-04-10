#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; (i) >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 524288;
ll s[MAXN*2],ss[MAXN*2];
const ll inf = 100000000000000000;
void up(int pos, ll val){
    pos+= MAXN;
    s[pos] = val;
    for(pos/=2; pos>0; pos/=2){
        s[pos] = max(s[pos*2],s[pos*2+1]);
    }
}
void uup(int pos, ll val){
    pos+= MAXN;
    ss[pos] = val;
    for(pos/=2; pos>0; pos/=2){
        ss[pos] = max(ss[pos*2],ss[pos*2+1]);
    }
}
ll query(int l, int r){
    l+=MAXN; r+=MAXN;
    ll ans = -inf;
    while(l <= r){
        if(l%2){
            ans = max(ans,s[l]);
            l++;
        }
        if(r%2 == 0){
            ans = max(ans,s[r]);
            r--;
        }
        r/=2; l/=2;
    }
    return ans;
}
void solve(){
    int N; cin >> N;
    vll v(N), h(N);
    for(ll &i: h)cin >> i;
    for(ll &i: v)cin >> i;
    vll k;
    vll p(N);
    for(int i = 0; i < MAXN*2; i++)s[i]= ss[i] = -inf;
    for(int i = 0; i < N; i++){
        while(!k.empty() && h[i] < h[k.back()])k.pop_back();
        if(k.empty())p[i] = -1;
        else p[i] = k.back();
        k.pb(i);
    }
    vll dp(N,-inf);
    ll m = 0,mn = -inf;
    for(int i = 0; i < N; i++){
        if(p[i]==-1){
            for(auto x: k)uup(x,-inf);
            k.clear();
            dp[i] = m + v[i];
        }else{
            while(!k.empty() && h[i] < h[k.back()]){
                uup(k.back(),-inf);
                k.pop_back();
            }
            dp[i] = ss[1];
            dp[i] = max(dp[i],query(p[i],i)+v[i]);
        }
    //    cout << p[i] << " "<< dp[i] << endl;
        m = max(m,dp[i]);
        up(i,dp[i]);
        uup(i,dp[i]);
        k.pb(i);
    }
    cout << dp[N-1] << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}