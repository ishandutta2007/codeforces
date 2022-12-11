#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 6010;

ll cnt[4][4][4][nmax];
int x[nmax];
int y[nmax];

int getmod4(int a) {
	a %= 4;
	if (a < 0) {
		a += 4;
	}
	return a;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
    	cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		int m = __gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4;
    		++cnt[getmod4(x[j] - x[i])][getmod4(y[j] - y[i])][m][i];
    		++cnt[getmod4(x[i] - x[j])][getmod4(y[i] - y[j])][m][j];
    	}
    }

    //cout << "!" << cnt[0][0][2][0] << endl;

    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
    	for (int x1 = 0; x1 < 4; ++x1) {
    		for (int y1 = 0; y1 < 4; ++y1) {
    			for (int x2 = 0; x2 < 4; ++x2) {
    				for (int y2 = 0; y2 < 4; ++y2) {
    					int b3 = __gcd(abs(x1 - x2), abs(y1 - y2)) % 4; // TODO
    					if (b3 & 1) {
    						continue;
    					}
    					int A = getmod4(x1 * y2 - x2 * y1);
						for (int b1 = 0; b1 < 4; b1 += 2) {
							for (int b2 = 0; b2 < 4; b2 += 2) {
								int B = (b1 + b2 + b3) % 4;
								if (A == B) {
									if (x1 == x2 && y1 == y2 && b1 == b2) {
										ll z = cnt[x1][y1][b1][i];
										/*if (z > 1) {
											cout << "!" << z << " " << x1 << " " << y1 << " " << b1 << " " << i << endl;
										}*/
										ans1 += z * (z - 1) / 2;
									} else {
										/*if (i == 0 && cnt[x1][y1][b1][i] && cnt[x2][y2][b2][i]) {
											cout << x1 << " " << y1 << " " << b1 << " " << x2 << " " << y2 << " " << b2 << "\n";
										}*/
										if (x1 < x2 || (x1 == x2 && y1 < y2) || (x1 == x2 && y1 == y2 && b1 < b2)) {
											ans1 += cnt[x1][y1][b1][i] * cnt[x2][y2][b2][i];
										}
									}
								}
							}
						}

						for (int b1 = 1; b1 < 4; b1 += 2) {
							for (int b2 = 1; b2 < 4; b2 += 2) {
								int B = (b1 + b2 + b3) % 4;
								if (A == B) {
									if (x1 == x2 && y1 == y2 && b1 == b2) {
										ll z = cnt[x1][y1][b1][i];
										ans2 += z * (z - 1) / 2;
									} else {
										if (x1 < x2 || (x1 == x2 && y1 < y2) || (x1 == x2 && y1 == y2 && b1 < b2)) {
											ans2 += cnt[x1][y1][b1][i] * cnt[x2][y2][b2][i];
										}										
									}
								}
							}
						}
    				}
    			}
    		}
    	}
    }

    assert(ans1 % 3 == 0);
    cout << ans1 / 3 + ans2 << "\n";

}