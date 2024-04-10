// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string ms[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;
	int k;
	cin >> k;
	k += find(ms, ms+12, s) - ms;
	cout << ms[k%12] << '\n';
}