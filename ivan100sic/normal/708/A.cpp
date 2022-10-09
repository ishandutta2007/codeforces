#include "bits/stdc++.h"
using namespace std;

string s, q;

int main(){
	cin >> s;
	q = s;
	int f = 0;
	for (char& x : s){
		if (f == 0 && x != 'a'){
			f = 1;
			x--;
		} else
		if (f == 1 && x == 'a'){
			f = 2;
		} else if (f == 1){
			x--;
		}
	}
	if (q == s) *s.rbegin() = 'z';
	cout << s;



	return 0;
}