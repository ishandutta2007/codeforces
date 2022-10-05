#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 1005;

int n, x[N], y[N];
set<tuple<int, int, int>> ss;
map<tuple<int, int>, ll> mp;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", x + i, y + i);
		for(int j = 0; j < i; j++){
			pii p = pii(x[i], y[i]);
			pii q = pii(x[j], y[j]);
			if(p > q) swap(p, q);
			int a = q.x - p.x;
			int b = q.y - p.y;
			int g = __gcd(a, b);
			a /= g; b /= g;
			int c = b * p.x - a * p.y;
			ss.insert(tie(a, b, c));
		}
	}
	ll r = ss.size();
	r = r * (r - 1) / 2;
	for(auto i : ss){
		int x, y; tie(x, y, ignore) = i;
		mp[tie(x, y)]++;
	}
	for(auto i : mp) r -= i.y * (i.y - 1) / 2;
	printf("%lld\n", r);
}