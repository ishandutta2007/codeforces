#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>num;
		if(num==1||num==2||num==4||num==5||num==8||num==11)cout<<"NO\n";
		else cout<<"YES\n";
	}
}