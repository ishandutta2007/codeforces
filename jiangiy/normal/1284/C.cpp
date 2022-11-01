#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define xx first
#define yy second

typedef long long ll;

const int N = 250005;

int n, P, fac[N];

int main() {
	cin >> n >> P;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (ll)fac[i - 1] * i % P;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + (ll)fac[i] * (n - i + 1) % P * (n - i + 1) % P * fac[n - i]) % P;
	}
	cout << ans << endl;
}