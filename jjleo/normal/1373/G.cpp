#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, m, k;
map<pair<int, int>, int> mp;
int x, y;

inline int cal(pair<int, int> p){
	return abs(p.first - k) + p.second;
}

vector<int> v[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		v[x].push_back(d);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
}

set<int> st;
int ans;
vector<int> V[maxn << 2];

void build(int x, int l, int r){
	int Ans = ans;
	for(int i = 0;i < v[x].size();i++){
		int j = *st.lower_bound(v[x][i]);
		st.erase(j);
		V[x].push_back(j);
		ans = max(ans, j);
	}
	if(l == r){
		printf("%d\n", max(ans - n, 0));
	}else{
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
	ans = Ans;
	for(int i = 0;i < V[x].size();i++) st.insert(V[x][i]);
}

int main(){
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		int z = mp[{x, y}];
		if(z){
			mp.erase({x, y});
			modify(1, 1, m, z, i - 1, cal({x, y}));
		}else{
			mp[{x, y}] = i;
		}
	}
	for(map<pair<int, int>, int>::iterator it = mp.begin();it != mp.end();++it){
		modify(1, 1, m, it->second, m, cal(it->first));
	}
	for(int i = 1;i < maxn;i++) st.insert(i);
	build(1, 1, m);
}