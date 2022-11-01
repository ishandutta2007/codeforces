#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
pair<int, int> p[maxn]; 
bool tag[maxn];
int tot;

set<pair<int, int> > st;

int fa[maxn]; 

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &p[i].first, &p[i].second);
	for(int i = 1;i < maxn;i++) fa[i] = i;
	sort(p + 1, p + 1 + n);
	for(int i = 1;i <= n;i++) swap(p[i].first, p[i].second);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		set<pair<int, int> >::iterator it = st.lower_bound({p[i].second, 0});
		for(;it != st.end() && it->first < p[i].first;++it){
			int x = find(it->second), y = find(p[i].second);
			if(x == y) return printf("NO"), 0;
			fa[x] = y;
			cnt++;
			if(cnt == n) return printf("NO"), 0;
		}
		st.insert(p[i]);
	}
	printf(cnt == n - 1 ? "YES" : "NO");
}