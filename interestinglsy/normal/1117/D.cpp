#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c)	c.begin(), c.end()
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {cout << "\n";}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " : " << a << " | "; err(++it, args...);}

typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<lli, lli> > vplli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tree <lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update >ordered_set;

#define PI 3.141592653589793
#define mod (lli)(1000*1000*1000+7)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
const int N = 100010;


void add(lli& a, lli b) {
	a=(a % mod + b % mod) % mod;
}

lli sub(lli a, lli b) {
	a -= b;
	if (a < 0)	a += mod;
	return a;
}

lli mult(lli a, lli b) {
	return (((a % mod) * (b % mod)) % mod);
}

lli power(lli a, lli b) {
	lli v = pow(a, b, mod);
	return v;
}

void print(vvlli& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			cout << arr[i][j] << " \n"[j == arr.size() - 1];
		}
	}
}

void mult(vvlli& a, vvlli& b) {
	vvlli c(a.size(), vlli(b[0].size(), 0ll));
	for (int r = 0; r < a.size(); ++r) {
		for (int j = 0; j < b[0].size(); ++j) {
			for (int x = 0; x < b.size(); ++x) {
				c[r][j]+= mult(a[r][x], b[x][j]);
				if( c[r][j] >= mod )
				c[r][j] -= mod;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			a[i][j] = c[i][j];
		}
	}
}

void pow(vvlli& arr, lli n) {
	if (n <= 1) return;

	if (n & 1) {
		vvlli temp(arr.size(), vlli(arr[0].size(), 0ll));
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[0].size(); j++) {
				temp[i][j] = arr[i][j];
			}
		}
		pow(arr, n / 2ll);
		mult(arr, arr);
		mult(arr, temp);
	} else {
		pow(arr, n / 2ll);
		mult(arr, arr);
	}
}

int main() {
	fio;
	lli n, m;
	cin >> n >> m;
	//take 1 or m
	// answer(n-1) + answer(n-m)
	if (n - m < 0) {
		// 1 1 1 1 1 1 1 1...
		cout << "1\n";
		return 0;
	}

	vvlli cof(m, vlli(m, 0ll));
	cof[0][0] = 1;
	cof[0][m - 1] = 1;
	for (int i = 1; i < cof.size(); i++) {
		cof[i][i - 1] = 1;
	}

	pow(cof, n - m + 1);
	lli ans = 0ll;
	for (int i = 0; i < m; i++){
		ans=ans+cof[0][i];
		ans%=mod;
	}
	cout << ans << "\n";
}