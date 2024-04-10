#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int N;
int B[maxn];

inline void add(int x, int y){
	for(;x <= N;x += x & -x) B[x] += y; 
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += B[x];
	return sum;
}

struct Node{
	int sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
}

inline void Add(int x, int y){
	t[x].sum += y, t[x].tag += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	Add(ls(x), t[x].tag), Add(rs(x), t[x].tag);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		Add(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

void build(int x, int l, int r){
	t[x].tag = 0;
	if(l == r){
		t[x].sum = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int T, n, m;
int a[maxn], b[maxn];
vector<int> w[maxn];
vector<int> v;
pair<int, int> p[maxn];

int main(){
	T = read();
	while(T--){
		n = read(), m = read();
		v.clear();
		for(int i = 1;i <= n;i++) a[i] = read(), v.push_back(a[i]);
		for(int i = 1;i <= m;i++) b[i] = read(), v.push_back(b[i]);
		sort(v.begin(), v.end()), sort(b + 1, b + 1 + m);
		v.erase(unique(v.begin(), v.end()), v.end());
		N = v.size();
		for(int i = 1;i <= N;i++) B[i] = 0, w[i].clear();
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
			ans += i - 1 - query(a[i]), add(a[i], 1);
			p[i] = {a[i], i};
			w[a[i]].push_back(i);
		}
		sort(p + 1, p + 1 + n);
		build(1, 0, n);
		int x = 0;
		for(int i = 1;i <= m;i++){
			b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
			if(b[i] ^ b[i - 1]){
				if(b[i - 1]) for(int j = 0;j < w[b[i - 1]].size();j++) modify(1, 0, n, w[b[i - 1]][j], n, 1);
				for(int j = 0;j < w[b[i]].size();j++) modify(1, 0, n, w[b[i]][j], n, -1);
			}	
			while(x < n && p[x + 1].first < b[i]){
				int pos = p[++x].second;
				modify(1, 0, n, pos, n, -1);
				modify(1, 0, n, 0, pos - 1, 1);
			}
			ans += t[1].sum;
		}
		printf("%lld\n", ans);
	}
}