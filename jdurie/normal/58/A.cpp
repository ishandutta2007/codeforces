#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	string s, t = "hello";
	ll i = 0;
	cin >> s;
	for(char c : s) if(i < 5 && c == t[i]) i++;
	cout << (i == 5 ? "YES" : "NO") << endl;
	return 0;
}