#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int INF = 1.1e9;
const int N = 4e5 + 10;
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
	
rollback_array<int> par, rnk;
	
int notBipartite;
void init(){
	for(int i = 1; i < N; i++){
		par.update(i, 2 * i);
		rnk.update(i, 1);
	}
}

int root(int x){
	int ret = 0;
	while(true){
		int h = par.get(x);
		if(x == (h >> 1)) break;
		ret ^= (h & 1);
		x = h >> 1;
	}
	return 2 * x + ret;
}
	
bool merge(int x, int y, bool roll = 0){
	int X = root(x), Y = root(y);
	x = X >> 1, y = Y >> 1;
	int parity_x = X & 1, parity_y = Y & 1;
	if(x == y){
		if(parity_x == parity_y) notBipartite = 1;
		return 0;
	}
	int rnkx = rnk.get(x), rnky = rnk.get(y);
	if(rnkx > rnky){
		swap(x, y), swap(rnkx, rnky);
		swap(parity_x, parity_y);
	}
	int nw = 2 * y + (parity_x ^ parity_y ^ 1);
	par.update(x, nw, roll);

	if(rnkx == rnky){
		rnk.update(y, rnky + 1, roll);
	}
	return 1;
}
	
int a[N], b[N];
	
int n, m;
	
void click_all(){
	par.click(); rnk.click();
}
	
void rollback_all(int notBipartite2 = 0){
	par.roll_back_to_the_last_click();
	rnk.roll_back_to_the_last_click();
	notBipartite = notBipartite2;
}

int fst[N];

// [p, q] -> answers in [l, r]
// dsu maintains [q, l] currently

void go(int p, int q, int l, int r){
	if(p > q) return;
	int notBipartite2 = notBipartite;
	click_all();
	int mid = (p + q) / 2;
	// answer at mid ?
	for(int i = mid; i <= min(q, l); i++){
		merge(a[i], b[i], 1);
	}
	// [mid, l]
	int i = max(l, mid - 1);
	for(;!notBipartite; i++) merge(a[i + 1], b[i + 1], 1);
	assert(notBipartite);
	assert(i <= r && i >= mid + 2);
	fst[mid] = i;
	rollback_all(notBipartite2);

	if(p <= mid - 1){
		click_all();
		for(int j = mid - 1; j <= min(l, q - 1); j++){
			merge(a[j], b[j], 1);
		}
		go(p, mid - 1, l, i);
		rollback_all(notBipartite2);
	}

	if(mid + 1 <= q){
		click_all();
		for(int j = max(q, l + 1); j <= i; j++) merge(a[j], b[j], 1);
		go(mid + 1, q, i, r);
		rollback_all(notBipartite2);
	}
}

int main(){
	n = 200000, m = 200000;
	int q = 200000;
	sd(n); sd(m); sd(q);

	for(int i = 1; i <= m; i++){
		a[i] = rand() % n + 1; b[i] = rand() % n + 1;
		sd(a[i]); sd(b[i]); 
		a[i + m] = a[i]; b[i + m] = b[i];
	}
	
	a[2 * m + 1] = 1, b[2 * m + 1] = 2;
	a[2 * m + 2] = 2; b[2 * m + 2] = 3;
	a[2 * m + 3] = 3; b[2 * m + 3] = 1;
	init();
	go(1, m + 1, 1, 2 * m + 3);
	for(int i = 1; i <= q; i++){
		int l = rand() % m + 1, r = n; 
		scanf("%d %d", &l, &r);
		printf(m > 2 && fst[r + 1] < l + m ? "YES\n" : "NO\n");
	}
}