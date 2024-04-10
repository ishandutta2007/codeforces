#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], b[maxn];

bool solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n;i++){
		if(a[i] > b[i]) return false;
		if(a[i] == b[i]) continue;
		int j = i + 1;
		if(j > n) j -= n;
		if(b[i] > b[j] + 1) return false;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}