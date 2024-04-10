//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = - 20 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, a, b;
vector <int> vec, V;

void check(int x, int y){
	int g = __gcd(x, y);
	for (int i = 1; i * i <= g; ++ i){
		if (g % i)
			continue;
		vec.push_back(i);
		vec.push_back(g / i);
	}
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> a >> b;
		vec.clear();
		check(a - 1, b - 1);
		check(a, b - 2);
		check(a - 2, b);
		vec.push_back(2);
		sort(all(vec));
		V.clear();
		for (int i = 0; i < SZ(vec); ++ i)
			if (!i || vec[i] != vec[i - 1])
				V.push_back(vec[i]);
		cout << SZ(V) << sep;
		for (int x : V)
			cout << x << sep;
		cout << endl;
	}

	return 0;
}