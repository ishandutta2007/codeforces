#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define ll long long
#define ll long long
using namespace std;
const int P = 2520;
ll f[20][2800][60], a[2800];
vector <int> di;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^'0');
    if (f) x=-x;
}

inline int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
inline int lcm(int a, int b) {return b ? a / gcd(a, b) * b : a;}

ll l, r, t, cnt;

ll dfs(int x, int mod, int Lcm, int d) {
	if (!x) return !(mod % Lcm);
	if (!d && f[x][mod][a[Lcm]]) return f[x][mod][a[Lcm]];
	int lim = d ? di[x] : 9; ll res = 0;
	for (int i = 0;i <= lim; i++) 
		res += dfs(x - 1, ((mod * 10) + i) % P, lcm(Lcm, i), d && (i == lim));
	if (d) return res;
	return f[x][mod][a[Lcm]] = res;
}

ll solve(ll x) {
	di.clear();
	di.push_back(-1);
	ll tmp = x;
	while (tmp) di.push_back(tmp % 10), tmp /= 10;
	return dfs(di.size() - 1, 0, 1, 1);
}

int main() {
	read(t);
	for (int i = 1;i <= P; i++) if (P % i == 0) a[i] = ++cnt;
	while (t--) {
		read(l), read(r);
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}