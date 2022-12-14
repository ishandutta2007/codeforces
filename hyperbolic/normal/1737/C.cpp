#include <stdio.h>
#include <vector>
#include <algorithm>

int abs(int k)
{
	return k>0?k:-k;
}

std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a,b,c,d,e,f,g,h,i;
		scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		V1.push_back(b);
		V1.push_back(d);
		V1.push_back(f);
		V2.push_back(c);
		V2.push_back(e);
		V2.push_back(g);
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		int C1 = 0, C2 = 0, C3 = 0, C4 = 0;
		if(V1[1]==1 || V1[1]==a) C1 = 1;
		if(V2[1]==1 || V2[1]==a) C2 = 1;
		if(h==1 || h==a) C3 = 1;
		if(i==1 || i==a) C4 = 1;
		
		if(C1==1 && C2==1)
		{
			if(V1[1]==h) printf("YES\n");
			else if(V2[1]==i) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			if(abs(V1[1]-h)%2+abs(V2[1]-i)%2<=1) printf("YES\n");
			else printf("NO\n");
		}
	}
}