#include <bits/stdc++.h>
using namespace std;

int n,m,i,j;
string s,t;
map<pair<string,int>,vector<int> > cnt;
char ss[1000005];

int main()
{
	scanf("%d",&n);
	
	for (j=1;j<=n;j++)
	{
		scanf(" %s",ss);s=ss;
		scanf(" %s",ss);t=ss;
		
		int f=0;
		for (i=0;i<t.length();i++) f|=(1<<(t[i]-'a'));
		while (!s.empty()&&((f>>(s.back()-'a'))&1)) s.pop_back();
		
		cnt[make_pair(s,f)].push_back(j);
		
	}
	
	printf("%d\n",cnt.size());
	for (map<pair<string,int>,vector<int> >::iterator it=cnt.begin();it!=cnt.end();it++)
	{
		printf("%d",it->second.size());
		for (i=0;i<it->second.size();i++) printf(" %d",it->second[i]);
		puts("");
	}
	
	return 0;
}