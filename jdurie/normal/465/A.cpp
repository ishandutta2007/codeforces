#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ll n, i = 0;
	cin >> n;
	string s;
	cin >> s;
	while(s[i] == '1' && i < n) i++;
	cout << (i == n ? n : i + 1) << endl;
	return 0;
}