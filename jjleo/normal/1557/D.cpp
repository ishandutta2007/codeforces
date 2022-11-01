#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

struct Node{
	pair<int, int> sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
}

inline void cover(int x, pair<int, int> y){
	t[x].sum = min(t[x].sum, y), t[x].tag = min(t[x].tag, y);
}

inline void down(int x){
	cover(ls(x), t[x].tag), cover(rs(x), t[x].tag);
}

void modify(int x, int l, int r, int ll, int rr, pair<int, int> d){
	if(ll <= l && r <= rr){
		cover(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x); 
}

pair<int, int> query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1;
	pair<int, int> sum = {1e9, 0};
	down(x);
	if(mid >= ll) sum = min(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = min(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

int n, m;
int x, y, z;
vector<pair<int, int> > v[maxn];
vector<int> a;
int last[maxn];
bool tag[maxn];

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		a.push_back(y), a.push_back(z);
		v[x].push_back({y, z}); 
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	m = a.size();
	pair<int, int> ans = {1e9, 0};
	for(int i = 1;i <= n;i++){
		pair<int, int> sum = {1e9, 0};
		for(int j = 0;j < v[i].size();j++){
			v[i][j].first = lower_bound(a.begin(), a.end(), v[i][j].first) - a.begin() + 1;
			v[i][j].second = lower_bound(a.begin(), a.end(), v[i][j].second) - a.begin() + 1;
			pair<int, int> p = query(1, 1, m, v[i][j].first, v[i][j].second);
			sum = min(sum, {p.first + i - 1, p.second});
		}
		for(int j = 0;j < v[i].size();j++){
			modify(1, 1, m, v[i][j].first, v[i][j].second, {sum.first - i, i});
		}
		last[i] = sum.second;
		ans = min(ans, {sum.first + n - i, i});
		//printf("%d %d %d--\n", i, sum.first, sum.second);
	}
	printf("%d\n", ans.first);
	int x = ans.second;
	while(x) tag[x] = true, x = last[x];
	for(int i = 1;i <= n;i++) if(!tag[i]) printf("%d ", i);
}