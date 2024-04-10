#include<cstdio>
#include<map>

std::map<int,int> M;
std::map<int,int>::iterator it;

void push(int x)
{
	if(M.find(x)==M.end())
		M[x]=1;
	else
		M[x]=M[x]+1;
}

int main()
{
	int cnt;
	int i,j,n,a,max=0;
	scanf("%d",&n);
	cnt=n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		push(a);
		if(a>max)max=a;
		for(j=a;M[j]==2;j++){cnt--;M[j]=0;push(j+1);if(j+1>max)max=j+1;}
	}
	printf("%d",max-cnt+1);
}