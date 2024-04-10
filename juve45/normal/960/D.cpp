#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, sh[99], x, h;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


long long get_pos(long long lvl, long long val) {
	long long pos = val - (1LL << (lvl - 1));
	pos += sh[lvl];
	pos %= (1LL << (lvl - 1));
	return pos;
}

long long get_el(long long lvl, long long pos) {
	long long val = (1LL << (lvl - 1)) + pos; //initial
	val -= sh[lvl];
	if(val < (1LL << (lvl - 1)))
		val += (1LL << (lvl - 1));
	return val;
}

void rec_shift(long long lvl, long long h) {
	if(lvl > 61) return;
	sh[lvl] += h;
	sh[lvl] %= (1LL << (lvl - 1));
	rec_shift(lvl + 1, 2 * h);
}




long long lvl(long long nr) {
	long long ans = 0;
	long long nn = nr;
	while(nr) ans++, nr /= 2;
	// if((1LL << (ans - 1)) == nn) ans--;
	return ans;
}


void dfs(long long lev, long long pos) {
	if(lev == 0) return;
	cout << get_el(lev, pos) << ' ';
	dfs(lev - 1, pos / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	// cout << lvl(1);
	// cout << lvl(2);
	// cout << lvl(3);
	// cout << lvl(4);
	// cout << lvl(5);
	// cout << lvl(6);
	// cout << lvl(7);
	// cout << lvl(8);

	for(long long i = 1; i <= n; i++) {
		long long op;
		cin >> op;
		if(op == 3) {
			cin >> x;
			long long lx = lvl(x);
			long long pos = get_pos(lx, x);
			// cout << pos << '\n';
			// cout << get_el(lx, pos) << '\n';
			dfs(lx, pos);
			cout << '\n';
		}
		if(op == 2) {
			cin >> x >> h;
			long long lx = lvl(x);
			h %= (1LL << (lx - 1));
			if(h < 0) h += (1LL << (lx - 1));
			rec_shift(lvl(x), h);
		}
		if(op == 1) {
			cin >> x >> h;
			long long lx = lvl(x);
			h %= (1LL << (lx - 1));
			if(h < 0) h += (1LL << (lx - 1));
			sh[lx] += h;
			sh[lx] %= (1LL << (lx - 1));
		}
	}	
}