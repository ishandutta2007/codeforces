#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
char s[MAXN],c[MAXN];
int n,m,q,N,S,i,j,l,r,ans,ne[MAXN],e[405];
struct node
{
    node *s[26],*f;
    int l,d;
};
vector<node*> h[1005];
struct NODE
{
node P[1005],*X,*L,*t,*p,*q,*nq;
void init()
{
	memset(P,0,sizeof(P));
	X=L=P;
}
void ins(int b)
{
    p=++X;
    p->l=L->l+1;
    for(t=L;t&&!t->s[b];t=t->f)t->s[b]=p;
    if(!t)p->f=P;
    else if(t->l+1==(q=t->s[b])->l)p->f=q;
    else
    {
        nq=++X;
        *nq=*q;
        nq->l=t->l+1;
        p->f=q->f=nq;
        for(;t&&t->s[b]==q;t=t->f)t->s[b]=nq;
    }
    L=p;
}
void get(int x,int y)
{
	int i,j;
	for(i=0;i<=S;i++)h[i].clear();
	for(p=P,i=x;i<=y;i++)
	{
		p=p->s[s[i]-'a'];
		p->d++;
	}
	for(p=P;p<=X;p++)h[p->l].push_back(p);
	for(i=S;~i;i--)for(j=h[i].size()-1;~j;j--)
	{
		p=h[i][j];
		if(p->f)p->f->d+=p->d;
	}
}
int ask()
{
	int i;
	for(p=P,i=1;i<=m;i++)if(!p->s[c[i]-'a'])return 0;
	else p=p->s[c[i]-'a'];
	return p->d;
}
}a[405];
int ask(int x,int y)
{
	int i,j,k;
	for(i=x,j=k=0;i<=y;i++)
	{
		for(;j&&c[j+1]!=s[i];j=ne[j]);
		if(c[j+1]==s[i])j++;
		if(j==m)
		{
			k++;
			j=ne[j];
		}
	}
	return k;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	S=sqrt(n);
	N=(n+S-1)/S;
	for(i=1;i<=N;i++)e[i]=i*S;
	e[N]=n;
	for(i=1;i<=N;i++)
	{
		a[i].init();
		for(j=e[i-1]+1;j<=e[i];j++)a[i].ins(s[j]-'a');
		a[i].get(e[i-1]+1,e[i]);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%s",&i,c+1);
			s[i]=c[1];
			i=(i-1)/S+1;
			a[i].init();
			for(j=e[i-1]+1;j<=e[i];j++)a[i].ins(s[j]-'a');
		a[i].get(e[i-1]+1,e[i]);
			c[1]=0;
		}
		else
		{
			scanf("%d%d%s",&l,&r,c+1);
			m=strlen(c+1);
			for(i=2,j=0;i<=m;i++)
			{
				for(;j&&c[j+1]!=c[i];j=ne[j]);
				if(c[j+1]==c[i])j++;
				ne[i]=j;
			}
			if(m>S||(l-1)/S==(r-1)/S)printf("%d\n",ask(l,r));
			else
			{
				for(ans=ask(l,e[(l-1)/S+1])+ask(e[(r-1)/S]+1,r),i=(l-1)/S+2;i<=(r-1)/S;i++)ans+=a[i].ask();
				if(m>1)for(i=(l-1)/S+1;i<=(r-1)/S;i++)ans+=ask(max(l,e[i]-m+2),min(r,e[i]+m-1));
				printf("%d\n",ans);
			}
			fill(c+1,c+m+1,0);
		}
	}
	return 0;
}