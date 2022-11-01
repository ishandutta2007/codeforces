#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, q;
set<int> st[maxn];
int x, y, opt;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		st[x].insert(y), st[y].insert(x);
	}
	scanf("%d", &q);
	int ans = 0;
	for(int i = 1;i <= n;i++) if(st[i].empty() || *st[i].rbegin() < i) ans++;
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			if(st[x].empty() || *st[x].rbegin() < x) ans--;
			if(st[y].empty() || *st[y].rbegin() < y) ans--;
			st[x].insert(y), st[y].insert(x);
			if(st[x].empty() || *st[x].rbegin() < x) ans++;
			if(st[y].empty() || *st[y].rbegin() < y) ans++;
		}else if(opt == 2){
			scanf("%d%d", &x, &y);
			if(st[x].empty() || *st[x].rbegin() < x) ans--;
			if(st[y].empty() || *st[y].rbegin() < y) ans--;
			st[x].erase(y), st[y].erase(x);
			if(st[x].empty() || *st[x].rbegin() < x) ans++;
			if(st[y].empty() || *st[y].rbegin() < y) ans++;
		}else printf("%d\n", ans);
	}
}