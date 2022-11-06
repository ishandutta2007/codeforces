#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll m[6],n;
	cin>>m[0]>>m[1];
	cin>>n;
	m[2]=m[1]-m[0];
	m[3]=-m[0];
	m[4]=-m[1];
	m[5]=-m[2];
	n=m[(n-1)%6];
	while(n<0)
	n+=1000000007;
	cout<<n%1000000007;
	return 0;
}