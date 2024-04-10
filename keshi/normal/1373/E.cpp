//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, k, a, b, f, sa[20];

string s, d;

string solve(ll x){
	string ss;
	if(x == 0) return ss;
	if(x <= 8){
		ss += char('0' + x);
		return ss;
	}
	ss = "8";
	x -= 8;
	while(x){
		ss += char('0' + min(x, 9ll));
		x -= min(x, 9ll);
	}
	reverse(ss.begin(), ss.end());
	return ss;
}

bool ismin(string s1, string s2){
	if(s1.size() < s2.size()) return 1;
	if(s1.size() > s2.size()) return 0;
	for(ll i = 0; i < s1.size(); i++){
		if(s1[i] < s2[i]) return 1;
		if(s1[i] > s2[i]) return 0;
	}
	return 1;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		k++;
		s = "";
		for(ll i = 0; i < maxn; i++){
			s += '9';
		}
		for(ll i = 0; i < 10; i++){
			sa[i] = 0;
			for(ll j = 0; j < k; j++){
				sa[i] += (i + j) % 10;
			}
		}
		for(ll i = 0; i < maxn; i++){
			for(ll j = 0; j < 10; j++){
				a = min(10 - j, k);
				b = k - a;
				f = (n - sa[j] - b - 9 * a * i);
				if(f >= 0 && f % k == 0){
					f /= k;
					d = solve(f);
					for(ll o = 0; o < i; o++){
						d += '9';
					}
					d += char('0' + j);
					if(ismin(d, s)) s = d;
				}
			}
		}
		if(s.size() == maxn) s = "-1";
		cout << s << '\n';
	}
	
	return 0;
}