#include<iostream>
#include<algorithm>

using namespace std;

string s;

int main () {
	cin >> s;
	cout << s;
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}