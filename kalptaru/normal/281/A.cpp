#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	char t;
	int n;
	cin>>a;
	t=a[0];
	n=t;
	if (t<93)
	{
		cout<<a;
	}
	else
	{
		t-=32;
		cout<<t<<a.substr(1,a.size());
	}
	
	
	return 0;
}