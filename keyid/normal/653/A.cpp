#include <bits/stdc++.h>
using namespace std;

const int MAXN=55;

int a[MAXN];

inline bool check(int a,int b,int c)
{
	int t[3]={a,b,c};
	sort(t,t+3);
	if (t[0]==t[1]||t[1]==t[2]) return false;
	if (t[2]-t[0]>2) return false;
	return true;
}

int main()
{
	int n;
	bool flag=false;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (j!=i)
				for (int k=0;k<n;k++)
					if (k!=i&&k!=j)
						if (check(a[i],a[j],a[k]))
							flag=true;
	printf(flag?"YES":"NO");
	return 0;
}