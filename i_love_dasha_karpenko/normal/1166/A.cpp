#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
struct pp { ll a, b; };

ll n;
map<char,ll> M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		M[s[0]]++;
	}
	ll k,res=0;
	for (auto it = M.begin(); it != M.end(); it++) {
		k = (*it).second;
		ll base = k;
		if (k % 2 != 0)k = k / 2 + 1;
		else k = k / 2;
		res += (k - 1) * k / 2;
		base -= k;
		res += base * (base - 1) / 2;
	}
	cout <<res << endl;
}