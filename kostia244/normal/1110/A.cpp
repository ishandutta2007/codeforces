#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int b, k, c = 0, t;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> b >> k;
	while(k--) {
		cin >> t;
		if(b&1)
			c += (t&1);
	}
	if((b&1) == 0)
		cout << (t&1 ? "odd" : "even");
	else {
		cout << (c&1 ? "odd" : "even");
	}
}