#include<bits/stdc++.h>
using namespace std;
int n,m,i,s=26,x;
bool a[26],b[26],f;
char c[10],d[100005];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",c,d);
		m=strlen(d);
		if(c[0]=='.')for(i=0;i<m;i++)if(!a[d[i]-'a'])
		{
			s--;
			a[d[i]-'a']=1;
		}
		if(c[0]=='!')
		{
			if(f)x++;
			memset(b,0,sizeof(b));
			for(i=0;i<m;i++)b[d[i]-'a']=1;
			for(i=0;i<26;i++)if(!b[i]&&!a[i])
			{
				a[i]=1;
				s--;
			}
		}
		if(c[0]=='?')
		{
			if(f&&n)x++;
			if(!a[d[0]-'a'])
			{
				a[d[0]-'a']=1;
				s--;
			}
		}
		if(s==1)f=1;
	}
	cout<<x<<endl;
	return 0;
}