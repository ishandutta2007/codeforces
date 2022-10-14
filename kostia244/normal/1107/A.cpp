#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

int n, m;
string l, r;
char t;
vector<int> a;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	while(n--) {
		cin >> m;
		cin >> t;
		l = t;
		m--;
		r= "";
		while(m--) {
			cin >> t;
			r +=t;
		}
		if(r.size() == 1 && (r[0] - '0') <= (l[0] - '0'))
			cout << "NO\n";
		else {
			cout << "YES\n2\n" << l << " " << r << "\n";
		}

	}
}