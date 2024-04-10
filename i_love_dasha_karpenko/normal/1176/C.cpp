#include <bits/stdc++.h>

using namespace std;
#define DIM  307
#define DIM2 107
#define INF 10E16
#define MAXN 107
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
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
ll t, n;
queue<ll> V1, V2, V3, V4, V5, V6;	
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ll x;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x == 4)V1.push(i);
		else if (x == 8)V2.push(i);
		else if (x == 15)V3.push(i);
		else if (x == 16)V4.push(i);
		else if (x == 23)V5.push(i);
		else if (x == 42)V6.push(i);
	}
	while (!(V1.empty() || V2.empty() || V3.empty() || V4.empty() || V5.empty() || V6.empty())) {
		while (!V2.empty() && V2.front() < V1.front())V2.pop();
		while (!V3.empty() && V3.front() < V2.front())V3.pop();
		while (!V4.empty() && V4.front() < V3.front())V4.pop();
		while (!V5.empty() && V5.front() < V4.front())V5.pop();
		while (!V6.empty() && V6.front() < V5.front())V6.pop();
		if (!(V1.empty() || V2.empty() || V3.empty() || V4.empty() || V5.empty() || V6.empty())) {
			res += 6; V1.pop(); V2.pop(); V3.pop(); V4.pop(); V5.pop(); V6.pop();
		}	
	}
	cout << n - res << endl;
}