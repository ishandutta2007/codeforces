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

const int maxn=110;

int n,m;
string a[maxn];
int a1,a2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	for (a1=0; a1<n; a1++) {
		int cnt=0;
		for (int i=0; i<m; i++) 
			cnt+=a[a1][i]=='*';
		if (cnt==1) break;
	}

	for (a2=0; a2<m; a2++) {
		int cnt=0;
		for (int i=0; i<n; i++)
			cnt+=a[i][a2]=='*';
		if (cnt==1) break;
	}

	cout << a1+1 << ' ' << a2+1 << endl;

	return 0;
}