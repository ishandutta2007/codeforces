#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	char a[n+1];
	scanf("%s",a);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int k;
		char c;
		scanf("%d",&k);
		scanf("%c",&c);
		scanf("%c",&c);
		int l=0,r=-1,check=0,ans=0,max=0;
		while(r+1<n)
		{
			r++;
			//printf("%c %c %d %d\n",a[r],c,r,check);
			if(a[r]!=c&&check<k)
			check++;
			else if(a[r]!=c&&check==k)
			{
				r--;
				break;
			}
		}
		//printf("%d %d\n",l,r);
		max=r-l+1;
		while(r+1<n)
		{
			r++;
			while(a[l]==c)
			l++;
			l++;
			while(a[r+1]==c&&r+1<n)
			r++;
			ans=r-l+1;
			//printf("%d %d\n",l,r);
			if(ans>max)
			max=ans;
		}
		printf("%d\n",max);
	}
}