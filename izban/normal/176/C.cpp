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




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,m,x1,y1,x2,y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	bool f=max(abs(x1-x2),abs(y1-y2))>4;
	f=f||(max(abs(x1-x2),abs(y1-y2))==4 && min(abs(x1-x2),abs(y1-y2))>2);

	if (f) cout << "Second" << endl;
	else cout << "First" << endl;

	return 0;
}