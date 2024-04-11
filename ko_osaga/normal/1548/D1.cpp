#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 6005;
const int mod = 1e9 + 7;

template<typename T>
T gcd(const T &a, const T &b) {
    return b == T(0) ? a : gcd(b, a % b);
}

struct mint {
    int val;
    mint() { val = 0; }
    mint(const lint& v) {
        val = (-mod <= v && v < mod) ? v : v % mod;
        if (val < 0) val += mod;
    }

    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
    friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
    friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

    mint operator-() const { return mint(-val); }
    mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
    mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
    mint& operator*=(const mint& m) { val = (lint)val*m.val%mod; return *this; }
    friend mint ipow(mint a, lint p) {
        mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};

	pi a[MAXN];
int solve(int i, int j, int k){
	int v1 = gcd(a[i].first - a[j].first, a[i].second - a[j].second);
	int v2 = gcd(a[k].first - a[j].first, a[k].second - a[j].second);
	int v3 = gcd(a[i].first - a[k].first, a[i].second - a[k].second);
	v1 &= 1;
	v2 &= 1;
	v3 &= 1;
	return (v1+v2+v3)%2;
}

lint c1[4][4];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first /= 2;
		a[i].second /= 2;
		a[i].first %= 2;
		a[i].second %= 2;
		c1[a[i].first%2][a[i].second%2]++;
	}
	for(int i = 0; i < 4; i++){
		a[i+n] = pi(i/2, i&1);
	}
	lint cnt = 0; 
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				lint fuck = c1[i/2][i&1] * c1[j/2][j&1] * c1[k/2][k&1];
				cnt += fuck * solve(n+i, n+j, n+k);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cnt -= solve(i, i, j) - solve(i, j, i) - solve(j, i, i);
		}
		cnt += solve(i, i, i) * 2;
	}
	cnt = 1ll * n * (n-1) * (n-2) - cnt;
	cout << cnt / 6 << endl;
}