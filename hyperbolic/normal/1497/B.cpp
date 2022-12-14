#include <stdio.h>

int count[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=b;i++) count[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			count[c%b]++;
		}
		
		int ans = 0;
		if(b%2==1)
		{
			int L = 1, R = b-1;
			while(1)
			{
				if(L>R) break;
				if(count[L]>count[R]) ans += (count[L]-count[R]);
				else if(count[L]<count[R]) ans += (count[R]-count[L]);
				else if(count[L]!=0) ans++;
				L++, R--;
			}
			if(count[0]>0) ans++;
			printf("%d\n",ans);
		}
		else
		{
			int L = 1, R = b-1;
			while(1)
			{
				if(L>=R) break;
				if(count[L]>count[R]) ans += (count[L]-count[R]);
				else if(count[L]<count[R]) ans += (count[R]-count[L]);
				else if(count[L]!=0) ans++;
				L++, R--;
			}
			if(count[0]>0) ans++;
			if(count[b/2]>0) ans++;
			printf("%d\n",ans);
		}
	}
}