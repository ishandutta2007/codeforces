#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
#define MAX 100010

int t, x, y, mx, my;
char c;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> c >> x >> y;
		if (c == '+') {
			if(x < y)
				swap(x, y);
			if(x > mx)
				mx = x;
			if(y > my)
				my = y;

		} else {
			if((mx <= x && my <= y) || (my <= x && mx <= y)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

}