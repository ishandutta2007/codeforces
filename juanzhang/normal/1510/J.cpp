#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=1010105,inf=1010111;
int n,i,j,k,l;
char c[N],p[N],as[N];
vector<int> ans;
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='_')
			c[i]='.';
	for(i=1;i<=n&&c[i]=='.';++i);
	if(i>n)
	{
		puts("0");
		return 0;
	}
	for(i=0;i<=100;++i)
	{
		for(j=1;j<=n+1;++j)
			as[j]=p[j]='.';
		for(j=1;j<=n;++j)
			if(c[j]=='#'&&c[j+1]!='#')
			{
				for(k=j;c[k]=='#';--k)
					p[k]='#';
				int m=i;
				for(;m&&k>=1;--k,--m)
					p[k]='#';
			}
		for(j=n+1;j>n-i+1;--j)
			p[j]='#';
		p[0]='.';
		for(j=0;j<=n+1;++j)
			if(p[j]=='.')
			{
				for(k=j;p[k]=='.';++k);
				if(k-j>=3)
					if(k-j&1)
					{
						for(l=j+1;l<k;l+=2)
							p[l]='#';
					}
					else
					{
						p[j+1]=p[j+2]='#';
						for(l=j+4;l<k;l+=2)
							p[l]='#';
					}
				j=k;
			}
		for(j=n;j>n-i+1;--j)
			p[j]='.';
		for(j=1;j<=n;++j)
			if(p[j]=='#')
			{
				for(k=j;p[k]=='#';++k);
				for(l=k-1;l>=j+i;--l)
					as[l]='#';
			}
		for(j=n;j>=1;--j)
			if(p[j]!='.')
				break;
		if(j!=n-i)
			continue;
		for(;j>=1;--j)
			if(p[j]=='.'&&p[j-1]=='.')
				break;
		if(j>=1)
			continue;
		for(j=1;j<=n;++j)
			if(as[j]!=c[j])
				break;
		if(j>n)
		{
			for(j=1;j<=n;++j)
				if(p[j]=='#')
				{
					for(k=j;p[k]=='#';++k);
					ans.push_back(k-j);
					j=k;
				}
			printf("%d\n",ans.size());
			for(auto it:ans)
				printf("%d ",it);
			return 0;
		}
	}
	puts("-1");
}