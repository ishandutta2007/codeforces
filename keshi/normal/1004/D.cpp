//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, a, x, y, s, b[maxn], c[maxn], d1, d2, d3;

bool f;

int main(){
	fast_io;
	
	cin >> t;
	
	for(ll i = 0; i < t; i++){
		cin >> a;
		b[a]++;
	}
	
	if(b[0] != 1){
		cout << -1;
		return 0;
	}
	
	if(t == 1){
		cout << "1 1\n1 1";
		return 0;
	}
	
	c[1] = 4 - b[1];
	if(c[1] && x == 0) x = 1;
	for(ll i = 2; i < t; i++){
		c[i] = 4 + b[i - 1] - b[i];
		if(c[i] && x == 0) x = i;
	}
	
	if(*min_element(c, c + t) < 0){
		cout << -1;
		return 0;
	}
	
	for(ll i = 2 * x - 1; i <= t; i++){
		if(t % i) continue;
		for(ll j = x; j < t; j++){
			c[j] -= 2;
		}
		c[x]++;
		for(ll j = i + 1 - x; j < t; j++){
			c[j] -= 2;
		}
		c[i + 1 - x]++;
		y = 0;
		for(ll j = 1; j < t; j++){
			if(c[j]){
				y = j;
				break;
			}
		}
		s = 0;
		f = 1;
		for(ll j = 1; j < t; j++){
			if(j == y) s++;
			if(j == y + 1) s++;
			if(j == t / i + 1 - y) s++;
			if(j == t / i + 2 - y) s++;
			if(j == x + y) s--;
			if(j == i + 1 - x + y) s--;
			if(j == x + t / i + 1 - y) s--;
			if(j == i + 1 - x + t / i + 1 - y) s--;
			if(s != c[j]) f = 0;
		}
		if(f){
			cout << i << " " << t / i << '\n';
			cout << x << " " << y << '\n';
			return 0;
		}
		for(ll j = x; j < t; j++){
			c[j] += 2;
		}
		c[x]--;
		for(ll j = i + 1 - x; j < t; j++){
			c[j] += 2;
		}
		c[i + 1 - x]--;
	}
	
	cout << -1;
	
	return 0;
}