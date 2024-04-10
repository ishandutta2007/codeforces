#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	int n;
	cin >> n;

	while (n--) {
		cout << a << " " << b << "\n";
		string c, d;
		cin >> c >> d;
		if (a == c) {
			a = d;
		} else {
			b = d;
		}
	}
	cout << a << " " << b << "\n";

}