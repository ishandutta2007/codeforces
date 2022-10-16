#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <long long> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const long long N = 100100;

long long n, m, a[N], k[N], x, y;
long long st[4 * N], lazy[4 * N];
set <pair<long long, long long> > diff;
string op;

void push(long long nod, long long l, long long r)
{
	if(lazy[nod])
	{
		if(l < r)
		{
			long long mid = (l + r) / 2;
			lazy[2 * nod] += lazy[nod];
			st[2 * nod] += lazy[nod] * (mid - l + 1);
			lazy[2 * nod + 1] += lazy[nod];
			st[2 * nod + 1] += lazy[nod] * (r - mid);
		}
		lazy[nod] = 0;
	}
}

void upd(long long nod, long long l, long long r, long long x, long long y, long long val)
{
	push(nod, l, r);
	if(l == r) {
		st[nod] += val;
		return ;
	}

	long long mid = (l + r) / 2;
	if(x <= l && r <= y)
		lazy[nod] += val;
	else{
		if(x <= mid) upd(2 * nod, l, mid, x, y, val);
		if(y > mid) upd(2 * nod + 1, mid + 1, r, x, y, val);
	}
	// push(nod, l, r);
	st[nod] = st[2 * nod] + st[2 * nod + 1] + lazy[nod] * (r -l + 1);
}

long long que(long long nod, long long l, long long r, long long x, long long y)
{
	push(nod, l, r);

	if(x <= l && r <= y)
		return st[nod];

	long long mid = (l + r) / 2, ans = 0;

	if(x <= mid) ans += que(2 * nod, l, mid, x, y);
	if(y > mid) ans += que(2 * nod + 1, mid + 1, r, x, y);
	return ans;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		upd(1, 1, n, i, i, a[i]);
	}
	for(long long i = 1; i < n; i++)
		cin >> k[i];
	for(long long i = 1; i < n; i++)
		diff.insert({i, a[i + 1] - a[i] - k[i]});
	diff.insert({n, 1e13});

	cin >> m;
	for(long long i = 1; i <= m; i++) {
		cin >> op >> x >> y;
		long long add = y;
		if(op == "s") {
			cout << que(1, 1, n, x, y) << '\n';
		} else {
			// dbg(diff);
			/// a creste cu b
			long long last = x;
			auto it = diff.lower_bound({x, -1e8});

			while(it != diff.end() && y > 0) {
				// dbg(last);
				// dbg(*it);

				// de la pozitia last la it->
				upd(1, 1, n, last, it->st, y);
				// dbg(last);
				// dbg(it->st);
				// dbg(y);

				last = it->st + 1;
				long long rem = it->nd - y;
				long long pos = it->st;
				y = max(0LL, y - it->nd);
				auto it2 = it;
				it++;
				diff.erase(it2);
				// dbg(rem);
				// dbg(y);
				if(rem > 0) {
					diff.insert({pos, rem});
					break;
				}
			}
			// dbg_ok;

			// update diff[i];
			if(x > 1) {
				auto it2 = diff.lower_bound({x - 1, -1e8});
				long long rem = 0;
				if(it2 != diff.end() && it2->st == x - 1) {
					rem = it2->nd;
					diff.erase(it2);
				}
				diff.insert({x - 1, rem + add});
			}

		}

	}
}