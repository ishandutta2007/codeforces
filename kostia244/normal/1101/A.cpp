#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

int q, l, r, d;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> q;
	while(q--) {
		cin >> l >> r >> d;
		if(d < l)
			cout << d << "\n";
		else
			cout << (((r/d) + 1) * d) << "\n";
	}

}