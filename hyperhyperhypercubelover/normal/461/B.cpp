#include<cstdio>
#include<vector>

const int mod = 1000000007;

std::vector<int> a[111111];
int b[111111];
int c[111111];
int d[111111];

void dfs(int x)
{
	int i;
	for(i=0;i<a[x].size();i++)dfs(a[x][i]);
    if(b[x])
	{
        d[x]=1;
        for(i=0;i<a[x].size();i++)d[x]=1LL*d[x]*(c[a[x][i]]+d[a[x][i]])%mod;
        return;
	}
    c[x]=1;
	for(i=0;i<a[x].size();i++)c[x]=1LL*c[x]*(c[a[x][i]]+d[a[x][i]])%mod;

	std::vector<int> L,R;
	L.resize(a[x].size()+1);
	R.resize(a[x].size()+1);

	L[0]=1;
    for(i=0;i<a[x].size();i++)L[i+1]=1LL*L[i]*(c[a[x][i]]+d[a[x][i]])%mod;
    R[a[x].size()]=1;
    for(i=a[x].size();i>0;i--)R[i-1]=1LL*R[i]*(c[a[x][i-1]]+d[a[x][i-1]])%mod;
    for(i=0;i<a[x].size();i++)d[x]=(d[x]+1LL*d[a[x][i]]*(1LL*L[i]*R[i+1]%mod))%mod;
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d",&j);
        a[j].push_back(i);
	}
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    dfs(0);
    printf("%d\n",d[0]);
}