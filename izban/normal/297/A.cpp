#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

string a, b;
int a1, a2;

bool slow_solve(string a, string b) {
	return 0;
}

string solve1() {
	a1 = 0;
	for (int i = 0; i < a.length(); i++) a1 += a[i] == '1';
	//for (int i = 0; i < b.length(); i++) a2 += b[i] == '1';
	string A = a;

	for (int i = 0; i < 3 * (int)A.size(); i++) {
		a = A;
		int j = 0, k = 0, par = a1, res = 1;
		//a1 -= a[i] == '1';
		if (i < (int)a.size() - (int)b.size()) continue;
		int add;
		for (add = 0; i + add < a.size(); add++) 
			if (a[i + add] != b[add]) res = 0;
		if (!res) continue;
		while (j + add < b.length()) {
			while (k < i && par%2 != (b[j + add] - '0'))
				par -= a[k++] == '1';
			if (k == i && par%2 != (b[j + add] - '0')) break;
			a += (char)(par%2 + '0');
			par += b[j + add] == '1';
			j++;
		}
		if (j + add == (int)b.length() && (int)a.length() - k >= b.length()) 
			return "YES";
	}
	return "NO";
}

string solve() {
	a1 = a2 = 0;
	for (int i = 0; i < a.length(); i++) a1 += a[i] == '1';
	for (int i = 0; i < b.length(); i++) a2 += b[i] == '1';
	a1 += a1 % 2;

	return (a1 >= a2 ? "YES" : "NO");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> a >> b)
		cout << solve() << endl;
	//bool f = slow_solve(a, b);
	
	return 0;
}