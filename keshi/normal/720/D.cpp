//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, k, dp[maxn], fen[maxn];
pll p[maxn];
vector<ll> vec[maxn], cev[maxn];
set<pll> s, st;

void upd(ll x, ll y){
	if(y < 0) y += mod;
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
		if(fen[x] >= mod) fen[x] -= mod;
	}
	return;
}
ll get(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
		if(y >= mod) y -= mod;
	}
	return y;
}

int main(){
    fast_io;
    
    cin >> n >> m >> k;
    for(ll i = 1; i <= k; i++){
    	ll x1, x2, y1, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	vec[x1].pb(i);
    	cev[x2].pb(i);
    	p[i] = Mp(y1, y2);
	}
	p[k + 1] = Mp(m, m);
	vec[n + 1].pb(k + 1);
	dp[0] = 1;
	st.insert(Mp(1, 0));
	s.insert(Mp(0, 0));
	upd(1, dp[0]);
	for(ll i = 1; i <= n + 1; i++){
		for(ll j : vec[i]){
			auto it = s.upper_bound(Mp(p[j].S + 1, inf));
			it--;
			ll x = min(p[j].S, it->S);
			dp[j] = get(p[j].S) - get(x);
			if(i == 1) dp[j] = 0;
			if(dp[j] < 0) dp[j] += mod;
		}
		for(ll j : cev[i - 1]){
			s.erase(p[j]);
		}
		for(ll j : vec[i]){
			auto it = st.lower_bound(Mp(p[j].F, -inf));
			while(it != st.end() && it->F <= p[j].S){
				upd(it->F, -dp[it->S]);
				it = st.erase(it);
			}
			s.insert(p[j]);
		}
		for(ll j : vec[i]){
			auto it = s.lower_bound(Mp(p[j].S + 1, -inf));
			if(it != s.end() && it->F == p[j].S + 1){
				dp[j] = 0;
			}
			st.insert(Mp(p[j].S + 1, j));
			upd(p[j].S + 1, dp[j]);
		}
	}
	cout << dp[k + 1];
 
    return 0;
}