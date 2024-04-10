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


int n,k,l,c,d,p,nl,np;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	cout << min(c*d,min(p/np,k*l/nl))/n;
	return 0;
}