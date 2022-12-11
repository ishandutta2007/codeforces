#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;
typedef unsigned uint;

#define mp make_pair
#define fi first
#define sc second

const int MAXN=500005;

uint R=time(NULL);

uint myrand()
{
	R^=R<<13;
	R^=R>>17;
	R^=R<<5;
	return R;
}

struct Node
{
	Node *ch[2];
	uint r;
	int v,p,min_vp,addp,s;

	int cmp(int x) const
	{
		if (x==v) return -1;
		return x<v?0:1;
	}

	void maintain()
	{
		min_vp=min(v-p,min(ch[0]->min_vp,ch[1]->min_vp))-addp;
		s=ch[0]->s+ch[1]->s+1;
	}
}*null,pool[MAXN],*sz=pool,*root;

Node* newnode(int v,int p)
{
	sz->ch[0]=sz->ch[1]=null;
	sz->r=myrand();
	sz->v=v;
	sz->p=p;
	return sz++;
}

void push_down(Node *o)
{
	for (int i=0;i<2;i++)
		if (o->ch[i]!=null)
		{
			o->ch[i]->addp+=o->addp;
			o->ch[i]->min_vp-=o->addp;
		}
	o->p+=o->addp;
	o->addp=0;
}

void rotate(Node* &o,int d)
{
	Node *k=o->ch[d^1];
	push_down(k);
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}

void insert(Node* &o,int x,int p)
{
	if (o==null)
		o=newnode(x,p);
	else
	{
		int d=(x<=o->v?0:1);
		push_down(o);
		insert(o->ch[d],x,p);
		if (o->ch[d]->r > o->r)
			rotate(o,d^1);
	}
	o->maintain();
}

int get_rank(Node *o,int x)
{
	if (o==null)
		return 0;
	if (x<=o->v)
		return get_rank(o->ch[0],x);
	return get_rank(o->ch[1],x)+o->ch[0]->s+1;
}

void remove(Node* &o,int x)
{
	int d=o->cmp(x);
	push_down(o);
	if (d==-1)
	{
		if (o->ch[0]==null)
			o=o->ch[1];
		else if (o->ch[1]==null)
			o=o->ch[0];
		else
		{
			int d2=(o->ch[0]->r > o->ch[1]->r?1:0);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	}
	else
		remove(o->ch[d],x);
	if (o!=null)
		o->maintain();
}

int find_min(Node* &o)
{
	push_down(o);
	int t;
	if (o->ch[0]->min_vp==o->min_vp)
		t=find_min(o->ch[0]);
	else if (o->v-o->p==o->min_vp)
	{
		t=o->v;
		remove(o,o->v);
	}
	else
		t=find_min(o->ch[1]);
	if (o!=null)
		o->maintain();
	return t;
}

void add(Node *o,int x,int d)
{
	if (o==null)
		return;
	if (o->v<x)
		add(o->ch[1],x,d);
	else
	{
		if (o->ch[1]!=null)
		{
			o->ch[1]->addp+=d;
			o->ch[1]->min_vp-=d;
		}
		o->p+=d;
		add(o->ch[0],x,d);
	}
	o->maintain();
}

int a[MAXN];
priority_queue <int> mns;
priority_queue <int,vector<int>,greater<int> > zro;

void add_v(int a)
{
	int k=get_rank(root,a);
	add(root,a,1);
	insert(root,a,k);
	if (root->min_vp+(int)mns.size()<=0)
	{
		int x=find_min(root);
		add(root,x+1,-1);
		zro.push(x);
	}
}

int main()
{
	null=sz++;
	null->min_vp=INT_MAX;
	int n;
	scanf("%d",&n);
	root=null;
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (a<=-(int)mns.size())
		{
			mns.push(a);
			if (mns.top()==-(int)mns.size()+1)
			{
				zro.push(mns.top());
				mns.pop();
			}
			else
			{
				if (!zro.empty())
				{
					add_v(zro.top());
					zro.pop();
				}
			}
		}
		else
			add_v(a);
		printf("%d\n",root->s-(int)mns.size());
	}
	return 0;
}