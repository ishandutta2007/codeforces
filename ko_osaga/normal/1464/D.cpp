#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;

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
    operator int64_t() const {return val; }
};

int vis[MAXN], p[MAXN];


void solve(){
	int n; scanf("%d", &n);
	for(int i=0; i<=n+1; i++){
		vis[i] = 0;
	}
	for(int i=0; i<n; i++){
		scanf("%d",&p[i]);
		p[i]--;
	}
	{
		mint ret = 1;
		int m = n;
		while(m % 3 != 0){
			m -= 2;
			ret *= mint(2);
		}
		ret *= ipow(mint(3), m / 3);	
		printf("%lld ",(lint)ret);
	}
	vector<int> seq;
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		int l = 0;
		for(int j=i; !vis[j]; j=p[j]){
			l++;
			vis[j] = 1;
		}
		seq.push_back(l);
	}
	int cnt[3] = {};
	for(auto &i : seq){
		cnt[i%3] += 1;
	}
	auto mcc = [&](){
		int maxCommonComp = cnt[0] + min(cnt[1], cnt[2]) + abs(cnt[2] - cnt[1]) / 3;
		return maxCommonComp;
	};
	if(n%3 == 0){
		printf("%d\n", n/3 + sz(seq) - 2 * mcc());
	}
	else if(n%3 == 2){
		int ret = -1e9;
		if(cnt[1] >= 2){
			cnt[1] -= 2;
			ret = max(ret, mcc() + 1);
			cnt[1] += 2;
		}
		if(cnt[2] >= 1){
			cnt[2] -= 1;
			ret = max(ret, mcc() + 1);
			cnt[2] += 1;
		}
		printf("%d\n", (n+1)/3 + sz(seq) - 2 * ret);
	}
	else if(n%3 == 1){
		int ret = -1e9;
		if(cnt[2] >= 2){
			cnt[2] -= 2;
			ret = max(ret, mcc() + 2);
			cnt[2] += 2;
		}
		if(cnt[1] >= 2 && cnt[2] >= 1){
			cnt[1] -= 2;
			cnt[2] -= 1;
			ret = max(ret, mcc() + 2);
			cnt[1] += 2;
			cnt[2] += 1;
		}
		if(cnt[1] >= 4){
			cnt[1] -= 4;
			ret = max(ret, mcc() + 2);
			cnt[1] += 4;
		}
		int dap = (n+2)/3 + sz(seq) - 2 * ret;
		if(cnt[1] >= 1){
			bool justdoit = 0;
			for(auto &i : seq){
				if(i >= 4 && i % 3 == 1) justdoit = 1;
			}
			if(justdoit){
				cnt[1] -= 1;
				dap = min(dap, n/3 + sz(seq) - 2 * (mcc() + 1));
				cnt[1] += 1;
			}
			else{
				cnt[1] -= 1;
				dap = min(dap, n/3 + sz(seq) - 2 * mcc());
				cnt[1] += 1;
			}
		}
		printf("%d\n", dap);
	}
}
int main(){
	int t; scanf("%d",&t); while(t--) solve();
}