#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int x;
map<int, int> a, b;
int c[maxn];
int d[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		a[x]++;
		d[i] = x;
	} 
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		b[x]++;
		c[i] = x;
	}
	int ans = 1e9;
	for(int x = 1;x <= n;x++){
		int i = (c[x] - d[1] + m) % m;
		bool suc = true;
		for(int y = 1;y <= n;y++){
			int j = d[y];
			if(a[j] ^ b[(j + i) % m]){
				//if(i == 1) printf("%d %d %d--\n", j, a[j], b[(j + 1) % m]);
				suc = false;
				break;
			}
		}
		if(suc){
			ans = min(ans, i);
		}
	}
	printf("%d", ans);
}