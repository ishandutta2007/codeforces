#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, m;
int a[maxn];
int x, y;
vector<int> v[maxn];
int t[maxn], b[maxn];

inline bool cmp(int x, int y){
	return t[x] < t[y];
}

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) scanf("%d", &t[i]), b[i] = i;
	sort(b + 1, b + 1 + n, cmp);
	for(int i = 1;i <= n;i++){
		if(a[b[i]] == t[b[i]] - 1){
			for(int j = 0;j < v[b[i]].size();j++){
				if(a[v[b[i]][j]] == t[b[i]] - 1) a[v[b[i]][j]] = t[b[i]];
			}
		}else{
			return printf("-1"), 0;
		}
	} 
	for(int i = 1;i <= n;i++) printf("%d ", b[i]);
}