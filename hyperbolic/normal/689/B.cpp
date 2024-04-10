#include <stdio.h>
#include <queue>
int x[200010];
int check[200010];
struct str{
	int x0;
	int y0;
};
str Str(int a, int b)
{
	str A;
	A.x0 = a;
	A.y0 = b;
	return A;
}
std::queue<str> Q;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	Q.push(Str(1,1));
	while(!Q.empty())
	{
		str A = Q.front();
		Q.pop();
		if(check[A.x0]!=0) continue;
		check[A.x0]=A.y0;
		
		if(1<A.x0&&check[A.x0-1]==0) Q.push(Str(A.x0-1,A.y0+1));
		if(A.x0<a&&check[A.x0+1]==0) Q.push(Str(A.x0+1,A.y0+1));
		if(check[x[A.x0]]==0) Q.push(Str(x[A.x0],A.y0+1));
	}
	for(int i=1;i<=a;i++) printf("%d ",check[i]-1);
}