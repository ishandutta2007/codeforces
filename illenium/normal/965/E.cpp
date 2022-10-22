#include<bits/stdc++.h>
#define iter multiset<int>::iterator 
#define ll long long
#define N 100005
#define D 27
using namespace std;
int n,tot,cnt[N],ch[N][D],flag[N];ll ans;
char s[N];
multiset<int>q[N];

class trie
{
  void merge(int x,int p)
  {
	for(iter it=q[p].begin();it!=q[p].end();++it)
      q[x].insert((*it)+1); 
  }
  public:
  void insert(char *s)
  {
    int x=0,len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
	  int num=s[i]-'a';
	  if(!ch[x][num])ch[x][num]=++tot;
	  x=ch[x][num];
	}
	flag[x]=1;
  }
  void dfs(int x)
  {
  	for(int i=0;i<26;i++)if(ch[x][i])
	  dfs(ch[x][i]),merge(x,ch[x][i]);
	if(!flag[x]&&q[x].size())
	  q[x].erase(--q[x].end());
	q[x].insert(0);
  }
}T;

int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf(" %s",s+1),T.insert(s);
  flag[0]=1;T.dfs(0);
  for(iter it=q[0].begin();it!=q[0].end();++it)ans+=(*it);
  printf("%lld\n",ans);
  return 0;
}