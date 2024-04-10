#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n,t;
string s;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 0; h < t; h++) {
		cin >> n;
		cin >> s;
		ll res = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '8') {
				res = i;
				break;
			}
		}
		if (res==-1 || (s.length() - res) < 11) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}