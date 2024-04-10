#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

unordered_map<int, int> p,di;
int get(int x) {
	if (p.find(x) == p.end())return p[x] = x;
	else return p[x];
}
int f(int x) {
	int par = get(x);
	if (x == par)return x;
	else {
		p[x] = f(p[x]);
		di[x] ^= di[par];
		return p[x];
	}
}
void u(int a, int b,int c) {
	int temp;
	di[temp=f(a)] = di[a] ^ di[b] ^ c;
	p[temp] = f(b);
	f(a);
}
int main()
{
	int q,last=0;
	scanf("%d", &q);
	while (q--) {
		int a, b, c, d;
		scanf("%d%d%d", &a, &b, &c);
		b ^= last, c ^= last;
		if (b > c)b ^= c ^= b ^= c;
		c++;
		if (a == 1) {
			scanf("%d", &d);
			d ^= last;
			if (f(b) == f(c))continue;
			u(b, c,d);
		}
		else {
			if (f(b) == f(c))printf("%d\n", last = di[b] ^ di[c]);
			else printf("-1\n"), last = 1;
		}
	}
}