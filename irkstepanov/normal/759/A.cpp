#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = 1e18;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}

	vector<char> used(n, false);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int curr = i;
			++cnt;
			used[curr] = true;
			while (!used[p[curr]]) {
				curr = p[curr];
				used[curr] = true;
			}
		}
	}

	int ans = 0;
	if (cnt > 1) {
		ans = cnt;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		sum ^= b;
	}
	if (sum == 0) {
		++ans;
	}
	cout << ans << "\n";

}