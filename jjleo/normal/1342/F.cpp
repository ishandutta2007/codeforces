#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int x, y, z;
};

int t;
int n;
int a[16];
int f[16][16][1 << 16];
int sum[1 << 16];
Node g[16][16][1 << 16];
vector<int> v;

inline void Min(int &x, int y, Node &z, Node p){
	if(y < x) x = y, z = p;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%d", &a[i]);
		for(int i = (1 << n) - 1;~i;i--){
			sum[i] = 0;
			for(int j = 0;j < n;j++){
				if(i & (1 << j)) sum[i] += a[j];
			}
		}
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= n;j++){
				for(int k = (1 << n) - 1;~k;k--){
					f[i][j][k] = 1e9;
				}
			}
		}
		f[0][0][0] = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= n;j++){
				for(int k = (1 << n) - 1;~k;k--){
					if(f[i][j][k] == 1e9) continue;
					//printf("%d %d %d %d--\n", i, j, k, f[i][j][k]);
					int K = k ^ ((1 << n) - 1);
					for(int l = K;l;l = (l - 1) & K){
						if(sum[l] <= f[i][j][k] || !(l >> max(j - 1, 0))) continue;
						int id = __builtin_ctz(l >> max(j - 1, 0)) + max(j - 1, 0);
						//printf("%d %d %d--\n", l, sum[l], id);
						Min(f[i + 1][id + 1][k | l], sum[l], g[i + 1][id + 1][k | l], (Node){j - 1, id, l});
					}
				}
			}
		}
		bool suc = false;
		for(int i = n;i && !suc;i--){
			for(int j = 1;j <= n && !suc;j++){
				if(f[i][j][(1 << n) - 1] == 1e9) continue;
				int k = (1 << n) - 1;
				printf("%d\n", n - i);
				v.clear();
				for(int l = 1;l <= n;l++) v.push_back(l);
				while(i || j || k){
					Node node = g[i][j][k];
					for(int l = 0;l < n;l++){
						if(!((1 << l) & node.z) || (l == node.y)) continue;
						vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), l + 1), it2 = lower_bound(v.begin(), v.end(), node.y + 1); 
						printf("%d %d\n", it1 - v.begin() + 1, it2 - v.begin() + 1);
						v.erase(it1);
					}
					i--, j = node.x + 1, k ^= node.z;
				}
				suc = true;
			}
		}
	}
}