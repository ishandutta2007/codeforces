#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)

const int siz = 40010;

int main(){
	ll n, m, k;
	cin >> n >> m >> k;

	ll nar[siz] = {};
	for (ll i = 0; i < n; ++i)
		cin >> nar[i];
	ll mar[siz] = {};
	for (ll i = 0; i < m; ++i)
		cin >> mar[i];
	
	ll nahead[siz] = {};
	for (ll i = n-1; i >= 0; --i)
		nahead[i] = (nahead[i+1] + nar[i]) * nar[i];
	ll mahead[siz] = {};
	for (ll i = m-1; i >= 0; --i)
		mahead[i] = (mahead[i+1] + mar[i]) * mar[i];

	ll numnum[siz] = {};
	for (ll i = 0; i < n; ++i)
		numnum[nahead[i]]++;
	ll mumnum[siz] = {};
	for (ll i = 0; i < m; ++i)
		mumnum[mahead[i]]++;

	for (ll i = n-1; i > 0; --i)
		numnum[i] += numnum[i+1];
	for (ll i = m-1; i > 0; --i)
		mumnum[i] += mumnum[i+1];

	ll sum = 0;
	for (ll i = 1; i < n+1; ++i)
		if (k % i == 0 && k / i <= m)
			sum += numnum[i] * mumnum[k / i];

	cout << sum << endl;
}