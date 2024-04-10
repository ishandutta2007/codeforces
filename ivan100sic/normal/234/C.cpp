#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int neg[100005], pos[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	ifs >> n;
	for (int i=1; i<=n; i++) {
		ifs >> a[i];
		pos[i] = pos[i-1] + (a[i] >= 0);
	}
	int sol = n+1;
	for (int i=n; i>=1; i--) {
		neg[i] = neg[i+1] + (a[i] <= 0);
		if (i < n) {
			sol = min(sol, pos[i] + neg[i+1]);
		}
	}
	ofs << sol << '\n';
}