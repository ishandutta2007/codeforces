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
string s,ans="a";

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s;
	n=s.length();
	for (int mask=0; mask<1<<n; mask++) {
		string cur="";
		for (int i=0; i<n; i++) 
			if (mask&(1<<i)) 
				cur+=s[i];
		string cur2=cur;
		reverse(cur2.begin(),cur2.end());
		if (cur==cur2) ans=max(ans,cur);
	}
	cout << ans;

	return 0;
}