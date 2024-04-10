#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, k;
int b[maxn];
int c[26];
string a[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll ans = 0;
	for (int U = 0; U < n; U++) {
		memset(b, 0, sizeof(b));
		for (int D = U; D < n; D++) {
			for (int i = 0; i < m; i++)
				b[i] += a[D][i] == 'a';
			int L = 0, R = 0;
			int cur = 0;
			for (L = 0; L < m; L++) {
				R = max(R, L);
				while (R < m && cur + b[R] <= k) {
					if (a[U][R] == a[D][R])
						c[a[U][R] - 'a']++;
					cur += b[R++];
				}
				if (b[L] <= k && a[U][L] == a[D][L])
					c[a[U][L] - 'a']--;
				if (b[L] <= k)
					cur -= b[L];
				if (U != D && L != R - 1 && a[U][L] == a[D][L])
					ans += c[a[U][L] - 'a'];
			}
		}
	}

	cout << ans;

	return 0;
}