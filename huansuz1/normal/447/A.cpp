#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define ll long long

using namespace std;
int n , m , p , a[12345] , ans=-1;
int main() {
	cin >> p >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		a[ m % p ]++;
		if (a[ m % p ]>1 && ans==-1) ans=i+1;
	}
	
	cout<<ans;


}