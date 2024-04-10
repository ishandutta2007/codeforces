#include<cstdio>

using namespace std;

long long query(int l,int r)
{
	printf("? %d %d\n",l,r);fflush(stdout);long long x=0;scanf("%lld",&x);return x;
}

long long calc(long long y)//y=x(x-1)/2
{
	long long l=1,r=1000000000;
	while(l<r)
	{
		long long mid=(l+r+1)>>1;
		if(mid*(mid-1)/2<=y)l=mid;else r=mid-1;
	}
	if(y!=l*(l-1)/2)return -1;return l;
}

int main()
{
	//printf("%lld",calc(21));
	int T=0;scanf("%d",&T);
	while(T--)
	{
		long long n=0;scanf("%lld",&n);long long tot=query(1,n);
		long long l=1,r=n,i=0,j=0,k=0;
		while(1)
		{
			long long mid=(l+r+1)>>1;long long x=query(1,mid);
			if(x==0){l=mid-1;}
			else if(x==tot){r=mid;}
			else
			{
				long long z=query(mid,n);
				if(calc(z)==-1)
				{
					//puts("A");
					i=mid-calc(x)+1;l=mid+1;
					while(l<r)
					{
						mid=(l+r)>>1;if(query(i,mid)==(mid-i)*(mid-i+1)/2)l=mid+1;else r=mid;
					}
					j=l;k=j+calc(tot-(j-i)*(j-i-1)/2)-1;break;//printf("%lld %lld\n",j,calc(6));break;
				}
				else if(calc(x)==-1)
				{
					//puts("B");
					k=mid+calc(z)-1;r=mid;
					while(l<r)
					{
						mid=(l+r)>>1;if(query(mid,k)==(k-mid)*(k-mid+1)/2)r=mid;else l=mid+1;
					}
					j=l;i=j-calc(tot-(k-j+1)*(k-j)/2);break;
				}
				else
				{
					long long y=query(1,mid+1);
					//if(y==x){j=mid+1;i=j-calc(x),k=j+mp[tot-x]-1;break;}
					if(y==x+calc(x)||y==x)
					{
						i=mid-calc(x)+1;l=mid+1;
						while(l<r)
						{
							mid=(l+r)>>1;if(query(i,mid)==(mid-i)*(mid-i+1)/2)l=mid+1;else r=mid;
						}
						j=l;k=j+calc(tot-(j-i)*(j-i-1)/2)-1;break;
					}
					else
					{
						k=mid+calc(z)-1;r=mid;
						while(l<r)
						{
							mid=(l+r)>>1;if(query(mid,k)==(k-mid)*(k-mid+1)/2)r=mid;else l=mid+1;
						}
						j=l;i=j-calc(tot-(k-j+1)*(k-j)/2);break;
					}
				}
			}
		}
		printf("! %lld %lld %lld\n",i,j,k);fflush(stdout);
	}
}