#include<cstdio>

int r[111111];
int t[111111];

int upd(int x,int y,int z)
{
	while(x<111111&&z--)
	{
		t[x]++;
		r[x]+=y;
		x<<=1;
		y++;
	}
}

int main()
{
	int i,j,k,l,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        scanf("%d",&j);
        k=0;
        l=1e9;
        while(j)
		{
			upd(j,k,l);
			if(j%2)l=1e9;
			else l=1;
            j/=2;
            k++;
		}
	}
	j=1;
	for(i=1;i<111111;i++)if(t[i]==n&&r[i]<r[j])j=i;
	printf("%d\n",r[j]);
}