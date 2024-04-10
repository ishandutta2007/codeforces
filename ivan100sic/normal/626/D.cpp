#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[2005];
ll c1[5005];
ll c2[10005];
ll z[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i] > a[j])
				c1[a[i] - a[j]]++;

	for (int i=0; i<=5000; i++)
		for (int j=0; j<=5000; j++)
			c2[i+j] += c1[i] * c1[j];

	for (int i=1; i<=10000; i++)
		z[i] = z[i-1] + c2[i];

	ll ways=0, good=0;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i] < a[j]) {
				ways += z[10000];
				good += z[a[j] - a[i] - 1];
			}

	cout << setprecision(20) << fixed << (ld)good/ways << '\n';
}