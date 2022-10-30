#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int a[maxn];

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) a[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}

int n;
char s[maxn];
vector<int> v[26];
int l[26], r[26];
long long ans;

int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 1;i <= n;i++) v[s[i] - 'a'].push_back(i);
	for(int i = 0;i < 26;i++) l[i] = 0, r[i] = (int)v[i].size() - 1;
	for(int i = 1;i < n - i + 1;i++){
		int a = s[i] - 'a', b = s[n - i + 1] - 'a';
		ans += v[b][l[b]] - 1 - query(v[b][l[b]]);
		add(v[b][l[b]++], 1);
		ans += n - v[a][r[a]] - query(n) + query(v[a][r[a]]);
		add(v[a][r[a]--], 1);
	}
	printf("%lld", ans);
}