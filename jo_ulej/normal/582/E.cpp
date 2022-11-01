#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DEBUG_OUTPUT_ENABLED 1
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
#endif

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
	};
	DebugStream instance(true);
};

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MOD = (int)1e9 + 7;
const int N   = 16;
inline int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
inline int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
inline int mult(int x, int y) {
	ll r = x * 1LL * y;
	if(r >= MOD) r %= MOD;
	return (int)r;
}
map<char, int> VarTable;
struct Node {
	char type;
	Node* left = nullptr;
	Node* right = nullptr;
	vector<int> dp;
};
string S;
int ptr = 0;
Node* Var() {
	Node* rez = new Node();
	rez->type = S[ptr++];
	return rez;
}
Node* Expr() {
	if(S[ptr] == '(') {
		++ptr;
		Node* rez = new Node();
		rez->left = Expr();
		assert(S[ptr++] == ')');
		rez->type = S[ptr++];
		assert(S[ptr++] == '(');
		rez->right = Expr();
		assert(S[ptr++] == ')');
		return rez;
	} else {
		return Var();
	}
}
void showNZ(const vector<int>& v) {
	for(int i = 0; i < (1 << N); ++i) if(v[i]) dout << i << ": " << v[i] << '\n';
}
vector<int> Transform(const vector<int>& v) {
	vector<int> a = v;
	for(int bt = 0; bt < N; ++bt) {
		int j = 1 << bt;
		for(int i = 0; i < (1 << N); ++i) {
			if(i & j) continue;
			a[i] = add(a[i], a[i ^ j]);
		}
	}
	return a;
}
vector<int> DeTransform(const vector<int>& v) {
	vector<int> a = v;
	for(int bt = N - 1; bt >= 0; --bt) {
		int j = 1 << bt;
		for(int i = 0; i < (1 << N); ++i) {
			if(i & j) {
				a[i ^ j] = sub(a[i ^ j], a[i]);
			}
		}
	}
	return a;
}
vector<int> AndConvolution(const vector<int>& lhs, const vector<int>& rhs) {
	auto left = Transform(lhs);
	auto right = Transform(rhs);
	vector<int> rez(1 << N, 0);
	for(int i = 0; i < (1 << N); ++i) rez[i] = mult(left[i], right[i]);
	return DeTransform(rez);
	/*vector<int> rez(1 << N, 0);
	for(int i = 0; i < (1 << N); ++i) if(lhs[i]) for(int j = 0; j < (1 << N); ++j) if(rhs[j]) rez[i & j] = add(rez[i & j], mult(lhs[i], rhs[j]));
	return rez;*/
}
vector<int> OrConvolution(const vector<int>& lhs, const vector<int>& rhs) {
	vector<int> left(1 << N, 0), right(1 << N, 0);
	for(int i = 0; i < (1 << N); ++i) {
		int j = i ^ ((1 << N) - 1);
		left[i] = lhs[j];
		right[i] = rhs[j];
	}
	auto rez = AndConvolution(left, right);
	vector<int> t(1 << N, 0);
	for(int i = 0; i < (1 << N); ++i) {
		int j = i ^ ((1 << N) - 1);
		t[i] = rez[j];
	}
	return t;
}
void calc(Node* node) {
	node->dp.resize(1 << N, 0);	
	if(node->left == nullptr && node->right == nullptr) {
		for(auto& PR: VarTable) {
			if(PR.first == node->type || node->type == '?') {
				node->dp[PR.second] = add(node->dp[PR.second], 1);
			}
		}
	} else {
		calc(node->left);
		calc(node->right);
		if(node->type == '?' || node->type == '&') {
			SAY("&");
			auto t = AndConvolution(node->left->dp, node->right->dp);
			for(int i = 0; i < (1 << N); ++i) node->dp[i] = add(node->dp[i], t[i]);
		}	
		if(node->type == '?' || node->type == '|') {
			SAY("|");
			auto t = OrConvolution(node->left->dp, node->right->dp);
			for(int i = 0; i < (1 << N); ++i) node->dp[i] = add(node->dp[i], t[i]);
		}	
	}
}
void solve() {
	for(char z = 'A'; z <= 'D'; ++z) {
		int tbl = 0;
		for(int msk = 0; msk < N; ++msk) {
			int bt = (msk >> (z - 'A')) & 1;
			tbl |= bt << msk;
		}
		VarTable[z] = tbl;
	}
	for(char z = 'a'; z <= 'd'; ++z) {
		int tbl = 0;
		for(int msk = 0; msk < N; ++msk) {
			int bt = (msk >> (z - 'a')) & 1;
			tbl |= (bt ^ 1) << msk;
		}
		VarTable[z] = tbl;
	}
	cin >> S;
	Node* root = Expr();
	calc(root);
	int answ = 0;
	int n = fetch<int>();
	map<int, int> must;
	for(int i = 0; i < n; ++i) {
		int msk = 0;
		msk += fetch<int>();
		msk += 2 * fetch<int>();
		msk += 4 * fetch<int>();
		msk += 8 * fetch<int>();
		int bt = fetch<int>();
		must[msk] = bt;
	}
	for(int i = 0; i < (1 << N); ++i) {
		int good = 1;
		for(auto& PR: must) {
			int have = (i >> PR.first) & 1;
			if(have != PR.second) {
				good = 0;
				break;
			}
		}
		if(good) answ = add(answ, root->dp[i]);
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}