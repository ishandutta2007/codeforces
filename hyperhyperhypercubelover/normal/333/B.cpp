#include<cstdio>

int w[1001];
int h[1001];

int main()
{
	int x,y,r=0;
	int i,j,k,t,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		w[x]=1;
        h[y]=1;
	}
	for(i=2;i<=n/2;i++)
	{
		m=0;
		for(j=0;j<256;j++)
		{
			if(((j>>0)&1)&&w[i])continue;
			if(((j>>1)&1)&&w[i])continue;
			if(((j>>2)&1)&&w[n-i+1])continue;
			if(((j>>3)&1)&&w[n-i+1])continue;
			if(((j>>4)&1)&&h[i])continue;
			if(((j>>5)&1)&&h[i])continue;
			if(((j>>6)&1)&&h[n-i+1])continue;
			if(((j>>7)&1)&&h[n-i+1])continue;

			if(((j>>0)&1)&&((j>>1)&1))continue;
			if(((j>>2)&1)&&((j>>3)&1))continue;
			if(((j>>4)&1)&&((j>>5)&1))continue;
			if(((j>>6)&1)&&((j>>7)&1))continue;

			if(((j>>0)&1)&&((j>>4)&1))continue;
			if(((j>>0)&1)&&((j>>7)&1))continue;
			if(((j>>1)&1)&&((j>>5)&1))continue;
			if(((j>>1)&1)&&((j>>6)&1))continue;
			if(((j>>2)&1)&&((j>>5)&1))continue;
			if(((j>>2)&1)&&((j>>6)&1))continue;
			if(((j>>3)&1)&&((j>>4)&1))continue;
			if(((j>>3)&1)&&((j>>7)&1))continue;

			t=0;
			for(k=0;k<8;k++)if((j>>k)&1)t++;
			if(t>m)m=t;
		}
		r+=m;
	}
	if((n&1)&&(!w[n/2+1]||!h[n/2+1]))r++;
	printf("%d",r);
}