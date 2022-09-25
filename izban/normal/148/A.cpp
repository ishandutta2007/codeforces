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
#define ll long long 

int n,m,k,p,l,d,ans;
string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> k >> l >> m >> n >> d;
	for (int i=1; i<=d; i++) 
		ans+=(!(i%k))||(!(i%l))||(!(i%m))||(!(i%n));
	cout << ans;
	return 0;
}