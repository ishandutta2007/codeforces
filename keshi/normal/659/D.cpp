//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, dr[maxn], ans;
pii a[maxn];

inline int filan(int x){
	if(x == 0) return 0;
	if(x < 0) return -1;
	return 1;
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	for(int i = 0; i < n; i++){
		int x = a[i + 1].F - a[i].F, y = a[i + 1].S - a[i].S;
		for(int j = 0; j < 4; j++){
			if(filan(x) == filan(dx[j]) && filan(y) == filan(dy[j])) dr[i] = j;
		}
	}
	dr[n] = dr[0];
	for(int i = 0; i < n; i++){
		if(dr[i + 1] == ((dr[i] + 3) & 3)) ans++;
	}
	cout << ans;
	
	return 0;
}