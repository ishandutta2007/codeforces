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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < k; i++)
#define foll(i,k) for(long long i = 0; i < k; i++)
#define FORr(i,k) for(int i = k-1; i >= 0; i--)
#define folr(i,k) for(long long i = k-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

ll findMinX(ll num[], ll rem[], ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    ll result = 0;

    // Apply above formula
    for (ll i = 0; i < k; i++) {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}

// Driver method
ll tcr(ll a, ll b, ll c, ll d)
{
    ll num[] = {a, b};
    ll rem[] = {c, d};
    ll k = sizeof(num) / sizeof(num[0]);
    return findMinX(num, rem, k);
}

ll sos(ll a, ll b){
    if(a == 0 || b == 0)return 0;
    return (a/__gcd(a,b))*b;
}

void solve(){
    ll N,M,K; cin >> N >> M >> K;
    vll v(N), vv(M);
    for(ll& i: v)cin >> i;
    for(ll& i: vv)cin >> i;
    vll pos(1000020,-1);
    for(int i = 0; i < M; i++)pos[vv[i]] = i;
    ll gc = __gcd(N,M);
    ll mcm = N*M/gc;
    vll kk(N);
    for(ll i = 0; i < N; i++){
        if(pos[v[i]] == -1 || i%gc != pos[v[i]]%gc )continue;
        kk[i] = gc*tcr(N/gc,M/gc,i/gc,pos[v[i]]/gc) + i%gc;
    }
    ll bs = 0, cur;
    vector<bool> check(N);
    for(int j = 0; j < N; j++){
        check[j] = (pos[v[j]] != -1 && j%gc == pos[v[j]]%gc);
    }
    for(ll i = (1LL << 60); i > 0; i/=2){
        cur = bs+i;
        ll cnt = cur;
        ll m = cur%mcm;
        for(ll j = 0; j < N; j++){
            if(check[j]){
                cnt -= cur/mcm;
                if(kk[int(j)] < m)cnt--;
            }
        }
        if(cnt < K)bs = cur;
    }
    cout << bs+1<<endl;
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