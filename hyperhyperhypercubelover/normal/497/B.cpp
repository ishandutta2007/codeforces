#include<cstdio>
#include<algorithm>

int a[333333];
int b[333333];

std::pair<int,int> rr[222222];
int rn;

int main()
{
	int fir,sec,last;
	int l,r,mid;
	int i,n,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(t==1)a[i]++;
		else b[i]++;
	}
	for(i=n+1;i<333333;i++)
	{
		a[i]=a[i-1];
		b[i]=b[i-1];
	}
	for(i=1;i<=n;i++)
	{
        fir=sec=0;
		last=-1;
		for(t=0;t<n;t=l)
		{
			l=t+i;
            r=t+i+i-1;
            while(l<r)
			{
				mid=(l+r)/2;
				if(a[mid]-a[t]<i&&b[mid]-b[t]<i)l=mid+1;
				else r=mid;
			}
            if(a[l]-a[t]==i)
			{
				fir++;
				last=1;
			}
            else if(b[l]-b[t]==i)
			{
				sec++;
				last=2;
			}
			else break;
		}
		if(t!=n)continue;
		if((fir>sec&&last==1)||(fir<sec&&last==2))rr[rn++]=std::make_pair(std::max(fir,sec),i);
	}
	printf("%d\n",rn);
	std::sort(rr,rr+rn);
	for(i=0;i<rn;i++)printf("%d %d\n",rr[i].first,rr[i].second);
}