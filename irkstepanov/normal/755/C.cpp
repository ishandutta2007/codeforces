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

	int ans = 0;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (x == i) {
			++ans;
			continue;
		} else {
			s.insert(x);
		}
	}

	cout << ans + sz(s) / 2 << "\n";

}