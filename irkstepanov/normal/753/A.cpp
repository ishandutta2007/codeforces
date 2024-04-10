#include <bits/stdc++.h>
#include <cstdint>
#include <inttypes.h>
#include <stdint.h>

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

	int n;
	cin >> n;

	int sum = 0;
	int k;
	for (k = 1; k + sum <= n; ++k) {
		sum += k;
	}
	--k;

	cout << k << "\n";
	for (int i = 1; i < k; ++i) {
		cout << i << " ";
	}
	cout << k + n - sum << "\n";

}