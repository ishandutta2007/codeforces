#include <stdio.h>
#include <map>

int getQuery(int type, int s, int t)
{
	if(type==1) printf("AND %d %d\n",s,t);
	if(type==2) printf("OR %d %d\n",s,t);
	if(type==3) printf("XOR %d %d\n",s,t);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}
int x[100010];
int ans[100010];
std::map<int,int> M;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++) x[i] = getQuery(3,1,i);
	
	int control = 0;
	if(control==0)
	{
		for(int i=2;i<=a;i++)
		{
			if(x[i]==0)
			{
				ans[1] = getQuery(1,1,i);
				control = 1;
				break;
			}
		}
	}
	
	if(control==0)
	{
		for(int i=2;i<=a;i++)
		{
			if(M[x[i]]!=0)
			{
				ans[i] = getQuery(1,M[x[i]],i);
				ans[1] = (ans[i] ^ x[i]);
				control = 1;
				break;
			}
			else M[x[i]] = i;
		}
	}
	if(control==1)
	{
		for(int i=2;i<=a;i++) ans[i] = (ans[1]^x[i]);
		printf("! ");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		fflush(stdout);
	}
	else
	{
		int p,q;
		for(int i=2;i<=a;i++) if(x[i]==1) p = i;
		for(int i=2;i<=a;i++) if(x[i]==a-2) q = i;
		ans[1] = getQuery(1,1,p) + getQuery(1,1,q);
		
		for(int i=2;i<=a;i++) ans[i] = (ans[1]^x[i]);
		printf("! ");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		fflush(stdout);
	}
}