//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1000;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

bitset<maxn> b[maxn];
int n;

int main(){
	fast_io;

	cin >> n;
	b[0][0] = 1;
	b[1][1] = 1;
	for(int i = 2; i <= n; i++){
		b[i] = (b[i - 1] << 1) ^ b[i - 2];
	}
	cout << n << "\n";
	for(int i = 0; i <= n; i++){
		cout << b[n][i] << " ";
	}
	cout << "\n";
	cout << n - 1 << "\n";
	for(int i = 0; i < n; i++){
		cout << b[n - 1][i] << " ";
	}
	cout << "\n";
	
	return 0;
}