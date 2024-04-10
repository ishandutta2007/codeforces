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

// const int N = ;
int n, z0, z1, z2, z3;
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> z0 >> z1 >> z2 >> z3;

	if(z2 == 0 && z3 == 0)
		if(z0 == z1 + 1) {
			v.push_back(0);
			for(int i = 0; i < z1; i++)
				v.push_back(1),
				v.push_back(0);
			cout << "YES\n";
			cout << v << '\n';
			return 0;
		}

	if(z1 == 0 && z0 == 0)
		if(z3 == z2 + 1) {
			v.push_back(3);
			for(int i = 0; i < z2; i++)
				v.push_back(2),
				v.push_back(3);
			cout << "YES\n";
			cout << v << '\n';
			return 0;
		}
	

	if(z1 < z0 || z2 < z3) 
		return cout << "NO\n", 0;
	
	int z01 = z0, z23 = z3;
	z1 -= z01;
	z2 -= z23;

	int z21 = min(z1, z2);
	z1 -= z21;
	z2 -= z21;

	if(z1 > 1 || z2 > 1) 
		return cout << "NO\n", 0;

	if(z1 == 1)
		v.push_back(1);

	for(int i = 0; i < z01; i++)
		v.push_back(0),
		v.push_back(1);
	for(int i = 0; i < z21; i++)
		v.push_back(2),
		v.push_back(1);
	for(int i = 0; i < z23; i++)
		v.push_back(2),
		v.push_back(3);

	if(z2 == 1)
		v.push_back(2);

	cout << "YES\n";
	cout << v << '\n';
}