#include<bits/stdc++.h>
using namespace std;
int n,i,x,y;
char c[10],ans[1005];
int main()
{
	cin>>n;
	for(i=x=y=1;i<n;i++)
	{
		cout<<"? "<<x<<' '<<y+1<<' '<<n<<' '<<n<<endl;
		fflush(stdout);
		cin>>c;
		if(c[0]=='Y')
		{
			ans[i]='R';
			y++;
		}
		else
		{
			ans[i]='D';
			x++;
		}
	}
	for(x=y=n;i<=2*n-2;i++)
	{
		cout<<"? 1 1 "<<x-1<<' '<<y<<endl;
		fflush(stdout);
		cin>>c;
		if(c[0]=='Y')
		{
			ans[i]='D';
			x--;
		}
		else
		{
			ans[i]='R';
			y--;
		}
	}
	reverse(ans+n,ans+2*n-1);
	cout<<"! ";
	puts(ans+1);
	return 0;
}