#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int t, n;
int a[maxn], b[maxn], d[maxn];
int A[maxn];
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), A[a[i]] = i;
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &d[i]), vis[i] = false;
		int ans = 1;
		for(int i = 1;i <= n;i++) if(!vis[i]){
			vector<int> v;
			int x = i;
			while(!vis[x]){
				vis[x] = true;
				v.push_back(x);
				x = A[b[x]];
			}
			bool tag = false;
			for(auto x : v) if(d[x] && d[x] != a[x]) tag = true;
			if(v.size() > 1 && !tag){
				for(auto x : v) if(d[x] && d[x] != b[x]) tag = true;
				if(!tag) ans = (ans + ans) % p;
			}
		}
		printf("%d\n", ans);
	}
}