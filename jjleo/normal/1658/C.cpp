#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a[maxn], b[maxn];

bool solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	if(*min_element(a + 1, a + 1 + n) > 1) return false;
	int pos = min_element(a + 1, a + 1 + n) - a;
	int cnt = 0;
	for(int i = pos;i <= n;i++) b[++cnt] = a[i];
	for(int i = 1;i < pos;i++) b[++cnt] = a[i];
	for(int i = 2;i <= n;i++){
		if(b[i] == 1) return false;
		if(b[i - 1] > b[i] || b[i] == b[i - 1] + 1 || b[i] == b[i - 1]) continue;
		return false;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}