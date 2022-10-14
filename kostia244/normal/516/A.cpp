#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1<<18, mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	char c;
	cin >> n;
	string s;
	while(n--) {
		cin >> c;
		if(c == '2') s += "2";
		if(c == '3') s += "3";
		if(c == '4') s += "322";
		if(c == '5') s += "5";
		if(c == '6') s += "53";
		if(c == '7') s += "7";
		if(c == '8') s += "7222";
		if(c == '9') s += "7332";
	}
	sort(begin(s), end(s), greater<>());
	cout << s << '\n';
}