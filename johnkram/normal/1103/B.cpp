#include<bits/stdc++.h>
using namespace std;
string s;
int x,l,r,mid;
int main()
{
	for(;;)
	{
		cin>>s;
		if(s[0]=='e')break;
		for(l=0;;l=l*2+1)
		{
			cout<<'?'<<' '<<l<<' '<<2*l+1<<endl;
			fflush(stdout);
			cin>>s;
			if(s[0]=='x')break;
		}
		r=2*l+1;
		while(l+1<r)
		{
			mid=l+r>>1;
			cout<<'?'<<' '<<l<<' '<<mid<<endl;
			fflush(stdout);
			cin>>s;
			if(s[0]=='x')r=mid;
			else l=mid;
		}
		cout<<'!'<<' '<<r<<endl;
		fflush(stdout);
	}
	return 0;
}