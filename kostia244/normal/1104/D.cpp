#include <bits/stdc++.h>
using namespace std;

string s;

void go(int l , int r) {
	cout << "? " << l << " " << r << "\n";
	cin >> s;
	cout.flush();
}

void go() {
	cin >> s;
	cout.flush();
}

int main() {
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(0);
	while(1) {
		go();
		if(s == "end" || s == "mistake" || s == "e")
			return 0;
		long long l = 0, r = 1;
		while(s != "x") {
			go(l, r);
			l = r;
			r *= 2;
		}
		l /= 2;
		r /= 2;
		while(l + 1 < r) {
			long long mid = (l + r) / 2;
			go(mid, r);
			if(s == "x")
				l = mid;
			else
				r = mid;
		}
		cout << "! " << r << "\n";
	}
}