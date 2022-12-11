#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

struct Pos
{
	int v,x;
};

char s[MAXN];
int last_tmp[MAXN*2],*last=last_tmp+MAXN,ml[MAXN];
bool d[MAXN];
stack <Pos> sta;

int main()
{
	scanf("%s",s+1);
	int l=strlen(s+1),ans=0,cnt;
	memset(last_tmp,-1,sizeof(last_tmp));
	last[0]=0;
	sta.push({0,0});
	for (int i=1,sum=0;i<=l;i++)
	{
		sum+=(s[i]=='('?1:-1);
		if (last[sum]>=0&&!d[last[sum]]) ml[i]=ml[last[sum]]+i-last[sum];
		if (ml[i]>ans)
		{
			ans=ml[i];
			cnt=1;
		}
		else if (ml[i]==ans) cnt++;
		last[sum]=i;
		while (!sta.empty()&&sta.top().v>=sum)
		{
			d[sta.top().x]=true;
			sta.pop();
		}
		sta.push({sum,i});
	}
	if (ans) printf("%d %d",ans,cnt);
	else printf("0 1");
	return 0;
}