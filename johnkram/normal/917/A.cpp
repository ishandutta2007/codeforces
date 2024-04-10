#include<bits/stdc++.h>
using namespace std;
char s[5005];
int n,i,j,l,r,ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		for(j=i,l=r=0;j<n;j++)
		{
			if(s[j]=='(')
			{
				l++;
				r++;
			}
			else if(s[j]==')')
			{
				l=max(l-1,0);
				r--;
			}
			else
			{
				l=max(l-1,0);
				r++;
			}
			if(l>r)break;
			if(!(r&1)&&!l)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}