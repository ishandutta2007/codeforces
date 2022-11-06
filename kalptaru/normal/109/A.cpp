#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,c=0;
		cin>>n;
		while(n%7!=0 && n>0)
		{
			n-=4;
			c++;
		}
		if(n<0)
		cout<<-1;
		else
		{
			FOR(i,0,c)
			cout<<4;
			FOR(i,0,n/7)
			cout<<7;
		}
	}
}