#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 200005;
const int MAXT = 530000;
const int mod = 1e9 + 7;

struct seg{
	int tree[MAXT], lim;
	void init(int n){
		memset(tree, 0x3f, sizeof(tree));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void upd(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[x], v);
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = 1e9;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg;

int n, q, arr[MAXN];
int l[MAXN], r[MAXN];

int main(){
	cin >> n >> q;
	seg.init(n);
	memset(l, 0x3f, sizeof(l));
	int anny = -1;
	set<int> s;
	for(int i=1; i<=n; i++){
		scanf("%d",&arr[i]);
		l[arr[i]] = min(l[arr[i]], i);
		r[arr[i]] = max(r[arr[i]], i);
		if(arr[i] == 0) s.insert(i);
		else seg.upd(i, arr[i]);
	}
	if(!s.empty()) anny = *s.begin();
	for(int i=q; i; i--){
		if(l[i] > r[i]) continue;
		if(seg.query(l[i], r[i]) < i){
			puts("NO");
			return 0;
		}
		auto it = s.lower_bound(l[i]);
		while(it != s.end()){
			if(*it <= r[i]){
				arr[*it] = i;
				it = s.erase(it);
			}
			else break;
		}
	}
	for(auto &i : s) arr[i] = 1;
	if(l[q] > r[q]){
		if(anny == -1){
			puts("NO");
			return 0;
		}
		arr[anny] = q;
	}
	puts("YES");
	for(int i=1; i<=n; i++) printf("%d ", arr[i]);
	// TODO : make sure q appears
}