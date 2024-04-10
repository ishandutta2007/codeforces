#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;

int lg(int ul, int ur, int sd) {
	while (ul + ur) {
		if (ur) {
			sd -= 9;
			ur--;
		} else {
			ul--;
		}

		if (ul) {
			sd += 9;
			ul--;
		} else {
			ur--;
		}
	}
	return sd;
}

int hg(int ul, int ur, int sd) {
	return -lg(ur, ul, -sd);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	int ul=0, ur=0, sd=0;
	for (int i=0; i<n; i++) {
		bool l = i < n/2;
		if (s[i] == '?')
			(l ? ul : ur)++;
		else
			sd += (l ? 1 : -1) * (s[i] - '0');
	}

	int x = lg(ul, ur, sd);
	if (x < 0)
		cout << "Monocarp\n";
	else {
		x = hg(ul, ur, sd);
		if (x > 0)
			cout << "Monocarp\n";
		else
			cout << "Bicarp\n";
	}
		
}