//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b, c, k;

int main(){
	fast_io;
	srand(time(NULL));
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll j = 0; j < 50000; j++){
		b = c = 0;
		k = rand() % n;
		for(ll i = 0; i < k; i++){
			if(a[i] > a[k]) b++;
			if(a[i] > -a[k]) c++;
		}
		for(ll i = k + 1; i < n; i++){
			if(a[k] > a[i]) b++;
			if(-a[k] > a[i]) c++;
		}
		if(c < b) a[k] = -a[k];
	}
	
	b = 0;
	
	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j < n; j++){
			if(a[i] > a[j]) b++;
		}
	}
	
	cout << b;
	
	
	return 0;
}