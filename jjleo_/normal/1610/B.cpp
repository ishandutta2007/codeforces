#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n; 
int a[maxn], b[maxn];

bool solve(int x){
	int m = 0;
	for(int i = 1;i <= n;i++) if(a[i] ^ x) b[++m] = a[i];
	for(int i = 1;i < m - i + 1;i++) if(b[i] ^ b[m - i + 1]) return false;
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 1;i < n - i + 1;i++){
			if(a[i] ^ a[n - i + 1]){
				tag = true;
				if(solve(a[i])) tag = false;
				else if(solve(a[n - i + 1])) tag = false;
				break;
			}
		}
		puts(tag ? "NO" : "YES"); 
	}
}