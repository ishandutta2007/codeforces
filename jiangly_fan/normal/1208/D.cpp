//Author: HeXun
//Date: 08-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
LL s[maxn];
LL mn[maxn << 2], added[maxn << 2];
int p[maxn];
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void add(int v, LL x){
	mn[v] += x;
	added[v] += x;
}
void push_down(int v){
	add(ls, added[v]);
	add(rs, added[v]);
	added[v] = 0;
}
void add(int v, int tl, int tr, int L, int R, LL x){
	if(tl >= L and tr <= R) add(v, x);
	else{
		push_down(v);
		if(L <= tm) add(ls, tl, tm, L, R, x);
		if(R > tm) add(rs, tm + 1, tr, L, R, x);
		mn[v] = min(mn[ls], mn[rs]);
	}
}
int query(int v, int tl, int tr){
	if(tl == tr) return tm;
	push_down(v);
	if(mn[rs] == 0) return query(rs, tm + 1, tr);
	return query(ls, tl, tm);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> s[i];
		add(1, 1, n, i, i, s[i]);
	}
	for(int i = 1; i <= n; i += 1){
		int x = query(1, 1, n);
		p[x] = i;
		if(x < n) add(1, 1, n, x + 1, n, -i);
		add(1, 1, n, x, x, 1e12);
	}
	for(int i = 1; i <= n; i += 1) cout << p[i] << " ";
	return 0;
}