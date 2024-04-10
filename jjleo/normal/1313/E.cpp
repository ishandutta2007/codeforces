#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n, m;
char a[maxn], b[maxn], s[maxn];

int z[maxn], p[maxn];
vector<int> l[maxn], r[maxn];

void Z(char *s, int n){
	z[1] = n;
	for(int i = 2, l = 0, r = 0;i <= n;i++){
		z[i] = i <= r ? min(z[i - l + 1], r - i + 1) : 0;
		while(i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) z[i]++;
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

void exKMP(char *s, char *t, int n, int m){
	Z(t, m);
	for(int i = 1, l = 0, r = 0;i <= n;i++){
		p[i] = i <= r ? min(z[i - l + 1], r - i + 1) : 0;
		while(i + p[i] <= n && p[i] + 1 <= m && s[i + p[i]] == t[p[i] + 1]) p[i]++;
		if(i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
	}
}

struct BIT{
	ll a[maxn];
	inline void add(int x, int y){
		for(;x < maxn;x += x & -x) a[x] += y;
	}
	
	inline ll query(int x){
		ll sum = 0;
		for(;x;x -= x & -x) sum += a[x];
		return sum;
	}
}B[2];

int main(){
	scanf("%d%d%s%s%s", &n, &m, a + 1, b + 1, s + 1);
	exKMP(a, s, n, m);
	for(int i = 1;i <= n;i++) l[p[i]].push_back(i);
	reverse(b + 1, b + 1 + n), reverse(s + 1, s + 1 + m);
	exKMP(b, s, n, m);
	for(int i = 1;i <= n;i++) r[p[n - i + 1]].push_back(i);
	for(int i = 0;i < r[m].size();i++) B[0].add(r[m][i], 1), B[1].add(r[m][i], m - 1);
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		if(m - i > 0) for(int j = 0;j < r[m - i].size();j++) B[0].add(r[m - i][j], 1), B[1].add(r[m - i][j], m - i);
		for(int j = 0;j < l[i].size();j++){
			int cnt = B[0].query(min(n, l[i][j] + m - 2)) - B[0].query(l[i][j] - 1);
		    ll sum = B[1].query(min(n, l[i][j] + m - 2)) - B[1].query(l[i][j] - 1);
		    ans += sum + 1ll * cnt * (min(i, m - 1) - m + 1);
		}
	}
	printf("%lld", ans);
}