//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 21e4;
const ll sq = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, w, a[maxn], b[maxn], cnt, d[maxn], ptr[maxn], e[maxn];
vector<ll> g[maxn];
vector<pair<pll, ll> > vec[maxn];
pll ans;

ll cal(pll l, pll r){
	return (l.S - r.S) / (r.F - l.F) - ((l.S - r.S < 0) && (l.S - r.S) % (r.F - l.F));
}

void add(ll i, pll p){
	if(vec[i].empty()){
		vec[i].pb(Mp(p, inf));
		return;
	}
	while(Sz(vec[i]) > 1 && vec[i][Sz(vec[i]) - 2].S >= cal(vec[i].back().F, p)){
		vec[i].pop_back();
	}
	vec[i].back().S = cal(vec[i].back().F, p);
	vec[i].pb(Mp(p, inf));
	return;
}

void add(ll x){
	ll i = 0;
	while((i + 1) * sq <= x){
		e[i]++;
		if(e[i] > vec[i][ptr[i]].S){
			ptr[i]++;
		}
		ans = max(ans, Mp(vec[i][ptr[i]].F.F * e[i] + vec[i][ptr[i]].F.S, vec[i][ptr[i]].F.F));
		i++;
	}
	vec[i].clear();
	for(ll j = i * sq; j < (i + 1) * sq; j++){
		if(j <= x) d[j]++;
		add(i, Mp(j, j * d[j]));
	}
	ptr[i] = 0;
	while(e[i] > vec[i][ptr[i]].S){
		ptr[i]++;
	}
	ans = max(ans, Mp(vec[i][ptr[i]].F.F * e[i] + vec[i][ptr[i]].F.S, vec[i][ptr[i]].F.F));
	return;
}

int main(){
//    fast_io;

	cin >> n >> w;
	cnt = n;
	ll mx = 0;
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		g[b[i]].pb(a[i]);
		mx = max(mx, b[i]);
	}
	for(ll i = 1; i * sq <= maxn; i++){
		vec[i - 1].pb(Mp(Mp(i * sq - 1, 0), inf));
	}
	for(ll c = 0; c <= mx + 1; c++){
		cout << cnt * c * w + ans.F << " " << ans.S << "\n";
		for(ll i : g[c]){
			cnt--;
			add(i);
		}
	}

    return 0;
}