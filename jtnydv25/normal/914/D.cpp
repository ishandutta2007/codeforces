#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second

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

const int N = 500005;
int tree[N << 2], a[N];
int n;
int make(int s = 1, int e = n, int ind = 1){
	if(s == e){
		return tree[ind] = a[s];
	}
	int mid = (s + e) >> 1;
	return tree[ind] = __gcd(make(s, mid, ind << 1), make(mid + 1, e, ind << 1 | 1));
}
void update(int i, int y, int s = 1, int e = n, int ind = 1){
	// trace(s, e, ind);
	if(s > i || e < i) return;
	if(s == e){
		tree[ind] = y;
		return;
	}
	int mid = (s + e) >> 1;
	update(i, y, s, mid, ind << 1);
	update(i, y, mid + 1, e, ind << 1 | 1);
	tree[ind] = __gcd(tree[ind << 1], tree[ind << 1 | 1]);
}

bool valid2(int x, int s, int e, int ind){
	if(s == e) return 1;
	int a = (tree[ind << 1] % x != 0);
	int b = (tree[ind << 1 | 1] % x != 0);
	if(a && b) return 0;
	int mid = (s + e) >> 1;
	if(a) return valid2(x, s, mid, ind << 1);
	else return valid2(x, mid + 1, e, ind << 1 | 1);
}
int cnt = 0;
bool valid(int x, int l, int r, int s = 1, int e = n, int ind = 1){
	// trace(s, e, ind);
	if(ind == 0){
		return 0;
	}
	if(l > e || s > r) return 1;
	if(s >= l && e <= r){
		if(tree[ind] % x != 0){
			cnt++;
			if(cnt > 1) return 0;
			return valid2(x, s, e, ind); 
		}
		return 1;
	}
	int mid = (s + e) >> 1;
	return valid(x, l, r, s, mid, ind << 1) && valid(x, l, r, mid + 1, e, ind << 1 | 1);
}

int main(){
	int q;
	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]);
	make();
	sd(q);
	while(q--){
		int type, l, r, x;
		sd(type); sd(l); sd(r); 
		if(type == 1){
			sd(x);
			// trace(l, r, x);
		}
		if(type == 2){
			update(l, r);
			continue;
		}
		cnt = 0;
		printf(valid(x, l, r) ? "YES\n" : "NO\n");
	}
}