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
#define Sz(x) int((x).size())
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

int n, m, ans, cnt;
vector<int> a[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	cnt = n + 1;
	for(int i = 0; i < m; i++){
		int k;
		cin >> k;
		a[i].resize(k);
		int ls = 0, ok = 1;
		for(int j = 0; j < k; j++){
			cin >> a[i][j];
			if(a[i][j] == ls + 1) ls++;
			else ok = 0;
			if(ok) cnt--;
			else if(j) ans++;
		}
	}
	cout << ans + cnt - 1;
	
	return 0;
}