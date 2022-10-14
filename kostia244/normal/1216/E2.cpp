#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll arip(ll n) {
	return (n*(n+1))/2;
}
ll len2(ll x) {
	ll len = 1, cnt = 9, cur = 0, sum = 0;
	while(cnt <= x) {
		sum += cur*cnt;
		sum += arip(cnt)*len;
		cur += cnt*len;
		x-=cnt;
		len++;
		cnt=cnt*10;
	}
	sum += cur*x;
	sum += arip(x)*len;
	return sum;
}

ll solve1(ll n) {
	ll cntless = 0, num = 9, len = 1;
	ll t = 1;
	while(t) {
		t = min(num, ((n+len-1)/len)-1);
		while(t*len >= n) t--;
		n -= len*t;
		num*=10;
		len++;
		cntless += t;
	}
//	cout << cntless << "\n";
	string x = to_string(cntless+1);
	return x[n-1]-'0';
}
void solve() {
	ll n;
	cin >> n;
	ll c=  0;
	for(ll x = 1<<29; x; x>>=1)
		if(len2(c+x)<n)c+=x;
	cout << solve1(n-len2(c)) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x;
	int q;
	cin >> q;
	while(q--) solve();
}