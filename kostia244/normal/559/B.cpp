#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define __V vector
#define vi __V
using namespace std;
string a, b;

string p(string s) {
	if (s.size() & 1)
		return s;
	string s1 = p(s.substr(0, s.size() / 2));
	string s2 = p(s.substr(s.size() / 2, s.size()));
	if (s1 < s2)
		return s1+s2;
	else
		return s2 + s1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> a >> b;
	string sa = p(a);
	string sb = p(b);
	if (sa == sb)
		cout << "YES";
	else
		cout << "NO";
}