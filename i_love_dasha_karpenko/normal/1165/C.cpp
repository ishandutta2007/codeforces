#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n;
string s="", A;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> A;
	ll pos = 0,len = 0;
	for (int i = 0; i < n; i++) {
		if (pos == 0 && i<n-1) {
			if (A[i] != A[i + 1]) {
				s += A[i];
				pos ^= 1;
			}
		}
		else {
			pos ^= 1;
			s += A[i];
		}
	}
	if (s.length() % 2 != 0) {
		s.erase(s.begin() + s.length() - 1);
	}
	cout << n - s.length() << endl;
	cout << s << endl;
}