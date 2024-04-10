#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string str[3];
string A, sb;
int mv;

char get(char sb) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < str[i].length(); j++) {
			if (str[i][j] == sb) return str[i][j + mv];
		}
	}
}

int main() {
	str[0] = "qwertyuiop";
	str[1] = "asdfghjkl;";
	str[2] = "zxcvbnm,./";
	cin >> A >> sb;
	if (A[0] == 'L') mv = 1;
	else mv = -1;
	for (int i = 0; i < sb.length(); i++) {
		cout << get(sb[i]);
	}
	cout << endl;
	return 0;
}