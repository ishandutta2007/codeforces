#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

bool c[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	ll n, k, ways = 0, curr = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	for(ll i = 0; i < k; i++) {
		char ch = ' ';
		while(ch == ' ')
		cin >> ch;
		c[ch - 'a'] = true;
	}
	for(char ch : s)
		if(c[ch - 'a']) {
			curr++;
		} else {
			ways += (curr + 1) * curr / 2;
			curr = 0;
		}
	ways += (curr + 1) * curr / 2;
	cout << ways << endl;
}