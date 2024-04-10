//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e2 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a, b, p;

string s;

int main(){
	fast_io;
	
	cin >> k >> a >> b >> s;
	n = s.size();
	
	if(n > k * b || n < a * k){
		cout << "No solution";
		return 0;
	}
	
	for(ll i = 0; i < n % k; i++){
		for(ll j = 0; j < n / k + 1; j++){
			cout << s[p++];
		}
		cout << endl;
	}
	
	for(ll i = 0; i < k - n % k; i++){
		for(ll j = 0; j < n / k; j++){
			cout << s[p++];
		}
		cout << endl;
	}
	
	
	return 0;
}