#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n, x, y,res = 0;
string num;
int main() {
	cin >> n >> y >> x;
	cin >> num;
	n--;
	ll ci = n - y;
	
	for (int i = ci+1; i <= n; i++) {
		if (n - i == x) {
			if (num[i] == '0')res++;
		}
		else {
			if (num[i] == '1')res++;
		}
	}
	cout << res << endl;
}