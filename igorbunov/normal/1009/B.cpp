#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	string s;
	cin >> s;
	string b;
	int count1 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			count1++;
		} else {
			b.push_back(s[i]);
		}
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '2') {
			for (int j = 0; j < count1; j++) {
				cout << '1';
			}
			count1 = 0;
		}
		cout << b[i];
	}
	for (int j = 0; j < count1; j++) {
		cout << '1';
	}
	cout << endl;
}