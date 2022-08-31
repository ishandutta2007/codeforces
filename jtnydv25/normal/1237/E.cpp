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
const int N = 1 << 21;
int bit[N];
void add(int x, int y){
	for(; x < N; x += (x & (-x))) bit[x] += y;
}

int get(int x){
	int ret = 0;
	for(; x; x -= (x & (-x))) ret += bit[x];
	return ret;
}

int get(int l, int r){
	return get(r) - get(l - 1);
}
void go(int l, int r, int i){
	if(i == 1){
		add(r, 1);
		return;
	}
	int mid = (l + r) / 2;
	go(l, mid, i - 1);
	go(mid + 1, r, i - 1);
	int mid2 = (mid + 1 + r) / 2;
	int parity = ((1 << (i - 1)) - 1 + get(mid2) - get(mid)) % 2;
	if(parity == 0) add(mid + 1, 1);
}

bool verify(int l, int r, int i){
	if(i == 1) return true;
	int mid = (l + r) / 2;
	int mid2 = (l + mid) / 2;
	if(( (1 << (i - 1)) - 1 + get(mid2 + 1, mid)) % 2 == 1) return 0;
	return verify(l, mid, i - 1) && verify(mid + 1, r, i - 1);
}

int f(int n){
	int k = 0;
	while((1 << k) - 1 < n) k++;
	if(n <= 2) return 1;
	if(n == 3) return 0;
	go(1, 1 << (k - 2), k - 2);
	int total = (1 << (k - 1)) - 1 + get(1, 1 << (k - 2));
	if(total != n && total != n - 1) return 0;
	int ret = n - total;
	add(1, ret);
	if(!verify(1, 1 << (k - 2), k - 2)) return 0;
	return 1;
}

int main(){
	int n; sd(n);
	// for(int i = 1; i <= n; i++){
	// 	for(int i = 0; i <= 10 * n; i++) bit[i]= 0;
	// 	if(f(i) == 1) cerr << i << endl;
	// }
	printf("%d\n", f(n));
}