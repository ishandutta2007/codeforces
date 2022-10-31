#include <bits/stdc++.h>

using namespace std;
#define DIM  2007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};

ll k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	ll r = 0, p=0,num = 0;
	while (r < k) {
		p++;
		r += 9 * pow(10, p - 1)*p;
		num += 9 * pow(10, p - 1);
	}
	ll cof = (r - k)/p;
	//if ((r - k) % p != 0)cof++;
	num -= cof;
	r -= cof * p;
	k = r-k;
	k++;
	ll sym = 1;
	while (1) {
		if (sym == k) {
			cout << num % 10 << endl;
			break;
		}
		num /= 10;
		sym++;
	}
}