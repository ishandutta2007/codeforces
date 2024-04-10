#include <bits/stdc++.h>

using namespace std;

// const int N = ;
int n, k, m;
string s, ans;

int cb(int l, int r) {
	if(l == r) return l;
	int mid = (l + r ) / 2;
	cout << "? " << r << ' ' << mid << endl;
	fflush(stdout);
	cin >> ans;
	if(ans == "y") return cb(mid + 1, r);
	return cb(l, mid);
}

int play() {
	int c = 1;
	while(true) {
		cout << "? " << c << ' ' << c * 2 << endl;
		fflush(stdout);
		cin >> ans;
		if(ans == "x") {
			return cb(1, c * 2);
		} 
		else c *= 2;
	}

}

int main() {
	// ios_base::sync_with_stdio(false);

	cin >> s;
	while(s == "start") {
		int ret = play();
		cout << "! " << ret << endl;
		fflush(stdout);
		cin >> s;
		if(s != "start") break;
	}
	return 0;
}