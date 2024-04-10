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

int n, k, a[maxn], b[maxn];
string c[maxn];
ll dp[100][100];

int main(){
	fast_io;
	
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> a[i] >> c[i] >> b[i];
		if(a[i] > b[i]){
			swap(a[i], b[i]);
			if(c[i] != "=") c[i][0] = '>' + '<' - c[i][0];
		}
		a[i]--;
		b[i]--;
	}
	for(int l = 0; l <= n + n; l++){
		dp[0][l] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int l = 0; l + i + i <= n + n; l++){
			int r = l + i + i;
			bool ok = 1;
			for(int j = 0; j < k; j++){
				bool f1 = (l <= a[j] && a[j] < r);
				bool f2 = (l <= b[j] && b[j] < r);
				if(f1 == 1 && f2 == 0){
					if(c[j] != ">" && c[j] != ">=") ok = 0;
				}
				if(f1 == 0 && f2 == 1){
					if(c[j] != "<" && c[j] != "<=") ok = 0;
				}
			}
			if(!ok) continue;
			ok = 1;
			for(int j = 0; j < k; j++){
				if(a[j] == l && b[j] == l + 1){
					if(c[j] == "<" || c[j] == ">") ok = 0;
				}
			}
			if(ok){
				dp[i][l] += dp[i - 1][l + 2];
			}
			ok = 1;
			for(int j = 0; j < k; j++){
				if(a[j] == r - 2 && b[j] == r - 1){
					if(c[j] == "<" || c[j] == ">") ok = 0;
				}
			}
			if(ok){
				dp[i][l] += dp[i - 1][l];
			}
			ok = 1;
			for(int j = 0; j < k; j++){
				if(a[j] == l && b[j] == r - 1){
					if(c[j] == "<" || c[j] == ">") ok = 0;
				}
			}
			if(ok){
				dp[i][l] += dp[i - 1][l + 1];
			}
		}
	}
	cout << dp[n][0] / 3;
	
	return 0;
}