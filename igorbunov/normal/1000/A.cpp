//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
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

using namespace std;

#define int long long

signed main() {
	int n;
	cin >> n;
	int m1 = 0;
	int s1 = 0;
	int xs1 = 0;
	int xxs1 = 0;
	int xxxs1 = 0;
	int l1 = 0;
	int xl1 = 0;
	int xxl1 = 0;
	int xxxl1 = 0;
	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;
		if (b == "M") {
			m1++;
		}
		if (b == "S") {
			s1++;
		}
		if (b == "XS") {
			xs1++;
		}
		if (b == "XXS") {
			xxs1++;
		}
		if (b == "XXXS") {
			xxxs1++;
		}

		if (b == "L") {
			l1++;
		}
		if (b == "XL") {
			xl1++;
		}
		if (b == "XXL") {
			xxl1++;
		}
		if (b == "XXXL") {
			xxxl1++;
		}
	}

	int m2 = 0;
	int s2 = 0;
	int xs2 = 0;
	int xxs2 = 0;
	int xxxs2 = 0;
	int l2 = 0;
	int xl2 = 0;
	int xxl2 = 0;
	int xxxl2 = 0;
	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;
		if (b == "M") {
			m2++;
		}
		if (b == "S") {
			s2++;
		}
		if (b == "XS") {
			xs2++;
		}
		if (b == "XXS") {
			xxs2++;
		}
		if (b == "XXXS") {
			xxxs2++;
		}

		if (b == "L") {
			l2++;
		}
		if (b == "XL") {
			xl2++;
		}
		if (b == "XXL") {
			xxl2++;
		}
		if (b == "XXXL") {
			xxxl2++;
		}
	}
	int ans = 0;




	if (m1 < m2) {
		while (s1 > s2 && m1 != m2) {
			s1--;
			m1++;
			ans++;
		}
		//cout << m1 << s1 << l1 << endl;
		ans += abs(s1 - s2);
		ans += abs(m1 - m2);
	} else {
		swap(m1, m2);
		swap(s1, s2);
		while (s1 > s2 && m1 != m2) {
			s1--;
			m1++;
			ans++;
		}
		ans += abs(s1 - s2);
		ans += abs(m1 - m2);
	}
	//cout << ans << endl;
	ans += abs(xl2 - xl1);
	ans += abs(xxl2 - xxl1);
	ans += abs(xxxl2 - xxxl1);
	cout << ans;
}