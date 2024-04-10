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


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n;
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	getline(cin,s);
	int i=0;
	bool f=true, g=false;
	while (i<s.length()) {
		if (s.length()-i>=2 && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
			i+=3;
			if (!f) {
				f=true; g=true;
			}
		} else {
			if (g) cout << ' ';
			cout << s[i];
			i++;
			f=g=false;
		}
	}

	return 0;
}