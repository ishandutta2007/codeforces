#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	for(int i = 1; i <= 100; ++i){
		string s = to_string(i);
		string t = to_string(i + 1);
		if(s[0] - 48 == a && t[0] - 48 == b) return cout << s << ' ' << t, 0; 
	}
	
	cout << "-1";
}