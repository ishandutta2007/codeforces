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
pair<int,int> a[maxn];
set<pair<int,int> > s;

pair<int,int> f(int a, int b) {
	if (a<0) {
		a*=-1; b*=-1;
	}
	int g=gcd(a,b);
	a/=g; b/=g;
	return make_pair(a,b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first!=0) {
			s.insert(f(a[i].first,a[i].second));
		}
	}
	cout << s.size();
	return 0;
}