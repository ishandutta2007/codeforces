// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[200005];
string s;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	cin >> s;

	for (int i=0; i<n-1; i++) {
		int j = i;
		while (j < n-1 && s[j] == '1')
			j++;
		sort(a+i, a+j+1);
		i = j;
	}

	cout << (is_sorted(a, a+n) ? "YES\n" : "NO\n");
}