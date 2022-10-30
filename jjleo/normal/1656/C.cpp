#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

bool solve(){
	scanf("%d", &n);
	bool tag = false;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), tag |= a[i] == 1;
	if(tag){
		sort(a + 1, a + 1 + n);
		for(int i = 1;i < n;i++) if(a[i] + 1 == a[i + 1]) return false;
		return true;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}