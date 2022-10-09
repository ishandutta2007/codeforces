#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 1000005;

int f[H];

void fadd(int x, int y) {
	for (x++; x < H; x+=x&-x)
		f[x] += y;
}

int fget(int x) {
	int y = 0;
	for (x++; x; x-=x&-x)
		y += f[x];
	return y;
}

int n, m;
basic_string<pair<int*, int>> q[H];
basic_string<int> u[H];
int ans[H], b[H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		u[r] += l;
	}
	
	for (int i=0; i<m; i++) {
		int k;
		cin >> k;
		b[0] = 0;
		b[k+1] = 1000001;
		for (int j=1; j<=k; j++)
			cin >> b[j];
		for (int j=0; j<=k; j++) {
			q[b[j+1]-1] += make_pair(ans+i, b[j]+1);
		}
	}

	for (int i=0; i<H; i++) {
		for (int l : u[i]) {
			fadd(l, 1);
		}
		for (auto [p, l] : q[i]) {
			*p += fget(H-3) - fget(l-1);
		}
	}
	
	for (int i=0; i<m; i++)
		cout << n - ans[i] << '\n';
}