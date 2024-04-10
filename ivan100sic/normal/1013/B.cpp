#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> mp;
int n, x;
int a[100005];

void sol(int y) {
	cout << y;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}

	// 0?

	for (int i=0; i<n; i++)
		if (mp[a[i]] > 1)
			sol(0);
	
	for (int i=0; i<n; i++) {
		mp[a[i]]--;
		int y = a[i] & x;
		if (mp[y] > 0)
			sol(1);
		mp[a[i]]++;
	}

	mp.clear();
	for (int i=0; i<n; i++)
		if (mp[a[i] & x]++)
			sol(2);

	sol(-1);

}