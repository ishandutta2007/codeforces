#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sp[10][10], cnt[10][10];

template<class T>
void floyd(T a) {
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			for (int k=0; k<10; k++)
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();

	for (int i=1; i<n; i++) {
		cnt[s[i-1]-'0'][s[i]-'0']++;
	}

	for (int x=0; x<10; x++) {
		for (int y=0; y<10; y++) {
			memset(sp, 63, sizeof(sp));
			for (int i=0; i<10; i++) {
				sp[i][(i+x) % 10] = 1;
				sp[i][(i+y) % 10] = 1;
			}
			floyd(sp);
			ll z = 1-(int)s.size();
			for (int i=0; i<10; i++)
				for (int j=0; j<10; j++) {
					if (cnt[i][j] > 0 && sp[i][j] > 10000)
						z = 1e18;
					z += 1ll * cnt[i][j] * sp[i][j];
				}
			cout << (z > 1e17 ? -1 : z) << " \n"[y == 9]; 
		}
	}
}