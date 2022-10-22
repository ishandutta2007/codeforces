#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,l1,r1,l2,r2,i;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>l1>>r1>>l2>>r2;
		if(l1==r2)
			cout<<r1<<" "<<l2<<"\n";
		else
			cout<<l1<<" "<<r2<<"\n";
	}
	return 0;
}