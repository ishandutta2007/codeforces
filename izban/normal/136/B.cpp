#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,k;
string s;

int a,b,c;
vector <int> a1,b1,c1;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> a >> c;
	while (a) {
		a1.push_back(a%3);
		a/=3;
	}
	while (c) {
		c1.push_back(c%3);
		c/=3;
	}
	for (int i=min(a1.size(),c1.size()); i<max(a1.size(),c1.size()); i++) {
		if (a1.size()==i) a1.push_back(0);
		else if (c1.size()==i) c1.push_back(0);
	}
	for (int i=0; i<c1.size(); i++) {
		for (int j=0; j<3; j++) 
			if ((a1[i]+j)%3==c1[i]) b1.push_back(j);
	}
	int k=1;
	for (int i=0; i<b1.size(); i++) {
		b+=b1[i]*k;
		k*=3;
	}
	cout << b;
	return 0;
}