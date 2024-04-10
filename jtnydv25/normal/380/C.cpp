#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e8;

int tree[N << 2], lazy[N << 2];

void go(int s, int e, int ind){
	tree[ind] += lazy[ind];
	if(s != e){
		lazy[ind << 1] += lazy[ind];
		lazy[ind << 1 | 1] += lazy[ind];
	}
	lazy[ind] = 0;	
}

int n;

void update(int l, int r, int add, int s = 1, int e = n, int ind = 1){
	go(s, e, ind);
	if(l > e || s > r) return;
	if(s >= l && e <= r){
		lazy[ind] += add;
		go(s, e, ind);
		return;
	}
	int mid = (s + e) >> 1;
	update(l, r, add, s, mid, ind << 1);
	update(l, r, add, mid + 1, e, ind << 1 | 1);
	tree[ind] = min(tree[ind << 1], tree[ind << 1 | 1]);
}

int get(int l, int r, int s = 1, int e = n, int ind = 1){
	go(s, e, ind);
	if(s >= l && e <= r) return tree[ind];
	if(s > r || l > e) return INF;
	int mid = (s + e) >> 1;
	return min(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, ind << 1 | 1));
}

vector<pair<int, int>> queries[N];
char s[N];
int l[N], r[N], ans[N], pref[N];
int main(){
	scanf("%s", s);
	n = strlen(s);
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", l + i, r + i);
		queries[r[i]].push_back({l[i], i});
	}

	for(int i = 1; i <= n; i++){
		char c = s[i - 1];
		pref[i] = pref[i - 1];
		if(c == '('){
			pref[i]++;
			update(i, i, pref[i - 1]);
		}
		else{
			update(1, i, 1);
			update(i, i, INF);
		}
		for(auto it : queries[i]){
			int val = get(it.first, i) - pref[it.first - 1];
			if(val > n) val = 0;
			val = min(val, pref[i] - pref[it.first - 1]);
			ans[it.second] = 2 * val;
		}
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}