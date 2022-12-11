#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	ll maxx = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += maxx - a[i];
	}
	cout << sum << "\n";

}