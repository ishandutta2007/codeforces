#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int f[105][105], g[105][105];

int main(){
	scanf("%d", &n);
	vector<int> v;
	int sum = 1;
	for(int i = 1;i < n;i++) if(__gcd(i, n) == 1) v.push_back(i), sum = 1ll * sum * i % n;
	if(sum ^ 1) v.pop_back();
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
	/*
	for(int n = 2;n <= 25;n++){
		vector<int> v;
		for(int i = 0;i < (1 << (n - 1));i++){
			int sum = 1;
			vector<int> w;
			for(int j = 0;j < n - 1;j++){
				if(i & (1 << j)) sum = 1ll * sum * (j + 1) % n, w.push_back(j + 1);
			}
			if(sum == 1 && w.size() > v.size()) v = w; 
		}
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
		
		memset(f, 0x3f, sizeof(f));
		for(int i = 1;i < n;i++){
			for(int j = 0;j < n;j++){
				if(f[i - 1][j] < f[i][j]){
					f[i][j] = f[i - 1][j];
					g[i][j] = -1;
				}
				if(f[i - 1][j] + 1 < f[i][1ll * j * i % n]){
					f[i][1ll * j * i % n] = f[i - 1][j] + 1;
					g[i][1ll * j * i % n] = j;
				}
			}
		}
		int x = 1;
		vector<int> v;
		for(int i = n - 1;i;i--){
			if(g[i][x] == -1) continue;
			x = g[i][x], v.push_back(i);
		}
		for(int i = v.size() - 1;~i;i--) printf("%d ", v[i]);puts("");
		
	}
	*/
}