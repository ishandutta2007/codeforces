#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int m, n;
 
int ask(int x) {
	cout << x << '\n' << flush;
	int y;
	cin >> y;
	if (y == 0)
		exit(0);
	return y;
}
 
int t[61]; // ja sam
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> m >> n;
 
	for (int i=0; i<n; i++)
		t[i] = ask(1);
 
	int l = 2, r = m, step = 0;
	while (l <= r) {
		int mid = (l+r) / 2;
 
		int z = ask(mid) * t[step++];
		if (step == n)
			step = 0;
 
		if (z == 1) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
}