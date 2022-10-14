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
#define sz(x) (int)b((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;

ll kek(ll a){
	return a*(a-1)/2;
}

void solve(){
	vector<pii> v;
	int N; cin >> N;
	ll ans = 0;
	ll pd, dp, pp, dd;
	while(N--){
		int x,y;
		cin >> x >> y;
		x /= 2; y /= 2;
		pd = dp = pp = dd = 0;
		for(auto i: v){
			if(abs(x-i.fi)%2){
				if(abs(y-i.se)%2)dd++;
				else dp++;
			}else{
				if(abs(y-i.se)%2)pd++;
				else pp++;
			}
		}
		//cout << pp << " " << dd << " " << pd << " " << dp << endl;
		v.pb({x,y});
		ans += kek(pd) + pd * pp + kek(pp) + pp * dp + kek(dp) + kek(dd) + pp*dd;
	}
	cout << ans << endl;
	return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;

//    cin >> T;

    while(T--){
        solve();
    }
}