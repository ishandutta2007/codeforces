#include<bits/stdc++.h>
using namespace std;
int n,p[2005],i,j,tmp[2005]; 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n*2;++i)
    {
		scanf("%d",&p[i]);
    	tmp[i]=p[i];
    }
    for(i=0;i<=n*2;++i)
    {
    	for(j=1;j<=n*2;++j)
    		if(p[j]!=j)
    			break;
    	if(j>n*2)
    		break;
    	if(i&1)
			for(j=1;j<=n*2;j+=2)
    			swap(p[j],p[j+1]);
    	else
    		for(j=1;j<=n;++j)
    			swap(p[j],p[j+n]);
	}
	int ans1=i;
	for(i=1;i<=n*2;++i)
		p[i]=tmp[i];
	for(i=0;i<=n*2;++i)
    {
    	for(j=1;j<=n*2;++j)
    		if(p[j]!=j)
    			break;
    	if(j>n*2)
    		break;
    	if((i&1)^1)
			for(j=1;j<=n*2;j+=2)
    			swap(p[j],p[j+1]);
    	else
    		for(j=1;j<=n;++j)
    			swap(p[j],p[j+n]);
	}
	int ans=min(ans1,i);
	if(ans>n*2)
		puts("-1");
	else
		cout<<ans;
}