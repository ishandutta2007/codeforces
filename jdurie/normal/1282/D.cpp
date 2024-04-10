#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll resp;
    cout << "a" << endl;
	cout.flush();
	cin >> resp;
	if(!resp) return 0;
	if(resp == 300) {
		for(ll i = 0; i < 300; i++) cout << "b";
		cout << endl;
	}
	string s;
	for(ll i = 0; i <= resp; i++) s += "a";
	cout << s << endl;
	cout.flush();
	cin >> resp;
	if(resp == s.size()) {
		s = "";
		for(ll i = 0; i < resp - 1; i++) s += "b";
		cout << s << endl;
		return 0;
	}
	ll bs = resp;
	for(ll i = 0; i < s.size(); i++) {
		s[i] = 'b';
		cout << s << endl;
		cout.flush();
		cin >> resp;
		if(!resp) return 0;
		if(resp > bs) s[i] = 'a';
		else bs--;
	}
}