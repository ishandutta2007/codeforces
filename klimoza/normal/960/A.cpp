#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a_num, b_num, c_num;
	a_num = 0;
	b_num = 0;
	c_num = 0;
	int flag = 0;
	bool bl = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' and flag == 0) {
			a_num++;
		}
		else if (s[i] == 'a') {
			bl = false;
			break;
		}
		else if (s[i] == 'b' and a_num != 0 and flag <= 1) {
			flag = 1;
			b_num++;
		}
		else if (s[i] == 'b') {
			bl = false;
			break;
		}
		else if (s[i] == 'c' and b_num != 0 and flag >= 1) {
			flag = 2;
			c_num++;
		}
		else {
			bl = false;
			break;
		}
	}
	if ((c_num == a_num or c_num == b_num) and bl and flag == 2) cout << "YES";
	else cout << "NO";
}