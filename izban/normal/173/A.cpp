#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int n,m,k;
int x1,x2,ansa,ansb;
string a,b;

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

int f(char b, char a) {
	return a=='R' && b=='S' || a=='S' && b=='P' || a=='P' && b=='R';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	cin >> a >> b;
	m=a.length();
	k=b.length();
	int x=m*k/gcd(m,k);

	for (int i=0; i<x; i++) {
		x1+=f(a[i%m],b[i%k]);
		x2+=f(b[i%k],a[i%m]);
	}
	ansa+=(n/x)*x1;
	ansb+=(n/x)*x2;
	for (int i=0; i<n%x; i++) {
		ansa+=f(a[i%m],b[i%k]);
		ansb+=f(b[i%k],a[i%m]);
	}
	cout << ansa << ' ' << ansb;
	return 0;
}