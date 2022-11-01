#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, b[maxn], c[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i <= n + 1;i++) v[i].clear();
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), v[b[i]].push_back(i);
		int x, val;
		for(int i = 1;i <= n;i++){
			if(b[i] == n + 1) x = 0, val = n + 1;
			if(b[i] == 0) x = 1, val = 0;
		}
		int cnt = 0, k = 0;
		while(1){
			int nxt = 0, pos;
			for(auto i : v[val]){
				c[++cnt] = i;
				if(!v[i].empty()){
					nxt = i;
					pos = cnt;
				}
				if(x == 0) k++;
			}
			if(!nxt) break;
			swap(c[cnt], c[pos]);
			x ^= 1, val = nxt;
		}
		printf("%d\n", k);
		for(int i = 1;i <= n;i++) printf("%d ", c[i]);puts("");
	}
}