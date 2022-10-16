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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int kek;
	cin >> kek;
	string s;
	cin >> s;
	int a = 0, b = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			a++;
		} else {
			b++;
		}
	}
	if (a != b) {
		cout << "No";
		return 0;
	}

	int count1 = 0;
	int balance = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			balance++;
		} else {
			if (balance == 0) {
				count1++;
				if (count1 == 2) {
					break;
				}
			} else {
				balance--;
			}

		}
	}

	if (count1 > 1) {
		cout << "No";
	} else {
		cout << "Yes";
	}
}