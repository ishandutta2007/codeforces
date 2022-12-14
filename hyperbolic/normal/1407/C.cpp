#include <stdio.h>
#include <set>
int getQuery(int a, int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int k;
	scanf("%d",&k);
	return k;
}

int ans[10010];
std::set<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	if(a==1)
	{
		printf("! 1");
		fflush(stdout);
		return 0;
	}
	
	int p = 1;
	for(int i=2;i<=a;i++)
	{
		int b = getQuery(p,i);
		int c = getQuery(i,p);
		if(b<c) ans[i] = c;
		else ans[p] = b, p = i;
	}
	for(int i=1;i<=a;i++) S.insert(i);
	for(int i=1;i<=a;i++) if(ans[i]>0) S.erase(ans[i]);
	ans[p] = (*S.begin());
	printf("! ");
	for(int i=1;i<=a;i++) printf("%d " ,ans[i]);
	fflush(stdout);
}