// hloya template v21

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

//clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("moocast.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x, int st = 2){
	string ans = "";
	while (x > 0){
		ans += char('0' + x % st);
		x /= st;
	}
	reverse(ans.begin(), ans.end());
	return ans.empty() ? "0" : ans;
}

// char input() {
// 	char c = getchar();
// 	do { c = getchar(); } while (c <= ' ');
// 	return c;
// }

// string input() {
// 	string ans = "";
// 	char c = endl;
// 	while (c == endl || c == ' ')
// 		c = getchar();
// 	while (c != endl && c != ' ' && c)
// 		ans += c, c = getchar();
// 	return ans;
// }

template<typename T>
T input(){
	T ans = 0, m = 1;
	char c = ' ';

	while (!((c >= '0' && c <= '9') || c == '-')) {
		c = getchar();
	}

	if (c == '-')
		m = -1, c = getchar();
	while (c >= '0' && c <= '9'){
		ans = ans * 10 + (c - '0'), c = getchar();
	}
	return ans * m;
}

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 1e3 + 44, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

template<typename T>
T binpow(T n, T s)
{
	if (s <= 0)
		return 1LL;
	if (s % 2 == 0){
		T b = binpow(n, s / 2);
		return ( 1LL * b * b ) % base;
	} else {
		return (1LL* binpow(n, s - 1) * n) % base;
	}
}

int main() {
	string s;
	cin >> s;
	cin >> s;

	if ((int)s.size() % 4)
		return cout << "===", 0;

	map<char, int> cnt;
	cnt['A'] = 0, cnt['G'] = 0, cnt['C'] = 0, cnt['T'] = 0;

	for (char c:s) {
		if (c == '?')
			continue;
		cnt[c]++;
	}
	for (auto e:cnt)
		if (e.s > (int)s.size() / 4)
			return cout << "===", 0;
		
	for (char& c:s)
		if (c == '?') {
			if (cnt['A'] != (int)s.size() / 4)
				c = 'A';
			else if (cnt['G'] != (int)s.size() / 4)
				c = 'G';
			else if (cnt['C'] != (int)s.size() / 4)
				c = 'C';
			else c = 'T';
			cnt[c]++;
		}
	cout << s;
	return 0;
}