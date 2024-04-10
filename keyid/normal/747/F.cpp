#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const char T[20]={"0123456789abcdef"};

int k,lim,cnt[20];
LL C[20][11],f[20][20];

int cal(int len)
{
	len--;
	cnt[0]--;
	memset(f,0,sizeof(f));
	f[0][len]=1;
	for (int i=1;i<=16;i++)
		for (int j=0;j<=len;j++)
		{
			f[i][j]=f[i-1][j];
			for (int u=1;u<=cnt[i-1]&&j+u<=len;u++)
			{
				f[i][j]+=f[i-1][j+u]*C[j+u][u];
				if (f[i][j]>k)
				{
					f[i][j]=k+1;
					break;
				}
			}
		}
	cnt[0]++;
	f[16][0]*=15;
	if (f[16][0]>k) f[16][0]=k+1;
	return f[16][0];
}

int cal2(int len)
{
	memset(f,0,sizeof(f));
	f[0][len]=1;
	for (int i=1;i<=16;i++)
		for (int j=0;j<=len;j++)
		{
			f[i][j]=f[i-1][j];
			for (int u=1;u<=cnt[i-1]&&j+u<=len;u++)
			{
				f[i][j]+=f[i-1][j+u]*C[j+u][u];
				if (f[i][j]>k)
				{
					f[i][j]=k+1;
					break;
				}
			}
		}
	return f[16][0];
}

void solve(int len)
{
	for (int i=len-1;i>=0;i--)
		for (int j=0;j<16;j++)
		{
			if (i==len-1&&j==0) continue;
			if (cnt[j])
			{
				cnt[j]--;
				int t=cal2(i);
				if (t>=k)
				{
					putchar(T[j]);
					break;
				}
				else
					k-=t;
				cnt[j]++;
			}
		}
}

int main()
{
	scanf("%d%d",&k,&lim);
	for (int i=0;i<=16;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i&&j<=10;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if (C[i][j]>k)
				C[i][j]=k+1;
		}
	}
	fill(cnt,cnt+16,lim);
	for (int i=1;;i++)
	{
		int t=cal(i);
		if (t>=k)
		{
			solve(i);
			break;
		}
		k-=t;
	}
	return 0;
}