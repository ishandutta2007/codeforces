#include <stdio.h>

int x[110],y[110],z[110],ans[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) scanf("%d",&z[i]);
		
		int p = -1;
		for(int i=1;i<a;i++)
		{
			if(p!=x[i]) ans[i] = x[i], p = x[i];
			else if(p!=y[i]) ans[i] = y[i], p = y[i];
			else if(p!=z[i]) ans[i] = z[i], p = z[i];
		}
		for(int i=1;i<a;i++) printf("%d " ,ans[i]);
		if(x[a]!=ans[1]&&x[a]!=ans[a-1]) printf("%d\n",x[a]);
		else if(y[a]!=ans[1]&&y[a]!=ans[a-1]) printf("%d\n",y[a]);
		else if(z[a]!=ans[1]&&z[a]!=ans[a-1]) printf("%d\n",z[a]);
	}
}