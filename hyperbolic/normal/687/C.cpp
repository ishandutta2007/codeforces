#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> ans;
int a,b;
short check[510][510][510];
int x[510],check2[510];
void func(int s, int t, int k)
{
	if(t>b) return;
	if(t==b)
	{
		check2[k] = 1;
		return;
	}
	if(s>a) return;
	if(check[s][t][k]) return;
	
	func(s+1,t,k);
	func(s+1,t+x[s],k+x[s]);
	func(s+1,t+x[s],k);
	check[s][t][k] = 1;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	func(1,0,0);
	
	for(int i=0;i<=b;i++) if(check2[i]==1) ans.push_back(i);
	
	printf("%d\n",ans.size());
	for(int j=0;j<ans.size();j++) printf("%d ",ans[j]);
}