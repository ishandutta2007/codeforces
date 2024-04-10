#include<bits/stdc++.h>
using namespace std;

bool ok(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	string s;
	cin>>s;
	return s[0]=='Y';
}

int main()
{
	int n;
	cin>>n;
	string s1;
	int x=1,y=1;
	while(x+y<n+1)
	if(x<n&&ok(x+1,y,n,n))
	{
		++x;
		s1.push_back('D');
	}
	else
	{
		++y;
		s1.push_back('R');
	}
	string s2;
	x=y=n;
	while(x+y>n+1)
	if(y>1&&ok(1,1,x,y-1))
	{
		--y;
		s2.push_back('R');
	}
	else
	{
		--x;
		s2.push_back('D');
	}
	reverse(s2.begin(),s2.end());
	cout<<"! "<<s1<<s2<<endl;
}