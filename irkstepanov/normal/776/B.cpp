#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool isPrime(int val)
{
	for (int d = 2; d * d <= val; ++d) {
		if (val % d == 0) {
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
	cout.tie(0);

	int n;
	cin >> n;

	if (n <= 2) {
		cout << "1\n";
		for (int i = 0; i < n; ++i) {
			cout << "1 ";
		}
		cout << "\n";
		return 0;
	}

	cout << "2\n";
	for (int i = 2; i <= n + 1; ++i) {
		if (isPrime(i)) {
			cout << "1 ";
		} else {
			cout << "2 ";
		}
	}
	cout << "\n";

}