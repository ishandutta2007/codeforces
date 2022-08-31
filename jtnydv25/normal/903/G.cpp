#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%lld", &(x))
#define ll long long
#define F first
#define S second
#define int ll
const int N = 200005;
const ll INF = 1e18;
int a[N], b[N];
vector<pair<int, int> > con[N];
vector<pair<int, int> > revcon[N];
long long cst[N];
ll tree[N << 2], lazy[N << 2];

int n, m, q;
int make(int s = 0, int e = n - 1, int ind = 1){
	if(s == e) return tree[ind] = b[s];
	int mid = (s + e) >> 1;
	return tree[ind] = min(make(s, mid, ind << 1), make(mid + 1, e, ind << 1 | 1));
}

void go(int s, int e, int ind){
	int l = lazy[ind];
	tree[ind] += l;
	lazy[ind] = 0;
	if(s != e){
		lazy[ind << 1] += l;
		lazy[ind << 1 | 1] += l;
	}
}

void update(int l, int r, int k, int s = 0, int e = n - 1, int ind = 1){
	go(s, e, ind);
	if(l > e || s > r) return;
	if(s >= l && e <= r){
		lazy[ind] = k;
		go(s, e, ind);
		return;
	}
	int mid = (s + e) >> 1;
	update(l, r, k, s, mid, ind << 1);
	update(l, r, k, mid + 1, e, ind << 1 | 1);
	tree[ind] = min(tree[ind << 1], tree[ind << 1 | 1]);
}

ll getMin(){
	go(0, n - 1, 1);
	return tree[1];
}

ll get(int l, int r, int s = 0, int e = n - 1, int ind = 1){
	go(s, e, ind);
	if(l > e || s > r) return INF;
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return min(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, ind << 1 | 1));
}

multiset<ll> ms;
main(){
	sd(n); sd(m); sd(q);
	for(int i = 1; i <= n - 1; i++){
		sd(a[i]); sd(b[i]);
	}

	for(int i = 1; i <= m; i++){
		int u, v, w;
		sd(u); sd(v); sd(w);
		con[u].push_back({v, w});
	 	revcon[v].push_back({u, w}); 
	}
	make();
	for(int i = 1; i <= n; i++){
		for(auto it : con[i]){
			update(0, it.F - 1, it.S);
			// cerr << it.F - 1 << " " << it.S << endl;
		}
		cst[i] = getMin();
		// for(int i = 0; i <= n - 1; i++) cerr << get(i, i) << " "; cerr << endl;
		// cerr << "cst : " << cst[i] << endl;
	}
	for(int i = 1; i <= n; i++) ms.insert(a[i] + cst[i]);
	printf("%lld\n", *ms.begin());
	while(q--){
		int i, W;
		sd(i); sd(W);
		ms.erase(ms.find(a[i] + cst[i]));
		a[i] = W;
		ms.insert(a[i] + cst[i]);
		printf("%lld\n", *ms.begin());
	}
}