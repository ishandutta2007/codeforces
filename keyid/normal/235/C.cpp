#include <bits/stdc++.h>
using namespace std;

const int MAXL=1000005,SIGMA=26;

struct Node
{
	Node *f,*ch[SIGMA];
	int len,size,vis;
}pool[MAXL*2],*sz,*last,*t[MAXL*2];


char s[MAXL];
int b[MAXL];

void init()
{
	sz=pool;
	last=sz++;
}

void add(int c)
{
	Node *np=sz++,*p=last;
	np->len=p->len+1;
	np->size=1;
	np->vis=-1;
	last=np;
	for (;p&&!p->ch[c];p=p->f) p->ch[c]=np;
	if (!p) np->f=pool;
	else
		if (p->ch[c]->len==p->len+1) np->f=p->ch[c];
		else
		{
			Node *q=p->ch[c],*r=sz++;
			*r=*q;
			r->len=p->len+1;
			r->size=0;
			q->f=np->f=r;
			for (;p&&p->ch[c]==q;p=p->f) p->ch[c]=r;
		}
}

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	init();
	for (int i=0;i<l;i++)
		add(s[i]-'a');
	for (Node *i=pool;i!=sz;i++)
		b[i->len]++;
	for (int i=1;i<=l;i++)
		b[i]+=b[i-1];
	int ns=b[l];
	for (Node *i=pool;i!=sz;i++)
		t[--b[i->len]]=i;
	for (int i=ns-1;i>0;i--)
		t[i]->f->size+=t[i]->size;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		Node *now=pool;
		int p=0,ans=0;
		for (int j=0;j<l;j++)
		{
			int c=s[j]-'a';
			if (now->ch[c])
			{
				now=now->ch[c];
				p++;
			}
			else
			{
				for (;now&&!now->ch[c];now=now->f);
				if (now)
				{
					p=now->len+1;
					now=now->ch[c];
				}
				else
				{
					p=0;
					now=pool;
				}
			}
		}
		if (p==l)
		{
			now->vis=i;
			ans+=now->size;
		}
		for (int j=0;j+1<l;j++)
		{
			int c=s[j]-'a';
			if (now->ch[c])
			{
				now=now->ch[c];
				p++;
			}
			else
			{
				for (;now&&!now->ch[c];now=now->f);
				if (now)
				{
					p=now->len+1;
					now=now->ch[c];
				}
				else
				{
					p=0;
					now=pool;
				}
			}
			for (;now!=pool&&now->f->len>=l;now=now->f,p=now->len);
			if (p>=l&&now->vis!=i)
			{
				now->vis=i;
				ans+=now->size;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}