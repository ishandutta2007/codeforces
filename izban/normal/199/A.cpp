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
vector<int> v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	if (n==0) cout << "0 0 0"; else
	if (n==1) cout << "1 0 0"; else
	if (n==2) cout << "1 1 0"; else 
	if (n==3) cout << "1 1 1"; else
	if (n==5) cout << "3 1 1"; else{
		v.push_back(0);
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		while (v[v.size()-1]+v[v.size()-2]<n) {
			v.push_back(v[v.size()-1]+v[v.size()-2]);
		}
		cout << v[v.size()-1] << ' ' << v[v.size()-3] << ' ' << v[v.size()-4];
	}

	return 0;
}