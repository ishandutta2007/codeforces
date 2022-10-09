#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, dx, dy;
int q[1000005];
int s[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> dx >> dy;
	
	for (int i=0, x=0, y=0; i<n; i++, x=(x+dx)%n, y=(y+dy)%n)
		q[x] = y;
	
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		s[(y-q[x]+n) % n]++;
	}
	cout << "0 " << max_element(s, s+n) - s << '\n';
}