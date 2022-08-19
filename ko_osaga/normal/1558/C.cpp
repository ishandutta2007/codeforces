#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 4000005;
int mod;

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

vector<int> ans;
int n, a[MAXN];

void Reverse(int x){
	reverse(a + 1, a + x + 1);
	ans.push_back(x);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans.clear();
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for(int i = n; i >= 2; i -= 2){
			int posEv = find(a + 1, a + n + 1, i - 1) - a;
			int posOd = find(a + 1, a + n + 1, i) - a;
			if(posEv % 2 == 1 || posOd % 2 == 0){
				break;
			}
			if(posEv < posOd){
				Reverse(posOd);
				posEv = find(a + 1, a + n + 1, i - 1) - a;
				Reverse(posEv - 1);
				Reverse(posEv + 1);
				Reverse(3);
				Reverse(i);
			}
			else{
				Reverse(posOd);
				Reverse(posEv - 1);
				Reverse(posEv + 1);
				Reverse(3);
				Reverse(i);
			}
		}
		if(!is_sorted(a + 1, a + n + 1)) puts("-1");
		else{
			printf("%d\n", sz(ans));
			for(auto &x : ans) printf("%d ", x);
		
		puts("");
		}
		ans.clear();
	}
}