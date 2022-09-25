#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const int maxn=0;

int n,a,b;
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> n >> s;
	bool f=false;
	for (int i=0; i<n; i++) {
		if (s[i]!='4' && s[i]!='7') f=true;
		if (i<n/2) a+=s[i]-'0';
		else b+=s[i]-'0';
	}
	if (a!=b) f=true;
	if (f) cout << "NO";
	else cout << "YES";
	return 0;
}