#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, l, r;
int main() {
	cin >> n >> l >> r;

	cout << (1LL<<l)-1+n-l << ' ';
	cout << (1LL<<r)-1+(1LL<<(r-1))*(n-r);
}