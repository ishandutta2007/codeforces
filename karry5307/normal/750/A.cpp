#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll nt,tt,cnt,k;
int main()
{
	cin>>cnt>>tt;
	nt=240-tt;
	for(register int i=1;i<=cnt&&nt-5*i>=0;i++)
	{
		nt-=5*i;
		k++;
	}
	cout<<k;
}