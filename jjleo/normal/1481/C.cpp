#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[maxn], b[maxn], c[maxn], d[maxn];
vector<int> v[maxn];
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), v[i].clear(), d[i] = 0;
		for(int i = 1;i <= m;i++) scanf("%d", &c[i]);
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			d[b[i]] = i;
			if(a[i] == b[i]) continue;
			v[b[i]].push_back(i);
			cnt++;
		}
		bool tag = false;
		for(int i = m;i;i--){
			if(v[c[i]].empty()){
				if(i == m){
					if(d[c[i]]) ans[i] = d[c[i]];
					else{
						tag = true;
						break;
					}
				}else{
					ans[i] = ans[i + 1];
				}
			}else{
				ans[i] = v[c[i]].back();
				v[c[i]].pop_back();
				cnt--;
			}
		}
		if(cnt || tag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= m;i++) printf("%d ", ans[i]);
		puts("");
	}
}