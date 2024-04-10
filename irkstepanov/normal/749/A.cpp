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

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<int> ans;
	if (n & 1) {
		ans.pb(3);
		n -= 3;
	}

	while (n) {
		ans.pb(2);
		n -= 2;
	}

	cout << sz(ans) << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";

}