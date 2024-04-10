#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int a[3000];

vector<int> ans;

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d",&n);bool no_sol=0;for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]%2!=i%2)no_sol=1;}
		if(no_sol){puts("-1");continue;}
		ans.clear();
		for(int i=n;i>=3;i-=2)
		{
			int x=1;while(a[x]!=i)x++;
			if(x!=1){ans.push_back(x);reverse(a+1,a+x+1);}
			int y=1;while(a[y]!=i-1)y++;
			if(y!=2)
			{
				ans.push_back(y-1);reverse(a+1,a+y);
				ans.push_back(y+1);reverse(a+1,a+y+2);
				ans.push_back(3);reverse(a+1,a+4);
			}
			ans.push_back(i);reverse(a+1,a+i+1);
		}
		printf("%d\n",ans.size());for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
	}
}