#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct E{
	int x, y, c, i;
	bool operator<(const E &oth) const {
		return c < oth.c;
	}
};

int n, m;
int p[200010], mc[200010], dep[200010], sp[18][200010], mx[18][200010];
int ans[200010];
E el[200010];
vector<E> e[200010], mt[200010], dt[200010];
map<int, int> *mp[200010], dlt[200010];

int fnd(int x){ return p[x] = (p[x] == x ? x : fnd(p[x])); }
void uni(int x, int y){ p[fnd(x)] = fnd(y); }

void f(int x, int p){
	for(int i = 1; i <= 17; i++){
		sp[i][x] = sp[i - 1][sp[i - 1][x]];
		mx[i][x] = max(mx[i - 1][x], mx[i - 1][sp[i - 1][x]]);
	}
	for(auto &i : mt[x]){
		if(i.y == p) continue;
		sp[0][i.y] = x;
		mx[0][i.y] = i.c;
		dep[i.y] = dep[x] + 1;
		f(i.y, x);
	}
}

void sf(int x, int p){
	vector<pii> v;
	for(auto &i : mt[x]){
		if(i.y == p) continue;
		sf(i.y, x);
		auto t = mp[i.y]->lower_bound(i.c);
		if(t == mp[i.y]->end()) ans[i.i] = -1;
		else ans[i.i] = (t->first) - 1;
		v.push_back({mp[i.y]->size(), i.y});
	}
	sort(v.begin(), v.end(), greater<pii>());
	if(v.empty()) mp[x] = new map<int, int>();
	else mp[x] = mp[v[0].second];
	for(int i = 1; i < v.size(); i++){
		for(auto &j : (*mp[v[i].second])){
			(*mp[x])[j.first] += j.second;
		}
	}
	for(auto &i : dlt[x]){
		(*mp[x])[i.first] += i.second;
		if(!((*mp[x])[i.first])) mp[x]->erase(i.first);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 17; i >= 0; i--){
		if(dep[x] - (1 << i) >= dep[y]){
			x = sp[i][x];
		}
	}
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
		if(sp[i][x] != sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

int qry(int x, int y){
	int z = lca(x, y);
	int ret = 0;
	for(int i = 17; i >= 0; i--){
		if(dep[x] - (1 << i) >= dep[z]){
			ret = max(ret, mx[i][x]);
			x = sp[i][x];
		}
		if(dep[y] - (1 << i) >= dep[z]){
			ret = max(ret, mx[i][y]);
			y = sp[i][y];
		}
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1, x, y, c; i <= m; i++){
		scanf("%d%d%d", &x, &y, &c);
		el[i] = {x, y, c, i};
		e[x].push_back({x, y, c, i});
		e[y].push_back({y, x, c, i});
	}
	sort(el + 1, el + m + 1);
	iota(p + 1, p + n + 1, 1);
	for(int i = 1; i <= m; i++){
		int x = el[i].x, y = el[i].y;
		if(fnd(x) == fnd(y)) continue;
		uni(x, y);
		mt[x].push_back({x, y, el[i].c, el[i].i});
		mt[y].push_back({y, x, el[i].c, el[i].i});
		mc[el[i].i] = 1;
	}
	sp[0][1] = 1;
	f(1, 0);
	for(int i = 1; i <= m; i++){
		if(mc[el[i].i]) continue;
		int x = el[i].x, y = el[i].y, c = el[i].c;
		int z = lca(x, y);
		dlt[x][c]++;
		dlt[y][c]++;
		dlt[z][c] -= 2;
		ans[el[i].i] = qry(el[i].x, el[i].y) - 1;
	}
	sf(1, 0);
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
	puts("");
}