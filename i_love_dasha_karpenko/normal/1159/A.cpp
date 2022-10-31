#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 10000000000000007
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];

ll n;
string s;
int main() {
	cin >> n >> s;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-')res = max(ll(0), res - 1);
		else res++;
	}
	cout << res << endl;	
}