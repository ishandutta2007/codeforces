#include <iostream>
using namespace std;

string s;

int main() {
	cin >> s;
	if(s.size() == 1 && s[0] == '2') cout << "NO" << endl;
	else if((s[s.size()-1] - '0') & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}