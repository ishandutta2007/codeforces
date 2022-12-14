#include <stdio.h>
#include <vector>

std::vector<char> V;
char x[510];
int check[510][510];

int func(int L, int R)
{
	if(L>R) return 0;
	if(check[L][R]!=-1) return check[L][R];
	
	int s1 = func(L+1,R)+1;
	for(int i=L+1;i<=R;i++)
	{
		if(V[i]==V[L])
		{
			int s2 = func(L+1,i-1)+func(i,R);
			s1 = s1<s2?s1:s2;
		}
	}
	return check[L][R] = s1;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) check[i][j] = -1;
	
	scanf("%s",x+1);
	V.push_back(x[1]);
	for(int i=2;i<=a;i++) if(x[i]!=x[i-1]) V.push_back(x[i]);
	printf("%d",func(0,V.size()-1));
}