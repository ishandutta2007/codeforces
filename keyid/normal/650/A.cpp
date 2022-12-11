#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

#define mp make_pair

typedef pair <int,int> pii;

map <int,int> ms1,ms2;
map <pii,int> ms;

int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=ms1[x]+ms2[y]-ms[mp(x,y)];
		ms1[x]++;
		ms2[y]++;
		ms[mp(x,y)]++;
	}
	printf("%I64d",ans);
	return 0;
}