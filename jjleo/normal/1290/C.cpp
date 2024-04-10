#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, k;
char s[maxn];
int fa[maxn], val[maxn], siz[maxn], cnt[maxn], sum[maxn];
vector<int> a[maxn];
int x, y;
int ans;

int find(int x){
	return x == fa[x] ? x : find(fa[x]);
}

int get(int x){
	return x == fa[x] ? 0 : val[x] ^ get(fa[x]);
}

void add(int x, int i){
	int val;
	if(sum[x] == -1) val = min(cnt[x], siz[x] - cnt[x]);
	else if(sum[x] == 0) val = cnt[x];
	else val = siz[x] - cnt[x];
	ans += i * val;
}

int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	for(int i = 1;i <= k;i++){
		scanf("%d", &x);
		while(x--){
			scanf("%d", &y);
			a[y].push_back(i);
		}
	}
 	for(int i = 1;i <= k;i++) fa[i] = i, siz[i] = 1, sum[i] = -1;
 	for(int i = 1;i <= n;i++){
 		if(a[i].size() == 2){
 			x = a[i][0], y = a[i][1];
 			int fx = find(x), fy = find(y);
 			if(fx ^ fy){
 				add(fx, -1), add(fy, -1);
 				if(siz[fx] > siz[fy]) swap(x, y), swap(fx, fy);
 				val[fx] = get(x) ^ get(y) ^ (s[i] == '0');
				fa[fx] = fy, siz[fy] += siz[fx];
				cnt[fy] += val[fx] ? siz[fx] - cnt[fx] : cnt[fx];
				if(sum[fx] != -1) sum[fy] = sum[fx] ^ val[fx];
				add(fy, 1);
			}
		}else if(a[i].size() == 1){
			x = a[i][0];
			int fx = find(x);
			add(fx, -1);
			if(sum[fx] == -1) sum[fx] = get(x) ^ (s[i] == '0');
			add(fx, 1);
 		}
		printf("%d\n", ans);
	 }
}