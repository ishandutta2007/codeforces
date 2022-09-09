#include<cstdio>
#include<vector>

using namespace std;

int a[300000];
vector<int> V;

bool PAN()
{
	for(int i=0;i<V.size()-1-i;i++)if(V[i]!=V[V.size()-1-i])return 0;return 1;
}

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int i=1;while(i<n+1-i&&a[i]==a[n+1-i])i++;
		if(i>=n+1-i){puts("YES");continue;}
		V.clear();for(int j=i;j<=n+1-i;j++)if(a[j]!=a[i])V.push_back(a[j]);
		if(PAN()){puts("YES");continue;}
		V.clear();for(int j=i;j<=n+1-i;j++)if(a[j]!=a[n+1-i])V.push_back(a[j]);
		if(PAN()){puts("YES");continue;}
		puts("NO");
	}
}