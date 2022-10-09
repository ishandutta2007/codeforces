#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[10] = {
	"O-|-OOOO",
	"O-|O-OOO",
	"O-|OO-OO",
	"O-|OOO-O",
	"O-|OOOO-",
	"-O|-OOOO",
	"-O|O-OOO",
	"-O|OO-OO",
	"-O|OOO-O",
	"-O|OOOO-",
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n == 0) {
		cout << s[0] << '\n';
		return 0;
	}

	while (n > 0) {
		cout << s[n % 10] << '\n';
		n /= 10;
	}
}