#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int maxn = 120000;
void no(){
	cout << ":(";
	exit(0);
}
char s[maxn];
int stag[maxn << 2], xtag[maxn << 2], a[maxn];
void push_down(int o, int l, int r){
	if(l != r){
		if(stag[o]){
			stag[o << 1] = stag[o];
			stag[o << 1 | 1] = stag[o];
			stag[o] = 0;
			xtag[o << 1 | 1] = xtag[o << 1] = 0;
		}
		xtag[o << 1] ^= xtag[o];
		xtag[o << 1 | 1] ^= xtag[o];
		xtag[o] = 0;
	}
}
void sett(int o, int l, int r, int L, int R, int v){
	push_down(o, l, r);
	int m = (l + r) >> 1;
	if(l >= L and r <= R){
		xtag[o] = 0;
		stag[o] = v;
	}
	else{
		if(L <= m) sett(o << 1, l, m, L, R, v);
		if(R > m) sett(o << 1 | 1, m + 1, r, L, R, v);
	}
}
void xorr(int o, int l, int r, int L, int R){
	push_down(o, l, r);
	int m = (l + r) >> 1;
	if(l >= L and r <= R) xtag[o] ^= 1;
	else{
		if(L <= m) xorr(o << 1, l, m, L, R);
		if(R > m) xorr(o << 1 | 1, m + 1, r, L, R);
	}
}
pair<int, int> query(int o, int l, int r, int p){
	push_down(o, l, r);
	int m = (l + r) >> 1;
	if(l == r) return make_pair(xtag[o], stag[o]);
	if(p <= m) return query(o << 1, l, m, p);
	return query(o << 1 | 1, m + 1, r, p);
}
int main(){
	ios::sync_with_stdio(false);
	int n, q, x, m = 1.1e5;
	cin >> n >> q;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= q; i += 1){
		cin >> s >> x;
		if(x == 0){
			if(*s == '>') sett(1, 1, m, 1, m, -1);
			else sett(1, 1, m, 1, m, 1);
		}
		if(x > 0){
			if(*s == '>') sett(1, 1, m, x + 1, m, -1);
			else{
				sett(1, 1, m, x, m, 1);
				if(x > 1) xorr(1, 1, m, 1, x - 1);
			}
		}
		if(x < 0){
			if(*s == '<') sett(1, 1, m, -x + 1, m, 1);
			else{
				sett(1, 1, m, -x, m, -1);
				if(x < -1) xorr(1, 1, m, 1, - x - 1);
			}
		}
	}
	for(int i = 1; i <= n; i += 1){
		if(a[i] == 0) cout << "0 ";
		else{
			auto p = query(1, 1, m, abs(a[i]));
			//cout << "!!!" << a[i] << " " << p.first << " " << p.second << endl;
			if(p.second){
				if(p.second == 1 and p.first == 0) cout << abs(a[i]) << " ";
				if(p.second == 1 and p.first == 1) cout << -abs(a[i]) << " ";
				if(p.second == -1 and p.first == 1) cout << abs(a[i]) << " ";
				if(p.second == -1 and p.first == 0) cout << -abs(a[i]) << " ";
			}
			else{
				if(p.first) cout << -a[i] << " ";
				else cout << a[i] << " ";
			}
		}
	}
}