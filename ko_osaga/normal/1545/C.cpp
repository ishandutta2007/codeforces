#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 505;

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

vector<int> val[MAXN][MAXN];
vector<int> gph[2*MAXN];
vector<pi> event[MAXN*2];
int col[MAXN*2];
int cnt[MAXN][MAXN];

void dfs(int x, int c){
	if(col[x]){
		assert(col[x] == c);
		return;
	}
	col[x] = c;
	for(auto &i : gph[x]) dfs(i, 3-c);
}

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		int n; scanf("%d",&n);
		for(int i = 1; i <= 2*n; i++){
			for(int j = 0; j < n; j++){
				int x; scanf("%d",&x);
				val[x][j].push_back(i);
				event[i].emplace_back(x, j);
			}
		}
		queue<int> que;
		auto enque = [&](int x, int c){
			if(col[x] == 0){
				col[x] = c;
				que.push(x);
			}
		};
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < n; j++){
				if(sz(val[i][j]) == 1){
					enque(val[i][j][0], 1);
				}
				cnt[i][j] = sz(val[i][j]);
			}
		}
		while(sz(que)){
			int x = que.front(); que.pop();
			if(col[x] == 1){
				for(auto &[i, j] : event[x]){
					cnt[i][j] = 0;
					for(auto &y : val[i][j]){
						enque(y, 3 - col[x]); 
					}
				}
			}
			if(col[x] == 2){
				for(auto &[i, j] : event[x]){
					cnt[i][j]--;
					if(cnt[i][j] == 1){
						for(auto &y : val[i][j]){
							enque(y, 3 - col[x]); 
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < n; j++){
				if(cnt[i][j] == 2){
					vector<int> qq;
					for(auto &x : val[i][j]){
						if(col[x] == 0) qq.push_back(x);
					}
					gph[qq[0]].push_back(qq[1]);
					gph[qq[1]].push_back(qq[0]);
				}
			}
		}
		{
			vector<int> v0, v1;
			for(int i = 1; i <= n*2; i++){
				if(col[i] == 1) v0.push_back(i);
				if(col[i] == 2) v1.push_back(i);
				col[i] = 0;
			}
			for(auto &i : v0){
				if(col[i] == 0) dfs(i, 1);
			}
			for(auto &i : v1){
				if(col[i] == 0) dfs(i, 2);
			}
		}
		mint ret = 1;
		for(int i = 1; i <= n*2; i++){
			if(!col[i]){
				dfs(i, 1);
				ret *= mint(2);
			}
		}
		cout << ret << endl;
		for(int i = 1; i <= 2*n; i++){
			if(col[i] == 1) printf("%d ", i);
		}
		for(int i= 1; i <= 2*n; i++){
			col[i] = 0;
			gph[i].clear();
			event[i].clear();
		}
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				val[i][j].clear();
				cnt[i][j] = 0;
			}
		}
		cout << endl;
	}
}