#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n, m;
int a[maxn], p[maxn];
int cnt[maxn];
vector<int> v;
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), cnt[(i - a[i] + n) % n]++;
		v.clear();
		for(int i = 0;i < n;i++){
			if(n - cnt[i] > 2 * m) continue;
			for(int j = 1;j <= n;j++){
				p[j] = (a[j] + i) % n;
				if(!p[j]) p[j] = n; 
				vis[j] = false;
			}
			int ans = n;
			for(int j = 1;j <= n;j++){
				if(vis[j]) continue;
				int x = j;
				ans--;
				while(!vis[x]){
					vis[x] = true;
					x = p[x];
				}
			}
			//printf("%d %d--\n", i, ans);
			if(ans <= m) v.push_back(i);
		}
		printf("%d", v.size());
		for(int i = 0;i < v.size();i++) printf(" %d", v[i]);puts("");
	}
}