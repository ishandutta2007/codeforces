#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
char Not(char a,char b)
{
	for(char i='a';i<='c';i++)
		if(i!=b&&i!=a)
			return i;
}
int main()
{
	int n,k;
	cin>>n>>k;
	string a,b,c;
	cin>>a>>b;
	c.resize(n);
	fill(c.begin(),c.end(),'1');
	int diff=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
			diff++;
	int c2=k+k-n;//4t-2n
	int c1=n-c2;//n-2t+n
	if(c1>diff)
	{
		c1=diff/2*2;
		c2=(k+k-c1)/2;
		if(c1+c2>n)
			die("-1");
	}
//	cout<<c1<<" "<<c2<<endl;
	int tmp1=c1/2,tmp2=c1/2;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
			if(tmp1)
			{
				tmp1--;
				c[i]=a[i];
			}
			else if(tmp2)
			{
				tmp2--;
				c[i]=b[i];
			}
	for(int i=0;i<n;i++)
		if(c[i]=='1'&&a[i]!=b[i])
			if(c2)
			{
				c[i]=Not(a[i],b[i]);
				c2--;
			}
			else	die("-1");
	for(int i=0;i<n;i++)
		if(c[i]=='1')
		{
			if(c2)
			{
				c[i]=Not(a[i],b[i]);
				c2--;
			}
			else c[i]=a[i];
		}
	if(tmp1||tmp2||c2)
		die("-1");
	die(c);
	return 0;
}