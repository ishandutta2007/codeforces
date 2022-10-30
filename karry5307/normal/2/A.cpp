#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1051;
ll cnt,score[MAXN],tot,maxn=-0x7ffffff,appear;
string str[MAXN],name[MAXN];
map<string,ll>mp,mmap;
int main()
{
	scanf("%d",&cnt);
	for(register int i=0;i<cnt;i++)
	{
		cin>>name[i];
		scanf("%d",&score[i]);
		if(!mp.count(name[i]))
		{
			str[tot++]=name[i];
		}
		mp[name[i]]+=score[i];
	}
	for(register int i=0;i<tot;i++)
	{
		maxn=max(maxn,mp[str[i]]);
	}
	for(register int i=0;i<cnt;i++)
	{
		mmap[name[i]]+=score[i];
		if(mp[name[i]]==maxn&&mmap[name[i]]>=maxn)
		{
			cout<<name[i]<<endl;
			return 0;
		}
	}
}