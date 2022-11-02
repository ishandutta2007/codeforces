#include <iostream>
#include <string>
using namespace std;

bool ck(string s)
{
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') c++;
		else c--;
		if (c < 0) return false;
	}
	return (c == 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	bool f = false;
	if (ck(s)) f = true;
	int p = 0;
	for (int i = (int)s.length() - 1; i >= 0; i--)
		if (s[i] == '(') {
			p = i;
			break;
		}
	string ts = ""; ts += s[p];
	for (int i = 0; i < s.length(); i++)
		if (p != i)
			ts += s[i];
	if (ck(ts)) f = true;
	p = (int)s.length() - 1;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ')') {
			p = i;
			break;
		}
	ts = "";
	for (int i = 0; i < s.length(); i++)
		if (p != i)
			ts += s[i];
	ts += s[p];
	if (ck(ts)) f = true;
	if (f) cout << "Yes" << '\n';
	else cout << "No" << '\n';
	return 0;
}