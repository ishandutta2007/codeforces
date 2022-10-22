#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define pill pair<ll, ll>
#define s second
#define ld long double
using namespace std;

const ll N = 4e5 + 10;
const ll mod = 998244353;
const ll big = 1e4;
const double eps = 1e-8;

ll t;
ll n, z;
ll a[N];

int main() {
	speed;
	cin >> t;	
	while(t--) {
		cin >> n >> z;
		ll sub = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i], sub = max(sub, a[i] | z);
		cout << sub << '\n';
	}
}
/*
3
1 0
3 0
5 0

*/