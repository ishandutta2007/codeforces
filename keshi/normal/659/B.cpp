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

int n, m, mx[maxn][3];
string s, ms[maxn][3];

int main(){
	fast_io;
	memset(mx, -1, sizeof mx);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int j, x;
		cin >> s >> j >> x;
		if(x > mx[j][2]){
			mx[j][2] = x;
			ms[j][2] = s;
		}
		if(mx[j][2] > mx[j][1]){
			swap(mx[j][1], mx[j][2]);
			swap(ms[j][1], ms[j][2]);
		}
		if(mx[j][1] > mx[j][0]){
			swap(mx[j][1], mx[j][0]);
			swap(ms[j][1], ms[j][0]);
		}
	}
	for(int i = 1; i <= m; i++){
		if(mx[i][1] == mx[i][2]){
			cout << "?\n";
		}
		else cout << ms[i][0] << " " << ms[i][1] << "\n";
	}
	
	return 0;
}