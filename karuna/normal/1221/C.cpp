#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q, c, m, x;
int main() {
	cin >> Q;
	while (Q--) {
		cin >> c >> m >> x;

		int lo=0, hi=min(c, m);
		while (lo<hi) {
			int mid = lo+hi+1>>1;
			if (c>=mid && m>=mid && c+m+x-2*mid>=mid)
				lo=mid;
			else hi=mid-1;
		}

		cout << lo << '\n';
	}
}