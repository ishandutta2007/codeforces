#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

const int mod = 998244353; //1e9 + 7;//998244353;

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
    operator int64_t() const {return val; }
};

char str[MAXN];
int cnt[30];

int main(){
	lint n, t; cin >> n >> t >> str;
	reverse(str, str + n);
	t -= (1 << (str[0] - 'a'));
	t += (1 << (str[1] - 'a'));
	for(int i=2; i<n; i++){
		cnt[str[i] - 'a']++;
		t += (1 << (str[i] - 'a'));
	}
	if(t % 2 == 1 || t < 0){
		puts("No");
		return 0;
	}
	t >>= 1;
	for(int i=0; i<26; i++){
		if(t & 1){
			if(cnt[i] == 0){
				puts("No");
				return 0;
			}
			t -= 1;
			cnt[i] -= 1;
		}
		cnt[i + 1] += cnt[i] / 2;
		t >>= 1;
	}
	if(t <= cnt[26]){
		puts("Yes");
	}
	else puts("No");
}