#include<cstdio>
#include<vector>

std::vector<int> a,b;

int main()
{
	long long aa,bb,l;
	int i,n,t;
	scanf("%d",&n);
	aa=bb=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(t>0)
		{
			a.push_back(t);
			aa+=t;
			l=0;
		}
		else
		{
			b.push_back(-t);
			bb+=-t;
			l=1;
		}
	}
	if(aa>bb)printf("first");
	else if(aa<bb)printf("second");
	else if(a>b)printf("first");
	else if(a<b)printf("second");
	else if(l==0)printf("first");
	else printf("second");
}