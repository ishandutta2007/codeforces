#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	int b[n];
	rep(i, 0, n) cin >> b[i];
	int ptr1 = 0;
	rep(i, 0, n) if (a[i] == 1) {
		ptr1 = i;
		break;
	}
	int ptr2 = 0;
	rep(i, 0, n) if (b[i] == 1) {
		ptr2 = i;
		break;
	}

	bool good = true;

	do {
		ptr1 = (ptr1+1)%n;
		if (a[ptr1] == 0) ptr1 = (ptr1+1)%n;

		ptr2 = (ptr2+1)%n;
		if (b[ptr2] == 0) ptr2 = (ptr2+1)%n;

		//cout << a[ptr1] << 
		if (a[ptr1] != b[ptr2]) good = false;
	} while (a[ptr1] != 1);

	if (good) cout << "YES" << endl;
	else cout << "NO" << endl;
}