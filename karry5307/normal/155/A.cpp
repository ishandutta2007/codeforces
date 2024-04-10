#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll minn=0x777777777777f,maxn,num,cnt,ans;
int main()
{
    cin>>cnt;
    cin>>num;
    minn=num;
    maxn=num;
    for(register int i=1;i<cnt;i++)
    {
    	cin>>num;
    	if(num<minn)
    	{
    		minn=num;
    		ans++;

		}
		if(num>maxn)
		{
			maxn=num;
			ans++;
		}
	}
	cout<<ans;
}