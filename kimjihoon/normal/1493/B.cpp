#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };
int h, m;

bool ps(string s)
{
	for (int i = 0; i < 5; i++) 
		if (i != 2 && r[s[i] - '0'] == -1)
			return false;
	int hp = r[s[4] - '0'] * 10 + r[s[3] - '0'];
	int mp = r[s[1] - '0'] * 10 + r[s[0] - '0'];
	if (hp >= h || mp >= m) return false;
	return true;
}

string nt(string s) {
	int hp = (s[0] - '0') * 10 + (s[1] - '0');
	int mp = (s[3] - '0') * 10 + (s[4] - '0');
	mp++;
	if (mp == m) {
		hp++; mp = 0;
	}
	if (hp == h) hp = 0;
	string r = "";
	r += (char)((hp / 10) + '0');
	r += (char)((hp % 10) + '0');
	r += ":";
	r += (char)((mp / 10) + '0');
	r += (char)((mp % 10) + '0');
	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> h >> m;
		string s; cin >> s;
		while (!ps(s)) 
			s = nt(s);
		cout << s << '\n';
	}
	return 0;
}