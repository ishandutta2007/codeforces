#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <memory.h>
#include <string>
using namespace std;
string inp;
int d,m,y,X,Y,Z;
int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


bool can(int dd, int mm, int yy) {
	bool res = 1;
	if (yy % 4 == 0) a[2] = 29;
	if (mm < 1 || mm > 12) res = 0;
	if (dd < 1 || dd > a[mm]) res = 0;
	a[2] = 28;
	if (!res) return 0;
	
	if (mm == 2 && dd == 29 && (y % 4 != 0)) {
		mm = 3;
		dd = 1;
	}
	
	if (yy >= y) return 0;
	if (y - yy > 18) return 1;
	if (y - yy != 18) return 0;
	if (mm < m || (mm == m && dd <= d)) return 1;
	return 0;
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	cin >> inp;
	d = (inp[0]-'0')*10 + inp[1] - '0';
	m = (inp[3]-'0')*10 + inp[4] - '0';
	y = (inp[6]-'0')*10 + inp[7] - '0';
	
	int a[3];
	cin >> inp;
	X = (inp[0]-'0')*10 + inp[1] - '0';
	Y = (inp[3]-'0')*10 + inp[4] - '0';
	Z = (inp[6]-'0')*10 + inp[7] - '0';
	
	if (can(X,Y,Z)) {
		puts("YES");
		return 0;
	}
	if (can(X,Y,Z)) {
		puts("YES");
		return 0;
	}
	if (can(X,Z,Y)) {
		puts("YES");
		return 0;
	}
	if (can(Y,X,Z)) {
		puts("YES");
		return 0;
	}
	if (can(Y,Z,X)) {
		puts("YES");
		return 0;
	}
	if (can(Z,X,Y)) {
		puts("YES");
		return 0;
	}
	if (can(Z,Y,X)) {
		puts("YES");
		return 0;
	}
	
	puts("NO");
	
	return 0;
}