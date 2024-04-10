#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll tot,cnt,best,size[(ll)(1e5+5)];
ll minn=-1;
int main()
{
	cin>>tot>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>size[i];
		if(tot%size[i]<minn)
		{
			minn=tot%size[i];
			best=i;
		}
	}
	cout<<best+1<<" "<<tot/size[best];
}