
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2000500;
ll a[N], ans = 1, n;
int cnt[N/4];
vector<ll> vec;
void div(ll x) {
	vec.clear();
	for (ll i = 1;i * i <= x; i++) {
		if (x % i == 0) {
			vec.push_back(i);
			if (i * i != x) vec.push_back(x / i);
		}
	}
	sort(vec.begin(), vec.end());
	memset(cnt, 0, sizeof cnt);
}

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main() {
	read(n); srand((ll)new char);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int T = 1;T <= 10; T++) {
		int k = (ll) rand() * rand() % n + 1;
		div(a[k]);
		for (int i = 1;i <= n; i++) {
			ll G = gcd(a[i], a[k]);
			int t = lower_bound(vec.begin(), vec.end(), G) - vec.begin();
			cnt[t]++;
		}
		for (int i = 0;i < vec.size(); i++) {
			if (vec[i] <= ans) continue;
			for (int j = i + 1;j < vec.size(); j++)
				if (vec[j] % vec[i] == 0) cnt[i] += cnt[j];
		}
		for (int i = vec.size() - 1;i >= 0; i--) {
			if (vec[i] <= ans) break;
			if (cnt[i] * 2 >= n) ans = vec[i];
		}
	}
	write(ans);
	return 0;
}