#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;

int n, m;
vector<int> v[maxn];
int k, x;
int a[maxn];
int ans[maxn], cnt[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) v[i].clear();
		for(int i = 1;i <= n;i++) a[i] = cnt[i] = 0;
		for(int i = 1;i <= m;i++){
			scanf("%d", &k);
			while(k--){
				scanf("%d", &x);
				v[i].push_back(x), a[x]++;
			}
			if(v[i].size() == 1){
				cnt[v[i][0]]++;
				ans[i] = v[i][0];
			}
		}
		bool tag = false;
		for(int i = 1;i <= m;i++){
			if(v[i].size() == 1) continue;
			int x = v[i][0];
			for(int j = 1;j < v[i].size();j++){
				if(cnt[v[i][j]] < cnt[x]) x = v[i][j];
			}
			ans[i] = x;
			cnt[x]++;
			/*for(int j = 0;j < v[i].size();j++){
				a[v[i][j]]--;
			}*/
		}
		for(int i = 1;i <= n;i++){
			if(cnt[i] > (m + 1) / 2){
				tag = true;
				break;
			}
		}
		if(tag){
			puts("NO");
		}else{
			puts("YES");
			for(int i = 1;i <= m;i++) printf("%d ", ans[i]);puts("");
		}
	}
}