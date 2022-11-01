#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

struct Node{
	int sum, id;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	if(t[ls(x)].id == t[rs(x)].id){
		t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
		t[x].id = t[ls(x)].id;
	}else{
		t[x].sum = abs(t[ls(x)].sum - t[rs(x)].sum);
		if(t[ls(x)].sum > t[rs(x)].sum) t[x].id = t[ls(x)].id;
		else t[x].id = t[rs(x)].id;
	}
} 

pair<int, int> query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return {t[x].sum, t[x].id};
	int mid = l + r >> 1;
	if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
	if(mid >= rr) return query(ls(x), l, mid, ll, rr);
	pair<int, int> L = query(ls(x), l, mid, ll, rr), R = query(rs(x), mid + 1, r, ll, rr), ans;
	if(L.second == R.second){
		ans = {L.first + R.first, L.second};
	}else{
		ans.first = abs(L.first - R.first);
		if(L.first > R.first) ans.second = L.second;
		else ans.second = R.second;
	}
	return ans;
} 

int a[maxn];
vector<int> v[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = 1, t[x].id = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, q;
int l, r;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v[a[i]].push_back(i);
	build(1, 1, n); 
	while(q--){
		scanf("%d%d", &l, &r);
		int x = query(1, 1, n, l, r).second;
		int sum = upper_bound(v[x].begin(), v[x].end(), r) - lower_bound(v[x].begin(), v[x].end(), l);
		printf("%d\n", 1 + max(0, sum - (r - l + 1 - sum + 1)));
	}
}