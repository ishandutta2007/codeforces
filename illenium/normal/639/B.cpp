#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

int main()
{
	int n,d,h;
	scanf("%d%d%d", &n, &d, &h);
	if(d>2*h || (h==d && d==1 && n>2))
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1; i<=h; i++)
		printf("%d %d\n", i, i+1);
	int j=1;
	for(int i=h+2; i<=d+1; i++)
	{
		printf("%d %d\n", j, i);
		j=i;
	}
	for(int i=d+2; i<=n; i++)
		printf("%d %d\n", h, i);
	return 0; 
}