#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

char a[100005], b[100005];
int n, m;
int l[100005], r[100005];
int main(){
	cin >> (a+1) >> (b+1);
	n = strlen(a+1);
	m = strlen(b+1);
	int p = 1;
	for(int i=1; i<=m; i++){
		while(p <= n && a[p] != b[i]) p++;
		if(p > n) p = 1e9;
		l[i] = p;
		p++;
	}
	p = n;
	r[m+1] = n+1;
	for(int i=m; i; i--){
		while(p >= 1 && a[p] != b[i]) p--;
		if(p <= 0) p = -1e9;
		r[i] = p;
		p--;
	}
	int e = 1;
	int ans = 1e9;
	int st, ed;
	for(int i=0; i<=m; i++){
		e = max(e, i+1);
		while(e <= m && l[i] >= r[e]) e++;
		if(l[i] < r[e] && ans > e - i - 1){
			ans = e - i - 1;
			st = i;
			ed = e;
		}
	}
	if(ans >= m){
		puts("-");
		return 0;
	}
	for(int i=1; i<=st; i++) putchar(b[i]);
	for(int i=ed; i<=m; i++) putchar(b[i]);
}