/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

class CRamzesIInvertirovanieUglov {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		vc<vc<int>> a(n, vc<int> (m));
		vc<vc<int>> b(n, vc<int> (m));
		in >> a >> b;
		for (int i = 1; i < n; i++){
			for (int j = 1; j < m; j++){
				int x = a[i][j] ^ b[i][j];
				a[0][0] ^= x;
				a[i][0] ^= x;
				a[0][j] ^= x;
				a[i][j] ^= x;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i][j] != b[i][j]){
					out << "No";
					return;
				}
			}
		}
		out << "Yes";
	}
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	CRamzesIInvertirovanieUglov solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}