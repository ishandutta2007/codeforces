#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

	int n;
	cin >> n;

	int a = 0, b = 0;

	while (n--) {
		char c;
		cin >> c;
		if (c == 'A') {
			++a;
		} else {
			++b;
		}
	}

	if (a == b) {
		cout << "Friendship\n";
	} else if (a > b) {
		cout << "Anton\n";
	} else {
		cout << "Danik\n";
	}

}