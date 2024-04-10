#include<cstdio>
#include<vector>

std::vector<int> d[300000];
char r[300001];

int main()
{
	int flag,i,j,k,n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		d[i-1].push_back(j-1);
		d[j-1].push_back(i-1);
	}
    for(i=0;i<n;i++)r[i]='0';
    for(m=100;m;m--)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<d[i].size();j++)k+=r[i]==r[d[i][j]];
            if(k>1)
			{
				flag=0;
				r[i]^=1;
			}
		}
        if(flag)break;
	}
	if(m)puts(r);
	else puts("-1");
}