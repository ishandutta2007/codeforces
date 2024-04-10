//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
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

int n, k, ps[maxn];
vector<int> vec[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		vec[i].resize(m);
		for(int j = 0; j < m; j++){
			cin >> vec[i][j];
		}
	}
	int l = 1, r = k + 1;
	for(int i = 1; i < n; i++){
		bool f = 0;
		for(int j = 0; j < min(Sz(vec[i]), Sz(vec[i - 1])); j++){
			if(vec[i][j] != vec[i - 1][j]){
				if(vec[i][j] > vec[i - 1][j]){
					ps[vec[i - 1][j] + 1]++;
					ps[vec[i][j] + 1]--;
				}
				else{
					l = max(l, vec[i][j] + 1);
					r = min(r, vec[i - 1][j] + 1);
				}
				f = 1;
				break;
			}
		}
		if(f == 0 && Sz(vec[i]) < Sz(vec[i - 1])){
			cout << -1;
			return 0;
		}
	}
	for(int i = 1; i <= k; i++){
		ps[i] += ps[i - 1];
	}
	for(int i = l; i < r; i++){
		if(ps[i] == 0){
			cout << (k + 1 - i) % k;
			return 0;
		}
	}
	cout << -1;
	
	return 0;
}