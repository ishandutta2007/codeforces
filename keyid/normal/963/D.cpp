#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXL=100005,SIGMA=26;

char s[MAXL];

struct Node
{
	Node *f,*ch[SIGMA];
	int len;
}pool[MAXL*2],*sz,*last;

int pos[MAXL*2],cnt,p[MAXL];
vector <int> G[MAXL*2];

void init()
{
	sz=pool;
	last=sz++;
}

void add(int c,int id)
{
	Node *np=sz++,*p=last;
	np->len=last->len+1;
	last=np;
	pos[np-pool]=id;
	for (;p&&!p->ch[c];p=p->f) p->ch[c]=np;
	if (!p) np->f=pool;
	else if (p->ch[c]->len==p->len+1) np->f=p->ch[c];
	else
	{
		Node *q=p->ch[c],*r=sz++;
		*r=*q;
		r->len=p->len+1;
		q->f=np->f=r;
		for (;p&&p->ch[c]==q;p=p->f) p->ch[c]=r;
	}
}

void dfs(int u)
{
	if (pos[u])
		p[cnt++]=pos[u];
	for (int v:G[u])
		dfs(v);
}

int solve()
{
	int k;
	scanf("%d%s",&k,s);
	int l=strlen(s);
	Node *now=pool;
	for (int i=0;i<l;i++)
	{
		if (now->ch[s[i]-'a']==NULL)
			return -1;
		now=now->ch[s[i]-'a'];
	}
	cnt=0;
	dfs(now-pool);
	if (cnt<k)
		return -1;
	sort(p,p+cnt);
	int ans=INT_MAX;
	for (int i=k-1;i<cnt;i++)
		ans=min(ans,p[i]-p[i-k+1]);
	ans+=l;
	return ans;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%s",s);
	int l=strlen(s);
	init();
	for (int i=0;i<l;i++)
		add(s[i]-'a',i+1);
	for (Node *i=pool+1;i!=sz;i++)
	{
		int f=i->f-pool,v=i-pool;
		G[f].pb(v);
	}
	int n;
	scanf("%d",&n);
	while (n--)
		printf("%d\n",solve());
	return 0;
}