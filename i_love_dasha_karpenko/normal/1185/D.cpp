#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
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

ll n;
pll A[DIM];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A + 1, A + 1 + n);
	ll cn = 0;
	ll prev = A[3].first -A[2].first,flag = 0;
	for (int i = 4; i <= n; i++) {
		if (A[i].first - A[i - 1].first != prev) {
			flag = 1; break;
		}
	}
	if (flag == 0) {
		cout << A[1].second << endl;
		return 0;
	}
	prev = A[3].first - A[1].first, flag = 0;
	for (int i = 4; i <= n; i++) {
		if (A[i].first - A[i - 1].first != prev) {
			flag = 1; break;
		}
	}
	if (flag == 0) {
		cout <<A[ 2].second << endl;
		return 0;
	}
	prev = A[2].first - A[1].first; flag = 0; ll num = 0, last = A[2].first;
	for (int i = 3; i <= n; i++) {
		if (A[i].first - last != prev) {
			if (flag == 1) {
				cout << -1 << endl;
				return 0;
			}
			else {
				num = i;
				flag = 1;
			}
		}
		else last = A[i].first;
	}
	cout <<A[ num].second << endl;
}