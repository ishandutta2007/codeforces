#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	float n,t,s=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		s+=t;
	}
	cout << std::fixed;
	cout << std::setprecision(10);
	cout<<s/n;
	return 0;
}