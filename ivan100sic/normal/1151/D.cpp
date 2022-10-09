#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stud {
	ll a, b;
	bool operator< (const stud& q) const {
		return a-b > q.a-q.b;
	}
} a[100005]; int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].a >> a[i].b;
	sort(a, a+n);
	ll z = 0;
	for (int i=0; i<n; i++)
		z += a[i].a * i + a[i].b * (n-i-1);
	cout << z << '\n';
}