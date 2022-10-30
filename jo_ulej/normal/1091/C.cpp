#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

typedef pair<int, int> point;

const ll mod = 1e7 + 9;

set<ll> answer;
ll n;

void process(ll k)
{
	answer.insert((n * (n - k + 2)) / (2 * k));
}

void solve()
{
	cin >> n;

	//answer.insert(1);
	//answer.insert(n * (n + 1) / 2);

	for(ll i = 1; i * i <= n; ++i)
		if(n % i == 0)
			process(i), process(n / i);

	for(auto el: answer)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}