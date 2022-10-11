//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c;
string s, t, g1, g2;
vector<ll> ans;

void f1(ll x){
	reverse(s.begin(), s.begin() + x);
	ans.pb(n - x);
	return;
}
void f2(ll x){
	reverse(s.begin() + x, s.end());
	ans.pb(x);
}

int main(){
	ll x;
	fast_io;
	
	cin >> n >> s >> t;
	g1 = s;
	g2 = t;
	sort(g1.begin(), g1.end());
	sort(g2.begin(), g2.end());
	if(g1 != g2){
		cout << -1;
		return 0;
	}
	g1 = g2 = "";
	for(ll i = 0; i < (n + 1) / 2; i++){
		g1 += t[i];
	}
	for(ll i  = (n + 1) / 2; i < n; i++){
		g2 += t[i];
	}
	reverse(g1.begin(), g1.end());
	for(ll i = 0; i < n / 2; i++){
		for(ll j = c; j < n; j++){
			if(s[j] == g1[i]) x = j;
		}
		f1(x);
		f2(x - c);
		c++;
		for(ll j = 0; j + c < n; j++){
			if(s[j] == g2[i]) x = j;
		}
		f1(0);
		f2(x + 1);
		f1(x + c + 1);
		f2(n);
		c++;
	}
	if(n & 1){
		for(ll j = c; j < n; j++){
			if(s[j] == g1[g1.size() - 1]) x = j;
		}
		f1(x);
		f2(x - c);
		c++;
	}
	cout << ans.size() << '\n';
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}