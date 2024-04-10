#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cppio ios_base::sync_with_stdio(0);cin.tie(0)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1005;

int n, s[N], v[N], c;
vector<int> e[N];

int sf(int x, int y){
	s[x] = 1;
	for(int i : e[x]) if(i != y) s[x] += sf(i, x);
	return s[x];
}

int cf(int x, int y, int t){
	for(int i : e[x]) if(i != y && s[i] > t / 2) return cf(i, x, t);
	return x;
}

void f(int x, int y, int m){
	v[x] = ++c;
	printf("%d %d %d\n", x, y, m * (c - v[y]));
	for(int i : e[x]) if(i != y) f(i, x, m);
}

int main(){ cppio;
	cin >> n;
	for(int i = 0, x, y; i < n - 1; i++){
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}
	int x = cf(1, 0, sf(1, 0));
	sf(x, 0);
	sort(all(e[x]), [](int x, int y){ return s[x] > s[y]; });
	int sc = 0, mode = 1, mlt;
	for(int i : e[x]){
		sc += s[i];
		if(mode == 1) f(i, x, 1);
		else f(i, x, mlt);
		if(sc > n / 3 && mode == 1){
			mlt = sc + 1;
			mode = 2;
			c = 0;
		}
	}
}