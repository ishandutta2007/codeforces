#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define next next_sdf
#define prev prev_sdf
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;


template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> int sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int maxn = 1000006;

const ll inf = 1e18;

int n;
int a, b; 
int x[maxn];
vi divs;
ll ansd[maxn], ansnd[maxn];

void getdivs(int x)
{
	for (int i = 2; i * i <= x; i++) if (x % i == 0)
	{
		while (x % i == 0) x /= i;
		divs.pb(i);
	}
	if (x > 1) divs.pb(x);
}

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);
	scanf("%d", &n);
	scanf("%d%d", &a, &b);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);	
	getdivs(x[0]);
	getdivs(x[0] + 1);
	getdivs(x[0] - 1);
	getdivs(x[n - 1]);
	getdivs(x[n - 1] + 1);
	getdivs(x[n - 1] - 1);
	sort(all(divs));
	divs.resize(unique(all(divs)) - divs.begin());

	ll answer = inf;

	for (int _ = 0; _ < 2; _++)
	{

	for (auto d : divs) if (d > 1)
	{
		int found = n;
		for (int i = 0; i < n; i++)
		{
			if (i != 0) ansd[i + 1] = min(ansd[i], ansnd[i]) + a;
			else ansd[i + 1] = inf;
			if (x[i] % d == 0) ansnd[i + 1] = ansnd[i];
			else if ((x[i] + 1) % d == 0 || (x[i] - 1) % d == 0) ansnd[i + 1] = ansnd[i] + b;
			else {
				found = i;
				break;
			}
		}
		ll rad  = 0;
		ll rnd = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int o = min(i + 1, found);
			answer = min(answer, min(rnd, rad) + min(ansd[o], ansnd[o]) + (ll)a * (i - o + 1));
//			cout << "now " << i << ' ' << o << ' ' << answer << endl;
			rad = rad + a;
			if (x[i] % d == 0) 1;
			else if ((x[i] + 1) % d == 0 || (x[i] - 1) % d == 0) rnd = rnd + b;
			else break;
		}
//		cout << d << ' ' << answer << endl;
	}	


	reverse(x, x + n);

	}

	cout << answer << endl;
	
	return 0;
}