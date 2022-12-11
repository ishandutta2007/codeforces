#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

bool isPrime(int x)
{
	for (int d = 2; d * d <= x; ++d) {
		if (x % d == 0) {
			return false;
		}
	}
	return true;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int m = 1; m <= 1000; ++m) {
		if (!isPrime(n * m + 1)) {
			cout << m << '\n';
			return 0;
		}
	}

}