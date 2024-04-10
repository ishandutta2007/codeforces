#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, mod = 1000003;

int main()
{
	cin >> n;
	ll cur = 1;
	for (int i = 1; i < n; i++)
		cur = cur*3%mod;
	cout<<cur;	
};