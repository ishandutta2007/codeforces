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

ll A[4],d;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A[1] >> A[2] >> A[3] >> d;
	sort(A + 1, A + 1 + 3);
	ll res = 0;
	if (A[2] - A[1] < d)res += d - A[2] + A[1];
	if (A[3] - A[2] < d)res += d - A[3] + A[2];
	cout << res << endl;
}