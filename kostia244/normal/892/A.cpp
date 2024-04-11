#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m1 = 0, m2 = 0, s = 0, t;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(ll i = 0; i < n; i++)
		cin >> t, s += t;
	for(ll i = 0; i < n; i++) {
		cin >> t;
		if(t > m1)
			m2 = m1, m1 = t;
		else if(t > m2)
			m2 = t;
	}
	cout << ((m1 + m2) >= s ? "YES" : "NO");
}