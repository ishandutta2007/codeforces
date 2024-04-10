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
const ll q=1000000000+7;


int n;
string s;
int c[300];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s;
	for (int i=0; i<s.length(); i++) {
		c[s[i]]++;
	}
	for (int i=0; i<s.length(); i++) {
		bool f=true;
		for (char j=s[i]+1; j<='z'; j++) if (c[j]) f=false;
		if (f) cout << s[i];
		c[s[i]]--;
	}

	return 0;
}