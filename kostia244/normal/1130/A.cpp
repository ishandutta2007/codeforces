#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,tn, t, p, ng;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	tn = n;
	p = ng = 0;
	while(tn--) {
		cin >> t;
		if(t > 0)
			p++;
		if(t < 0)
			ng++;
	}
	if(p >= (n+1)/2)
		cout << 1;
	else if(ng >= (n+1)/2)
		cout << -1;
	else
		cout << 0;
}