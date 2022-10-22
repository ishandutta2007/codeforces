#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k;
	cin >> n >> m >> k;
	cout << ((k+n-1)/k)*((m+k-1)/k);
	return 0;
}