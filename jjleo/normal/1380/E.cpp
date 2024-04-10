#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

set<pair<int, int> > st[maxn]; 

int n, m, x, y;
int ans;

inline void insert(pair<int, int> p, int i){
	set<pair<int, int> >::iterator it = st[i].lower_bound(p);
	pair<int, int> a = {0, 0}, b = {0, 0};
	if(it != st[i].end()) a = *it;
	if(it != st[i].begin()) b = *prev(it);
	if(a.first && a.first == p.second + 1){
		p.second = a.second;
		st[i].erase(a);
	}
	if(b.second && b.second + 1 == p.first){
		p.first = b.first;
		st[i].erase(b);
	}
	st[i].insert(p);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		insert({i, i}, x);
	}
	for(int i = 1;i <= m;i++){
		ans += st[i].size() - 1;
	}
	for(int i = m;i;i--){
		printf("%d\n", ans + i - 1);
		if(i ^ 1){
			scanf("%d%d", &x, &y);
			ans -= st[x].size() + st[y].size() - 2;
			if(st[x].size() < st[y].size()) swap(st[x], st[y]);
			for(set<pair<int, int> >::iterator it = st[y].begin();it != st[y].end();++it){
				insert(*it, x);
			} 
			//printf("%d--\n", st[x].size() - 1);
			ans += st[x].size() - 1;
			st[y].clear();
		}
	}
}