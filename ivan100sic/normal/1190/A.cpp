#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k;
int m;
ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin >> a[i];
		a[i]--;
	}
	int sol = 0;
	for (int i=0; i<m; i++) {
		int j = i;
		while (j+1 < n && (a[j+1]-i)/k == (a[i]-i)/k)
			j++;
		sol++;
		i = j;
	}
	cout << sol << '\n';
}