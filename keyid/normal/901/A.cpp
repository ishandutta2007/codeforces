#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=100005;

int a[MAXN],fa[2][MAXN*2];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	int cnt=1;
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (a[i-1]!=1)
		{
			if (a[i]!=1)
			{
				flag=false;
				for (int j=1;j<=a[i];j++)
					fa[0][cnt+j]=cnt;
				fa[1][cnt+1]=cnt;
				for (int j=2;j<=a[i];j++)
					fa[1][cnt+j]=cnt-1;
				cnt+=a[i];
				for (int j=i+1;j<=n;j++)
				{
					for (int k=1;k<=a[j];k++)
						fa[0][cnt+k]=fa[1][cnt+k]=cnt;
					cnt+=a[j];
				}
				break;
			}
			else
			{
				fa[0][cnt+1]=fa[1][cnt+1]=cnt;
				cnt++;
			}
		}
		else
		{
			for (int j=1;j<=a[i];j++)
				fa[0][cnt+j]=fa[1][cnt+j]=cnt;
			cnt+=a[i];
		}
	if (flag)
		printf("perfect");
	else
	{
		puts("ambiguous");
		for (int i=1;i<=cnt;i++)
			printf("%d ",fa[0][i]);
		puts("");
		for (int i=1;i<=cnt;i++)
			printf("%d ",fa[1][i]);
	}
	return 0;
}