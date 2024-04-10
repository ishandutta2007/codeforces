#include <stdio.h>
#include <vector>

std::vector<int> V3,V4;
std::vector<int > V1,V2;
char x[200010],y[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int control = 0;
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		
		V3.clear();
		V4.clear();
		for(int i=1;i<=a;i++) if(x[i]!='b') V3.push_back(x[i]);
		for(int i=1;i<=a;i++) if(y[i]!='b') V4.push_back(y[i]);
		
		if(V3.size()!=V4.size()) control = 1;
		else for(int i=0;i<V3.size();i++) if(V3[i]!=V4[i]) control = 1;
		
		V1.clear();
		V2.clear();
		for(int i=1;i<=a;i++) if(x[i]=='a') V1.push_back(i);
		for(int i=1;i<=a;i++) if(y[i]=='a') V2.push_back(i);
		if(V1.size()!=V2.size()) control = 1;
		else for(int i=0;i<V1.size();i++) if(V1[i]>V2[i]) control = 1;
		
		V1.clear();
		V2.clear();
		for(int i=1;i<=a;i++) if(x[i]=='c') V1.push_back(i);
		for(int i=1;i<=a;i++) if(y[i]=='c') V2.push_back(i);
		if(V1.size()!=V2.size()) control = 1;
		else for(int i=0;i<V1.size();i++) if(V1[i]<V2[i]) control = 1;
		
		if(control==0) printf("YES\n");
		else printf("NO\n");
	}
}