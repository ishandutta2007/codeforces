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

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		x += 2;
		for(int i=x; i<MAXN; i+=i&-i) tree[i] += v;
	}
	int query(int x){
		x += 2;
		int ret = 0;
		for(int i=x; i; i-=i&-i)ret += tree[i];
		return ret;
	}
}bit[2];

int x, y;
char str[MAXN];

int main(){
	scanf("%s %d %d",str,&x,&y);
	if(x <= y){
		swap(x, y);
		for(int i=0; str[i]; i++){
			if(str[i] == '0') str[i] = '1';
			else if(str[i] == '1') str[i] = '0';
		}
	}
	int n = strlen(str);
	lint base = 0;
	int c0 = 0, c1 = 0;
	for(int i=0; i<n; i++){
		if(str[i] != '1'){
			base += 1ll * c1 * y;
			c0++;
			bit[0].add(i, 1);
		}
		if(str[i] == '1'){
			base += 1ll * c0 * x;
			c1++;
			bit[1].add(i, 1);
		}
	}
	lint ret = base;
	for(int i=0; i<n; i++){
		if(str[i] == '?'){
			int r1 = bit[1].query(n - 1) - bit[1].query(i);
			int l1 = bit[1].query(i - 1);
			int r0 = bit[0].query(n - 1) - bit[0].query(i);
			int l0 = bit[0].query(i - 1);
			ret -= 1ll * r1 * x + 1ll * l1 * y;
			ret += 1ll * r0 * y + 1ll * l0 * x;
			base = min(base, ret);
			bit[0].add(i, -1);
			bit[1].add(i, 1);
		}
	}
	cout << base << endl;
}