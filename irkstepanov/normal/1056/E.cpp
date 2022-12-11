#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

mt19937 rr(time(0));

int mod1, mod2;

bool isPrime(int x) {
	for (int d = 2; d * d <= x; ++d) {
		if (x % d == 0) {
			return false;
		}
	}
	return true;
}

int getPrime() {
	int x = rr() % int(5e8) + int(5e8);
	while (!isPrime(x)) {
		++x;
	}
	return x;
}

pii operator+(pii a, pii b) {
	a.first += b.first;
	a.second += b.second;
	if (a.first >= mod1) {
		a.first -= mod1;
	}
	if (a.second >= mod2) {
		a.second -= mod2;
	}
	return a;
}

pii operator*(pii a, pii b) {
	a.first = ll(a.first) * b.first % mod1;
	a.second = ll(a.second) * b.second % mod2;
	return a;
}

pii operator-(pii a, pii b) {
	a.first -= b.first;
	a.second -= b.second;
	if (a.first < 0) {
		a.first += mod1;
	}
	if (a.second < 0) {
		a.second += mod2;
	}
	return a;
}

const int nmax = 1e6 + 100;

pii degs[nmax];
pii pref[nmax];

pii get(int l, int r) {
	if (l == 0) {
		return pref[r];
	}
	return pref[r] - pref[l - 1] * degs[r - l + 1];
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    cin >> s >> t;

    mod1 = getPrime();
    mod2 = getPrime();

    degs[0] = {1, 1};
    degs[1] = {rr() % 30 + 30, rr() % 70 + 70};

    for (int i = 2; i < nmax; ++i) {
    	degs[i] = degs[i - 1] * degs[1];
    }

    int n = sz(t);
    for (int i = 0; i < n; ++i) {
    	if (i) {
    		pref[i] = pref[i - 1] * degs[1];
    	}
    	pii tmp = {t[i] - 'a' + 1, t[i] - 'a' + 1};
    	pref[i] = pref[i] + tmp;
    }

    vector<pii> blocks;
    int sum[2] = {0, 0};
    pii lst = {-1, 0};
    for (int i = 0; i < sz(s); ++i) {
    	if (lst.first != s[i] - '0') {
    		if (lst.first != -1) {
    			blocks.pb(lst);
    			sum[lst.first] += lst.second;
    		}
    		lst = {s[i] - '0', 1};
    	} else {
    		++lst.second;
    	}
    }
    blocks.pb(lst);
    sum[lst.first] += lst.second;

    int ans = 0;
    for (int lena = 1; lena * sum[0] < n; ++lena) {
    	int lenb = (n - lena * sum[0]) / sum[1];
    	if (lenb * sum[1] + lena * sum[0] != n) {
    		continue;
    	}
    	int l[2] = {-1, -1};
    	int r[2] = {-1, -1};
    	bool ok = true;
    	int pos = 0;
    	for (pii p : blocks) {
    		int len;
    		if (p.first == 0) {
    			len = lena;
    		} else {
    			len = lenb;
    		}
    		if (p.second > 1) {
    			pii x = get(pos, pos + (p.second - 1) * len - 1);
    			pii y = get(pos + len, pos + p.second * len - 1);
    			if (x != y) {
    				ok = false;
    				break;
    			}
    		}
    		if (l[p.first] == -1) {
    			l[p.first] = pos;
    			r[p.first] = pos + len - 1;
    		} else {
    			pii x = get(l[p.first], r[p.first]);
    			pii y = get(pos, pos + len - 1);
    			if (x != y) {
    				ok = false;
    				break;
    			}
    		}

    		pos += p.second * len;
    	}
    	pii x = get(l[0], r[0]);
    	pii y = get(l[1], r[1]);
    	if (x == y) {
    		ok = false;
    	}
    	if (ok) {
    		++ans;
    	}
    }

    cout << ans << "\n";

}