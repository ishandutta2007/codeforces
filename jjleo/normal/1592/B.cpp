#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		bool tag = false;
		for(int i = 1;i <= n;i++) if(max(i - 1, n - i) < x && a[i] != b[i]){
			tag = true;
			break;
		}
		puts(tag ? "NO" : "YES");
	}
}