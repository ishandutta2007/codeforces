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
	int am1 = 0;
	int am2 = 0;
	cin >> s;
	for(const auto& el : s) {
		if(el >= 'a' && el <= 'z') {
			++am1;
		} else {
			++am2;
		}
	}
	for(auto& el : s) {
		if(am1 >= am2) {
			if(el >= 'A' && el <= 'Z') {
				el -= 'A';
				el += 'a';
			}
		} else {
			if(el >= 'a' && el <= 'z') {
				el -= 'a';
				el += 'A';
			}
		}
		cout << el;
	}
}