#include<iostream> 
#include<string>
#include<algorithm> 



using namespace std;

int32_t main() {
	string s;
	cin >> s;
	int q;
	cin >> q;
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		k %= (r - l);
		rotate(s.begin() + l, s.begin() + r - k, s.begin() + r);
	}
	cout << s << endl;
}