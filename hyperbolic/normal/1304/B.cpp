#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<char> ans,ans2;
char x[1010][1010];
int check[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) continue;
		for(int j=i+1;j<=a;j++)
		{
			if(check[j]==1) continue;
			for(int k=1;k<=b;k++) if(x[i][k]!=x[j][b-k+1]) goto u;
			
			check[i] = check[j] = 1;
			for(int k=1;k<=b;k++) ans.push_back(x[i][k]);
			goto v;
			
			u:;
		}
		
		for(int k=1;k<=b;k++) if(x[i][k]!=x[i][b-k+1]) goto v;
		if(ans2.size()==0)
		{
			check[i] = 1;
			for(int k=1;k<=b;k++) ans2.push_back(x[i][k]);
		}
		
		v:;
	}
	printf("%d\n",2*ans.size()+ans2.size());
	for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
	for(int i=0;i<ans2.size();i++) printf("%c",ans2[i]);
	for(int i=ans.size()-1;i>=0;i--) printf("%c",ans[i]);
}