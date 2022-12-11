#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair

typedef pair <int,int> pii;

const int MAXN=200005;

pii a[MAXN];
int rid[MAXN];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i].fi);
		a[i].sc=i+1;
	}
	sort(a,a+n);
	for (int i=0;i<n;i++)
		rid[a[i].sc]=i;
	while (m--)
	{
		int s,l;
		scanf("%d%d",&s,&l);
		s=rid[s];
		bool right=true;
		for (;;)
		{
			int k1,k2,t;
			if (right)
			{
				k1=upper_bound(a+s,a+n,mp(a[s].fi+l,n))-a-1;
				l-=a[k1].fi-a[s].fi;
				k2=lower_bound(a,a+n,mp(a[k1].fi-l,0))-a;
				if (k1==k2)
				{
					s=k1;
					break;
				}
				t=a[k1].fi-a[k2].fi;
			}
			else
			{
				k1=lower_bound(a,a+n,mp(a[s].fi-l,0))-a;
				l-=a[s].fi-a[k1].fi;
				k2=upper_bound(a,a+n,mp(a[k1].fi+l,n))-a-1;
				if (k1==k2)
				{
					s=k1;
					break;
				}
				t=a[k2].fi-a[k1].fi;
			}
			if ((l/t)&1)
				s=k2;
			else
			{
				s=k1;
				right^=1;
			}
			l%=t;
		}
		printf("%d\n",a[s].sc);
	}
	return 0;
}