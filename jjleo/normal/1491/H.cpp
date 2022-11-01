#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, sn, q;
int a[maxn], f[maxn], tag[maxn], cnt[maxn];
int opt, x, y, z;

int lca(int x, int y){
	while(1){
		if(x / sn == y / sn && f[x] == f[y]) break;
		if(x < y) swap(x, y);
		x = f[x], x = max(0, a[x] - tag[x / sn]);
	}
	while(x ^ y){
		if(x < y) swap(x, y);
		x = max(0, a[x] - tag[x / sn]);
	}
	return x;
}

int main(){
	scanf("%d%d", &n, &q);
	sn = (int)sqrt(n);
	for(int i = 1;i < n;i++) scanf("%d", &a[i]), a[i]--;
	for(int i = 0;i < n;i++){
		if(i == 0 || a[i] / sn != i / sn) f[i] = i;
		else f[i] = f[a[i]];
	}
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d%d", &x, &y, &z), x--, y--;
			if(x / sn == y / sn){
				for(int i = x;i <= y;i++){
					a[i] = max(0, a[i] - z);
					int A = max(0, a[i] - tag[i / sn]);
					if(i == 0 || A / sn != i / sn) f[i] = i;
					else f[i] = f[A];
				}
				for(int i = y + 1;i / sn == y / sn;i++){
					int A = max(0, a[i] - tag[i / sn]);
					if(A / sn != i / sn) f[i] = i;
					else f[i] = f[A];
				}
				continue;
			}
			for(int i = x;i / sn == x / sn;i++){
				a[i] = max(0, a[i] - z);
				int A = max(0, a[i] - tag[i / sn]);
				if(i == 0 || A / sn != i / sn) f[i] = i;
				else f[i] = f[A];
			}
			for(int i = x / sn + 1;i < y / sn;i++){
				if(cnt[i] > sn){
					tag[i] = min(n, tag[i] + z);
					continue;
				}
				cnt[i]++;
				for(int j = i * sn;j / sn == i;j++){
					a[j] = max(0, a[j] - z);
					if(a[j] / sn != i) f[j] = j;
					else f[j] = f[a[j]];
				}
			}
			for(int i = y / sn * sn;i <= y;i++){
				a[i] = max(0, a[i] - z);
				int A = max(0, a[i] - tag[i / sn]);
				if(i == 0 || A / sn != i / sn) f[i] = i;
				else f[i] = f[A];
			}
			for(int i = y + 1;i / sn == y / sn;i++){
				int A = max(0, a[i] - tag[i / sn]);
				if(A / sn != i / sn) f[i] = i;
				else f[i] = f[A];
			}
		}else{
			scanf("%d%d", &x, &y);
			printf("%d\n", lca(--x, --y) + 1);
		}
	}
}