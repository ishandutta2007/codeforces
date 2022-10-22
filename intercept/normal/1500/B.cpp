#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
ll n, m;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    ll r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
ll inv(ll a, ll b) {
    ll x, y;
    ll r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}
const int maxn = 1e6 + 5;
ll k;
ll a[maxn], b[maxn], c[maxn];
int ha[maxn], hb[maxn];
void init(){
    ll g = __gcd(n , m);
    ll M = n*m/g;
    fors(i,1,n+1){
        if(hb[a[i]] == 0) {
            c[i] = -1; continue;
        }
        ll c1 = i-1, c2 = hb[a[i]]-1;
        if((c2-c1)%g) {
            c[i] = -1;
            continue;
        }
        c[i] = (inv(n/g, m/g) * ((c2-c1)/g)%(m/g)) * n + c1;
        c[i] = (c[i]%M + M)%M;
        c[i]++;
    }
}
bool check(ll lim){
    ll g = __gcd(n , m);
    ll M = n*m/g;
    ll cur = 0;
    fors(i,1,n+1){
        if(c[i] == -1) continue;
        if(lim >= c[i]){
            cur+= (lim-c[i])/M + 1;
        }
        if(lim-cur < k) return false;
    }
    return lim-cur >= k;
}
int main()
{
    cin>>n>>m>>k;
    fors(i,1,n+1) scanf("%lld", &a[i]), ha[a[i]]=i;
    fors(i,1,m+1) scanf("%lld", &b[i]), hb[b[i]]=i;
    init();
    ll l = 1, r = 1e18, ans = -1;
    while(l <= r){
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    assert(ans != -1);
    cout<<ans<<endl;
	return 0;
}