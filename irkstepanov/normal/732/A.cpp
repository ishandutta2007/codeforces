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

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int k, r;
	cin >> k >> r;

	for (int d = 1; d <= 10; ++d) {
		int s = d * k;
		if (s % 10 == 0) {
			cout << d << "\n";
			return 0;
		}
		if (s >= r) {
			s -= r;
			if (s % 10 == 0) {
				cout << d << "\n";
				return 0;
			}
		}
	}

}