#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;

int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int R = a, L = 1;
	int l = 1, r = x[a]+1;
	while(L<=R)
	{
		for(int i=l;i<l+x[L];i++) for(int j=i+1;j<=r;j++) ans.push_back(std::make_pair(i,j));
		l += x[L];
		for(int i=R;i>L;i--) x[i] -= x[L];
		R--;
		L++;
		r = x[R]+l;//(r-l+1) == x[R]+1
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}