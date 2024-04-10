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

string a,b;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> a >> b;
	int x=0,y=0;
	for (int i=0; i<a.length(); i++) {
		if (a[i]!=b[i] && a[i]=='4') x++;
		if (a[i]!=b[i] && a[i]=='7') y++;
	}
	cout << max(x,y);
	return 0;
}