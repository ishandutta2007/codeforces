#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

long long n, k, m;

string a, b;
vector <int> aa, bb, both, zero;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> a;
	cin >> b;
	for(int i = 0; i < n; i++) {
		if(a[i] == '0' && b[i] == '0')
			zero.push_back(i + 1);
		else if(a[i] == '1' && b[i] == '1')
			both.push_back(i + 1);
		else if(a[i] == '1')
			aa.push_back(i + 1);
		else 
			bb.push_back(i + 1);
	}

	for(int i = 0; i <= aa.size(); i++)
		for(int j = 0; j <= bb.size(); j++) {
			int dif = i - j;
			if(abs(dif) > both.size() || abs(dif) % 2 != both.size() % 2) 
				continue;
			
			int each = ((int)both.size() - abs(dif)) / 2;


			int nr1 = each + i + bb.size() - j;
			int nr2 = each + j + aa.size() - i;

			if(dif > 0) nr2 += dif;
			else				nr1 += abs(dif);
			
			if(nr1 > n / 2 || nr2 > n / 2) 
				continue;

			dbg(i);
			dbg(j);
			dbg(nr1);
			dbg(nr2);
			dbg(dif);


			for(int l = 0; l < i; l++)
				cout << aa[l] << ' ';
			// dbg_ok;

			for(int l = 0; l + j < bb.size(); l++)
				cout << bb[l] << ' ';
			// dbg_ok;
			
			int wert = each - min(dif, 0);

			for(int l = 0; l < wert; l++)
				cout << both[l] << ' ';
			// dbg_ok;

			for(int l = nr1 + 1; l <= n / 2; l++)
				cout << zero[l - nr1 - 1] << ' ';
			return 0;
		}

	cout << "-1\n";
}