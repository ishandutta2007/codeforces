//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll n, k, a[maxn], ans, fen1[maxn], fen2[maxn];
vector<pll> vec;

void upd1(ll x, ll y){
	for(x += 5; x > 0; x -= x & -x){
		fen1[x] += y;
	}
	return;
}
ll get1(ll x){
	ll y = 0;
	for(x += 5; x < maxn; x += x & -x){
		y += fen1[x];
	}
	return y;
}
void upd2(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen2[x] += y;
	}
	return;
}
ll get2(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen2[x];
	}
	return y;
}
ll get(ll x){
	return get1(x + 1) + get2(x - 1);
}

int main(){
    fast_io;
    
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
    	vec.pb(Mp(a[i], i));
	}
	sort(all(vec));
	ll c = 1;
	for(ll i = 0; i < n; i++){
		if(i > 0 && vec[i].F != vec[i - 1].F) c++;
		a[vec[i].S] = c;
	}
	a[0] = 0;
	ll r = n + 1, s = 0;
	while(r > 1 && s + get(a[r - 1]) <= k){
		s += get(a[r - 1]);
		upd2(a[r - 1], 1);
		r--;
	}
	for(ll i = 1; i < n; i++){
		s += get(a[i]);
		upd1(a[i], 1);
		while(r == i || (r < n && s > k)){
			s -= get(a[r]);
			upd2(a[r], -1);
			r++;
		}
		if(s > k) continue;
		ans += n - r + 1;
	}
	cout << ans << "\n";
 
    return 0;
}