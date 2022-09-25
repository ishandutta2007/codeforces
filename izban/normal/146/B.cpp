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

int getmask(int x) {
	string s;
	while (x) {
		if (x%10==4 || x%10==7) 
			s+='0'+x%10;
		x/=10;
	}
	reverse(s.begin(),s.end());
	return atoi(s.c_str());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> a >> b;
	for (int c=a+1; c>0; c++) {
		if (getmask(c)==b) {
			cout << c;
			return 0;
		}
	}
	return 0;
}