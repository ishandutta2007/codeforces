#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 505;
int n, a[N], k, low;
set <int> pos, mid;

int que() {
	cout << "? " << pos << endl;
	int p;
	cin >> p;
	cin >> a[p];
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	if(k == 1) {cout<< "! 1" << endl; return 0;}

	for(int i = 1; i <= k; i++)
		pos.insert(i);

	int p = que();

	for(int i = k + 1; i <= n; i++) {
		mid.insert(p);
		pos.erase(p);
		pos.insert(i);
		
		p = que();
	}

	mid.insert(p);
	pos.erase(p);

	set <int> new_pos = pos;
	int p1 = *mid.begin();
	int p2 = *mid.rbegin();

	if(a[p1] > a[p2]) swap(p1, p2);

	pos.insert(p1);
	pos.insert(p2);
	for(auto i : new_pos) {
		pos.erase(i);
		int pp = que();
		if(pp == p2)
			low++;
		pos.insert(i);
	}

	cout << "! " << low + 1 << endl;



}