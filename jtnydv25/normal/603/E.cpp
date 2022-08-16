#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int INF = 1.1e9;
const int N = 3e5 + 10;
template<class T>
struct rollback_array{
	stack<pair<int, T>> changes;
	T arr[N];
	rollback_array(){}
	T get(int i){
		return arr[i];
	}
	void update(int i, T v, bool roll = 0){
		if(roll) changes.push({i, arr[i]});
		arr[i] = v;
	}
	void click(){
		changes.push({INF, T()});
	}
	void roll_back_to_the_last_click(){
		while(!changes.empty()){
			auto it = changes.top();
			changes.pop();
			if(it.F == INF) return;
			arr[it.F] = it.S;
		}
	}
};

rollback_array<int> par, rnk, parity;

int comp;
int odd;
void init(){
  for(int i = 1; i < N; i++){
  	par.update(i, i);
  	rnk.update(i, 1);
  	parity.update(i, 1);
  }
}

int root(int x, bool roll = 0){
	int parx = par.get(x);
	if(x == parx) return x;
	int rt = root(parx, roll);
	par.update(x, rt, roll);
	return rt;
}

bool merge(int x, int y, bool roll = 0){
  x = root(x, roll), y = root(y, roll);
  if(x == y){
    return 0;
  }
  int rnkx = rnk.get(x), rnky = rnk.get(y);
  if(rnkx > rnky) swap(x, y), swap(rnkx, rnky);

  int parx = parity.get(x), pary = parity.get(y);
  if(parx && pary) odd -= 2;

  parity.update(y, parx ^ pary, roll);
  par.update(x, y, roll);
  if(rnkx == rnky){
  	rnk.update(y, rnky + 1, roll);
  }
  return 1;
}

int a[N], b[N], w[N], perm[N], iperm[N];

bool cmp(int i, int j){return w[i] < w[j];}

int n, m;
int ans[N];

void click_all(){
	par.click(); rnk.click(); parity.click();
}

void rollback_all(int odd2 = 0){
	par.roll_back_to_the_last_click();
	rnk.roll_back_to_the_last_click();
	parity.roll_back_to_the_last_click();
	odd = odd2;
}

void go(int p = 1, int q = m, int l = 1, int r = m){
	// cerr << l << " " << r << " " << p << " " << q << endl;
	// currently l, p-1	
	int odd2 = odd;
	click_all();
	if(l == r){
		int p1;
		for(p1 = p; p1 <= q; p1++){
			if(perm[p1] <= l){
				merge(a[perm[p1]], b[perm[p1]], 1);
			}
			if(odd == 0){
				printf("%d\n", w[perm[p1]]);
				rollback_all();
				return;
			}
		}
		printf("-1\n");
		rollback_all(odd2);
		return;
	}

	int mid = (l + r) >> 1, mid2 = q;
	for(int i = l; i <= mid; i++) if(iperm[i] < p) merge(a[i], b[i], 1);

	for(int p1 = p; p1 <= q; p1++){
		if(perm[p1] <= mid) merge(a[perm[p1]], b[perm[p1]], 1);
		if(odd == 0){
			mid2 = p1;
			break;
		}
	}


	rollback_all(odd2);

	click_all();

	for(int i = p; i < mid2; i++){
		if(perm[i] <= l) merge(a[perm[i]], b[perm[i]], 1);
	}

	go(mid2, q, l, mid);

	rollback_all(odd2);

	click_all();

	for(int i = l + 1; i <= mid + 1; i++){
		if(iperm[i] < p) merge(a[i], b[i], 1);
	}

	go(p, mid2, mid + 1, r);
	rollback_all(odd2);
}

int main(){
	sd(n); sd(m);
	for(int i = 1; i <= m; i++){
		sd(a[i]); sd(b[i]); sd(w[i]); perm[i] = i;
	}
	sort(perm + 1, perm + m + 1, cmp);
	for(int i = 1; i <= m; i++) iperm[perm[i]] = i;
	init();
	odd = n;
	go();
}