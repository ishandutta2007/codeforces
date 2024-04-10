#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[509];

int qry(string s)
{
	cout << "? " << s << endl;
	int t; cin >> t;
	return t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	string s = "";
	for (int i = 0; i < m; i++)
		s += "0";
	for (int i = 0; i < m; i++) {
		s[i] = '1';
		p[i].first = qry(s);
		p[i].second = i;
		s[i] = '0';
	}
	sort(p, p + m);
	int ss = 0;
	for (int i = 0; i < m; i++) {
		s[p[i].second] = '1';
		int t = qry(s);
		if (t == ss + p[i].first)
			ss = t;
		else
			s[p[i].second] = '0';
	}
	cout << "! " << ss << endl;
	return 0;
}