#include <stdio.h>
#include <vector>

std::vector<int> V;
int check[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=9;i++) check[i] = 0;
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		while(a)
		{
			V.push_back(a%10);
			a/=10;
		}
		int n = V.size()-1;
		int count = 0;
		for(int i=n;i>=0;i--)
		{
			if(check[V[i]]==0)
			{
				if(count==b)
				{
					for(int j=V[i]+1;j<=9;j++)
					{
						if(check[j]>0)
						{
							for(int k=n;k>i;k--) printf("%d",V[k]);
							printf("%d",j);
							int p = j;
							for(int k=9;k>=0;k--) if(check[k]>0) p = k;
							for(int k=i-1;k>=0;k--) printf("%d",p);
							printf("\n");
							goto u;
						}
					}
					
					for(int j=i+1;j<=n;j++)
					{
						check[V[j]]--;
						if(check[V[j]]==0)
						{
							if(check[V[j]+1]>0)
							{
								for(int k=n;k>j;k--) printf("%d",V[k]);
								printf("%d",V[j]+1);
								for(int k=j-1;k>=0;k--) printf("0");
								printf("\n");
								goto u;
							}
							else
							{
								for(int k=n;k>j;k--) printf("%d",V[k]);
								printf("%d",V[j]+1);
								check[V[j]+1]++;
								int p = V[j]+1;
								for(int k=9;k>=0;k--) if(check[k]>0) p = k;
								for(int k=j-1;k>=0;k--) printf("%d",p);
								printf("\n");
								goto u;
							}
						}
						else
						{
							for(int k=V[j]+1;k<=9;k++)
							{
								if(check[k]>0)
								{
									for(int l=n;l>j;l--) printf("%d",V[l]);
									printf("%d",k);
									check[k]++;
									int p = k;
									for(int l=9;l>=0;l--) if(check[l]>0) p = l;
									for(int l=j-1;l>=0;l--) printf("%d",p);
									printf("\n");
									goto u;
								}
							}
						}
					}
				}
				else
				{
					count++;
					check[V[i]]++;
				}
			}
			else check[V[i]]++;
		}
		
		for(int i=n;i>=0;i--) printf("%d",V[i]);
		printf("\n");
		u:;
	}
}