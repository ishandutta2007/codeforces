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
const int N = 1e9+1;
using namespace __gnu_pbds;
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
gp_hash_table<int, int, chash> fen;
static inline int F(int v) {
	auto it = fen.find(v);
	if(it == fen.end()) return v&-v;
	return it->second;
}
int lower(int v) {
	int p = 0;
	for(int z = 1<<30; z>>=1;) {
		int t = F(p|z);
		if(v>t)
			v-=t,p|=z;
	}
	return p;
}
int get(int p) {
	p++;
	int ans = 0;
	for(; p; p -= p&-p)
		ans += F(p);
	return ans;
}
void add(int p, int d) {
	p++;
	for(; p <= N; p += p&-p) {
		auto it = fen.find(p);
		if(it == fen.end())
			fen[p] = p&-p;
		fen[p] += d;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	add(0, -1);
	for(int t, k, x = 0; n--;) {
		cin >> t;
		int a = lower(t), b = lower(t+1);
		add(0, 1);
		add(a, -1);
		add(b, -1);
		cin >> k;
		while(k--) {
			cin >> t;
			t = (t+x)%int(1e9+1);
			cout << (x=get(t)) << '\n';
		}
	}
}