#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string s;
	cin >> s;
	set<char> s1;
	for(auto& el : s) {
		if(el < 'a') {
			el -= 'A';
			el += 'a';
		}
		s1.insert(el);
	}
	if(s1.size() % 2 == 0) {
		cout << "CHAT WITH HER!";
	} else {
		cout << "IGNORE HIM!";
	}
}