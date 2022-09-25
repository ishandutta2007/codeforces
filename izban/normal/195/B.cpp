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
const double eps=1e-9;


int n,m;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> m >> n;
	int cur=0, wh, i=1;
	while (cur<m) {
		if (cur%n==0) { wh=(n+1)/2; i=1; }
		cur++;
		cout << wh << endl;
		if (n/2.0-wh>-eps) wh+=i;
		else wh-=i;
		i++;
	}

	return 0;
}