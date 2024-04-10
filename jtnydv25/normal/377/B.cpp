#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
int a[N], b[N], c[N], perm[N], perm2[N];
int B[N], C[N], ptr[N];

bool cmp(int i, int j){ return b[i] < b[j];}
bool cmp2(int i, int j){ return a[i] < a[j];}

int tree[N << 2];
int n, m, s;

inline int mn(int i, int j){ return C[i] < C[j] ? i : j;}
void make(int s = 1, int e = n, int ind = 1){
	if(s == e){
		tree[ind] = s;
		return;
	}
	int mid = (s + e) >> 1;
	make(s, mid, ind << 1);
	make(mid + 1, e, ind << 1 | 1);
	tree[ind] = mn(tree[ind << 1], tree[ind << 1 | 1]);
}

void update(int i, int x, int s = 1, int e = n, int ind = 1){
	if(s > i || e < i) return;
	if(s == e){
		tree[ind] = x;
		return;
	}
	int mid = (s + e) >> 1;
	update(i, x, s, mid, ind << 1);
	update(i, x, mid + 1, e, ind << 1 | 1);
	tree[ind] = mn(tree[ind << 1], tree[ind << 1 | 1]);
}

int get(int l, int r, int s = 1, int e = n, int ind = 1){
	if(s > r || e < l || l > r) return N - 1;
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return mn(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, ind << 1 | 1));
}

const int INF = 1.01e9;
inline int add(int x, int y){
	x += y;
	if(x > INF) x = INF;
	return x;
}
int done[N];
bool check(int k){
	make();
	C[N - 1] = INF;
	int ret = 0;
	for(int i = m; i >= 1; i -= k){
		int ind = get(ptr[i], n);
		ret = add(ret, C[ind]);
		update(ind, N - 1);
		for(int j = i; j > i - k && j >= 1; j--) done[perm2[j]] = perm[ind];
	}
	return ret <= s;
}

int main(){
	sd(n); sd(m); sd(s);

	for(int i = 1; i <= m; i++){
		sd(a[i]);
		perm2[i] = i;
	}

	sort(perm2 + 1, perm2 + m + 1, cmp2);

	for(int i = 1; i <= n; i++){
		sd(b[i]);
		perm[i] = i;
	}

	for(int i = 1; i <= n; i++){
		sd(c[i]);
	}

	sort(perm + 1, perm + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		B[i] = b[perm[i]];
		C[i] = c[perm[i]];
		if(i == 3) cerr << perm[i] << " " << B[i] << " " << C[i] << endl;
	}

	for(int i = 1; i <= m; i++){
		ptr[i] = lower_bound(B + 1, B + n + 1, a[perm2[i]]) - B;
		if(ptr[i] > n){
			printf("NO\n");
			return 0;
		}
	}
	// check(3);
	int lo = 1, hi = m + 1;
	while(lo < hi){
		int k = (lo + hi) >> 1;
		if(check(k)) hi = k;
		else lo = k + 1;
	}
	if(lo > m){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	check(lo);
	for(int i = 1; i <= m; i++) printf("%d ", done[i]);
}