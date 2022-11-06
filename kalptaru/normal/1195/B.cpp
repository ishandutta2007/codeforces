#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k,t,a;
	cin>>n>>k;
	t=pow((9+8*(k+n)),0.5);
	a=2*n+3-t;
	cout<<(a>>1);
	return 0;
}