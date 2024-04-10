#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < m;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x % m]++;
		int ans = 0;
		for(int i = 0;i < m;i++){
			int x = (m - i) % m;
			if(i == x){
				if(a[i]) ans++;
			}else if(i > x) break;
			else{
				if(!a[i] && !a[x]) continue; 
				ans += max(1, max(a[i], a[x]) - min(a[i], a[x]));
			}
		}
		printf("%d\n", ans);
	}
}