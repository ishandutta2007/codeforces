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

int dp[2][2][2][8][8][8];

const int inf = 1e9;

struct ancestor {
	int d1, d2, d;
	int a, b, c;
	int e1, e2;
	int carry;
};

ancestor p[2][2][2][8][8][8];

void parse(vector<int>& a, vector<int>& b, vector<int>& c) {
	string s;
	cin >> s;
	int curr = 0;
	int state = 0;
	for (int i = 0; i <= sz(s); ++i) {
		if (i == sz(s) || s[i] == '+' || s[i] == '=') {
			while (curr) {
				if (state == 0) {
					a.pb(curr % 10);
				} else if (state == 1) {
					b.pb(curr % 10);
				} else {
					c.pb(curr % 10);
				}
				curr /= 10;
			}
			++state;
		} else {
			curr *= 10;
			curr += (s[i] - '0');
		}
	}
}

void update(int newe1, int newe2, int newcarry, int newi, int newj, int newk, int e1, int e2, int carry, int i, int j, int k, int put, int d1, int d2, int d) {
	int val = dp[e1][e2][carry][i][j][k] + put;
	int& x = dp[newe1][newe2][newcarry][newi][newj][newk];
	if (x > val) {
		x = val;
		p[newe1][newe2][newcarry][newi][newj][newk] = {d1, d2, d, i, j, k, e1, e2, carry};
	}
}

void print(vector<int>& a) {
	bool need = false;
	for (int i = 0; i < sz(a); ++i) {
		if (a[i] || need) {
			need = true;
		}
		if (need) {
			cout << a[i];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    vector<int> A, B, C;
    parse(A, B, C);

    for (int i = 0; i <= sz(A); ++i) {
    	for (int j = 0; j <= sz(B); ++j) {
    		for (int k = 0; k <= sz(C); ++k) {
    			for (int e1 = 0; e1 < 2; ++e1) {
    				for (int e2 = 0; e2 < 2; ++e2) {
    					for (int carry = 0; carry < 2; ++carry) {
    						dp[e1][e2][carry][i][j][k] = inf;
    					}
    				}
    			}
    		}
    	}
    }

    dp[0][0][0][0][0][0] = 0;

    for (int i = 0; i <= sz(A); ++i) {
    				for (int j = 0; j <= sz(B); ++j) {
    					for (int k = 0; k <= sz(C); ++k) {

    for (int e1 = 0; e1 < 2; ++e1) {
    	for (int e2 = 0; e2 < 2; ++e2) {
    		for (int carry = 0; carry < 2; ++carry) {
    			
    						for (int attempt = 0; attempt < 2; ++attempt) {
	    						if (dp[e1][e2][carry][i][j][k] == inf) {
	    							continue;
	    						}
	    						int lima = (e1 ? 1 : 10);
	    						int limb = (e2 ? 1 : 10);
	    						for (int d1 = 0; d1 < lima; ++d1) {
	    							for (int d2 = 0; d2 < limb; ++d2) {



	    								int d = (d1 + d2 + carry) % 10;
	    								int newcarry = (d1 + d2 + carry) / 10;



	    								int newi;
	    								int put = 0;
	    								if (i != sz(A) && d1 == A[i]) {
	    									newi = i + 1;
	    								} else {
	    									newi = i;
	    									if (!e1) {
	    										++put;
	    									}
	    								}
	    								int newj;
	    								if (j != sz(B) && d2 == B[j]) {
	    									newj = j + 1;
	    								} else {
	    									newj = j;
	    									if (!e2) {
	    										++put;
	    									}
	    								}
	    								int newk;
	    								if (k != sz(C) && d == C[k]) {
	    									newk = k + 1;
	    								} else {
	    									newk = k;
	    									++put;
	    								}

	    								/*if (e1 == 0 && e2 == 0 && carry == 0 && i == 1 && j == 2 && k == 2 && d1 == 4 && d2 == 2) {
	    									cout << "!" << newi << " " << newj << " " << newk << " " << put << endl;
	    								}*/

	    								update(e1, e2, newcarry, newi, newj, newk, e1, e2, carry, i, j, k, put, d1, d2, d);

	    								if (e1 && !e2) {
    										if (newj == sz(B)) {
    											update(1, 1, newcarry, newi, newj, newk, 1, 0, carry, i, j, k, put, d1, d2, d);
    										}
	    								}

	    								if (!e1 && e2) {
    										if (newi == sz(A)) {
    											update(1, 1, newcarry, newi, newj, newk, 0, 1, carry, i, j, k, put, d1, d2, d);
    										}
	    								}
	    								if (!e1 && !e2) {
    										if (newi == sz(A)) {
    											update(1, 0, newcarry, newi, newj, newk, 0, 0, carry, i, j, k, put, d1, d2, d);
    										}
    										if (newj == sz(B)) {
    											update(0, 1, newcarry, newi, newj, newk, 0, 0, carry, i, j, k, put, d1, d2, d);
    										}
    										if (newi == sz(A) && newj == sz(B)) {
    											update(1, 1, newcarry, newi, newj, newk, 0, 0, carry, i, j, k, put, d1, d2, d);
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
    }

    //cout << dp[0][0][0][2][3][3] << endl;

    int e1 = 1, e2 = 1, carry = 0, i = sz(A), j = sz(B), k = sz(C);
    //cout << "!" << dp[e1][e2][carry][i][j][k] << endl;
    vector<int> a, b, c;
    while (e1 || e2 || carry || i || j || k) {
    	ancestor& s = p[e1][e2][carry][i][j][k];
    	a.pb(s.d1);
    	b.pb(s.d2);
    	c.pb(s.d);
    	e1 = s.e1, e2 = s.e2, carry = s.carry;
    	i = s.a, j = s.b, k = s.c;
    }

    print(a);
    cout << "+";
    print(b);
    cout << "=";
    print(c);
    cout << "\n";

}