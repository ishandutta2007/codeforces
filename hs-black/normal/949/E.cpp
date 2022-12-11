
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

const int N = 400500, delta = 200005;
vector<int> vnw, ans;
int a[N], siz = N, n;
void Unique(vector<int> &v) { v.erase(unique(v.begin(), v.end()), v.end()); }
void dfs (vector<int> v, int dep) {
//	write(v[0]);
	if (vnw.size() >= siz || dep > (1 << 18)) return;
	if (v.size() == 1 && v[0] == 0) return ans = vnw, siz = ans.size(), void();
	int fl = 0;
	for (int x : v) if (x & 1) fl = 1;
	if (!fl) {
		for (int &x: v) x >>= 1; 
		return dfs(v, dep << 1);
	}
	vnw.push_back(-dep);
	vector<int> tmp = v;
	for (int &x: tmp) (x & 1) ? x = (x + 1) >> 1 : x = x >> 1;
	Unique(tmp);
	dfs(tmp, dep << 1);
	vnw[vnw.size() - 1] = dep;
	tmp = v;
	for (int &x: tmp) (x & 1) ? x = (x - 1) >> 1 : x = x >> 1;
	Unique(tmp);
	dfs(tmp, dep << 1);
	vnw.pop_back();
}

int main() {
	read(n); vector<int> res;
	for (int i = 1;i <= n; i++) 
		read(a[i]), res.push_back(a[i]);
	sort(res.begin(), res.end()), Unique(res);
	dfs(res, 1); write(ans.size()); for (int x: ans) write(x, ' ');
	return 0;
}