#include <iostream>
#include <string>
using namespace std;

int n, ans[209], v1[209], v2[209];
string s[209];

bool ps(string sp)
{
	for (int i = 0; i < 2 * (n - 1); i++) {
		if (s[i] == sp.substr(0, s[i].length()) && s[i] == sp.substr(n - s[i].length(), s[i].length())) ans[i] = 0;
		else if (s[i] == sp.substr(0, s[i].length())) ans[i] = 1;
		else if (s[i] == sp.substr(n - s[i].length(), s[i].length())) ans[i] = 2;
		else return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	string sa = "", sb = "";
	for (int i = 0; i < 2 * (n - 1); i++) {
		cin >> s[i];
		if (s[i].length() == n - 1) {
			if (sa == "") sa = s[i];
			else sb = s[i];
		}
	}
	if (sa.substr(1, n - 2) == sb.substr(0, n - 2) && ps(sa[0] + sb)) {}
	else
		ps(sb + sa[n - 2]);
	for (int i = 0; i < 2 * (n - 1); i++) {
		if (ans[i] == 1) v1[s[i].length()] = 1;
		else if (ans[i] == 2) v2[s[i].length()] = 1;
	}
	for (int i = 0; i < 2 * (n - 1); i++) {
		if (ans[i] == 1) cout << "P";
		else if (ans[i] == 2) cout << "S";
		else {
			if (v1[s[i].length()] == 0) {
				cout << "P"; v1[s[i].length()] = 1;
			}
			else {
				cout << "S"; v2[s[i].length()] = 1;
			}
		}
	}
	cout << '\n';
	return 0;
}