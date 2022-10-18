#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	ll res = 0;
	for (int i = 0; i < 5; i++){
		int j = (5 - i) % 5;
		res += (n / 5 + ((n % 5) >= i && i != 0)) * (m / 5 + ((m % 5) >= j && j != 0));
		//cout << i << ' ' << j << ' ' << (n / 5 + ((n % 5) >= i)) * (m / 5 + ((m % 5) >= j)) << endl;
	}
	cout << res;
}