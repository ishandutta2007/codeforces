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
#include <queue>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const int maxn=100100,inf=1e9+7;

int x1,x2,a,b,d;
bool f;


int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> x1 >> x2 >> a >> b;
	if (a>b) swap(a,b);
	d=x2-x1;
	if (b<0) {
		d=-d;
		swap(a,b);
		a=-a; b=-b;
		f=true;
	}
	if (d>=a && d<=b) {
		cout << "FIRST" << endl << x2;
		return 0;
	}
	if (a<=0 && b>=0) {
		cout << "DRAW" << endl;
		return 0;
	}
	if (d<0) {
		cout << "DRAW";
		return 0;
	}
	if (d%(a+b)==0) {
		cout << "SECOND";
		return 0;
	}
	if (d%(a+b)>=a && d%(a+b)<=b) {
		cout << "FIRST" <<endl;
		int k=d%(a+b);
		/*if (f) {
			swap(a,b);
			a=-a; b=-b;
		}*/
		cout << x1+k*(f?-1:1);
		return 0;
	}
	cout << "DRAW";
	return 0;
}