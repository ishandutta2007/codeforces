#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>sol;
ll n;
ll wt[2];
char ch[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void dfs(ll cur,ll c,ll lst)
{
	if(cur==n+1)
	{
		puts("YES");
		for(register int i:sol)
		{
			printf("%d ",i);
		}
		exit(0);
	}
	for(register int i=wt[c^1]-wt[c]+1;i<=10;i++)
	{
		if((ch[i]&1)&&i!=lst)
		{
			wt[c]+=i,sol.push_back(i),dfs(cur+1,c^1,i),sol.pop_back(),wt[c]-=i;
		}
	}
}
int main()
{
	scanf("%s",ch+1),n=read(),dfs(1,0,-1),puts("NO");
}