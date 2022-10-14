// Problem: F. Make Symmetrical
// Contest: Codeforces - AIM Tech Round 5 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1028/problem/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};
using gp_map = __gnu_pbds::gp_hash_table<int, int, chash>;
const int C = 120200;
gp_map ans[C];
int cnt = 0;
void upd_line(int x, int y, int d) {
	int g = __gcd(x, y);
	x /= g, y /= g;
	ans[x][y]+=d;
}
int get_line(int x, int y) {
	int g = __gcd(x, y);
	x /= g, y /= g;
	return cnt-ans[x][y];
}
struct Block {
	vector<array<int, 2>> vals;
	void add(array<int, 2> x) {
		cnt++;
		upd(x, 1);
		vals.push_back(x);
	}
	void rem(array<int, 2> x) {
		cnt--;
		vals.erase(find(all(vals), x));
		upd(x, -1);
	}
	void upd(array<int, 2> x, int d) {
		upd_line(x[0], x[1], d);
		for(auto [a, b] : vals)
			upd_line(x[0]+a, x[1]+b, d*2);
	}
};
map<ll, Block> bl;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	for(int t, x, y, i = 0; i < n; i++) {
		cin >> t >> x >> y;
		if(t == 3)
			cout << get_line(x, y) << '\n';
		else if(t == 1)
			bl[x*1ll*x + y*1ll*y].add({x, y});
		else	
			bl[x*1ll*x + y*1ll*y].rem({x, y});
	}
}