#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

vector<ll> a, b;

string s, d;

int main(){
	fast_io;
	
	cin >> s >> d;
	
	n = s.size();
	
	for(ll i = n - 1; i > -1; i--){
		a.pb(s[i] - 'a');
		b.pb(d[i] - 'a');
	}
	
	a[0]++;
	for(ll i = 0; i < n - 1; i++){
		a[i + 1] += a[i] / 26;
		a[i] %= 26;
	}
	if(a == b){
		cout << "No such string";
	}
	else{
		for(ll i = n - 1; i > -1; i--){
			cout << char(a[i] + 'a');
		}
	}
	
	return 0;
}