#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t, n, x, y;
int fa[maxn];
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> v;
		v.push_back(0);
		for(int i = 1;i < n;i++){
			int l = -1, r = v.size() - 1, mid;
			while(l < r){
				mid = (l + r >> 1) + 1;
				printf("1 %d %d\n", i, v[mid]), fflush(stdout);
				scanf("%d", &x);
				if(x) r = mid - 1;
				else l = mid;
			}
			v.insert(v.begin() + l + 1, i);
		}
		for(int i = 0;i < n;i++) fa[i] = i;
		x = n - 1;
		for(int i = n - 1;~i;i--){
			x = min(x, i);
			while(x){
				printf("2 %d %d ", v[i], x);
				for(int j = 0;j <= x - 1;j++) printf("%d ", v[j]);
				puts(""), fflush(stdout);
				scanf("%d", &y);
				if(y) fa[--x] = fa[i]; 
				else break;
			}
			if(!x) break;
		}
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) a[v[i]][v[j]] = fa[i] <= fa[j];
		puts("3"), fflush(stdout);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++) printf("%d", a[i][j]);
			puts(""), fflush(stdout);
		} 
		scanf("%d", &x);
	}
}