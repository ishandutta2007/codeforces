#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

const int N=200005;

int len[N],pos[N],key[N],pre[N],next[N],l[N],r[N];
int ed,ql,qr,rt,aux[N],pp[N*5];

void up(int i)
{
	if (pre[i]!=-1)
	{
		len[i]=key[i]-key[pre[i]];
		pos[i]=key[pre[i]];
	}
	else len[i]=0,pos[i]=i;
	if (l[i]!=0)
	{
		if (len[l[i]]/2>len[i]/2)
		{
			len[i]=len[l[i]];
			pos[i]=pos[l[i]];
		}
		else if (len[l[i]]/2==len[i]/2) pos[i]=pos[l[i]];
	}
	if (r[i]!=0)
	{
		if (len[r[i]]/2>len[i]/2)
		{
			len[i]=len[r[i]];
			pos[i]=pos[r[i]];
		}
	}
}

void left(int &i)
{
	int j=r[i]; r[i]=l[j]; l[j]=i; up(i); up(j); i=j;
}

void right(int &i)
{
	int j=l[i]; l[i]=r[j]; r[j]=i; up(i); up(j); i=j;
}

void ins(int &i,int j)
{
	if (i==0)
	{
		ed++; i=ed; key[i]=j; pre[i]=ql; next[i]=qr;
		if (ql!=-1) next[ql]=i;
		if (qr!=-1) pre[qr]=i;
		l[i]=0; r[i]=0; aux[i]=rand();
		up(i);
		return;
	}
	if (j<key[i])
	{
		qr=i;
		ins(l[i],j); up(i);
		if (aux[l[i]]>aux[i]) right(i);
	}
	else
	{
		ql=i;
		ins(r[i],j); up(i);
		if (aux[r[i]]>aux[i]) left(i);
	}
}

void del(int &i,int j)
{
	if (i==0) return;
	if (j==key[i])
	{
		ql=pre[i];
		qr=next[i];
		if (l[i]==0) {i=r[i]; return;}
		if (r[i]==0) {i=l[i]; return;}
		if (aux[l[i]]<aux[r[i]])
		{
			left(i);
			del(l[i],j);
			up(i);
		}
		else
		{
			right(i);
			del(r[i],j);
			up(i);
		}
	}
	if (j<key[i])
	{
		del(l[i],j);
		up(i);
	}
	else
	{
		del(r[i],j);
		up(i);
	}
}

void find(int i,int j)
{
	if (key[i]==j)
	{
		up(i);
		return;
	}
	if (j<key[i])
	{
		find(l[i],j); up(i);
	}
	else
	{
		find(r[i],j); up(i);
	}
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("e.in","r",stdin);
		freopen("e.out","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	rt=0;
	ed=0;
	while (m--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		if (i==1)
		{
			int k;
			if (rt==0) k=1;
			else
			{
				int i=rt;
				while (l[i]!=0) i=l[i];
				int lenl=key[i]-1;
				i=rt;
				while (r[i]!=0) i=r[i];
				int lenr=n-key[i];
				int lenm=len[rt]/2,posm=pos[rt]+lenm;
				if (lenl>=lenr && lenl>=lenm)
				{
					k=1;
				}
				else if (lenm>=lenr)
				{
					k=posm;
				}
				else
				{
					k=n;
				}
			}
			pp[j]=k;
			printf("%d\n",k);
			ql=-1;
			qr=-1;
			ins(rt,k);
		}
		else
		{
			del(rt,pp[j]);
			if (ql!=-1) next[ql]=qr;
			if (qr!=-1) pre[qr]=ql;
			find(rt,key[qr]);
			find(rt,key[ql]);
		}
	}
  return 0;
}