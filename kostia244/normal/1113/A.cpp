#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;//2 + 3 + 4
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, v, i = 2, a = 0, t = 1;
//2 + 2 + 2 +
int main() {
	cin >> n >> v;
	n--;
	a = t = min(v, n);
	for(;t < n;i++, t++) {
		a += i;
	}
	cout << a << "\n";
}