//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s11, s12, s21, s22;
	cin >> s11 >> s12 >> s21 >> s22;
	string s1 = s11 + s12[1] + s12[0];
	string s2 = s21 + s22[1] + s22[0];
	s1.erase(s1.find('X'), 1);
	s2.erase(s2.find('X'), 1);
	//cerr << s1 << " " << s2;
	for (int i = 0; i < 3; ++i) {
	  if (s1 == s2.substr(i) + s2.substr(0, i)) {
	    cout << "YES" << endl;
	    return 0;
	  }
	}
	cout << "NO" << endl;
	return 0;
}