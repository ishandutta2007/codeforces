/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-20 23:14:03
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#include<assert.h>
#include<set>
#include<vector>
#define i64 long long
const int N=400010,m=200000;
int x[N],y[N],n,_n,A[N],B[N],C[N],c[N];
int cmpx(int a,int b){ return x[a]<x[b]; }
int cmpy(int a,int b){ return y[a]<y[b]; }
template<int *a> struct cmp
{
	int operator()(int x,int y){ return a[x]<a[y]; }
};
std::set<int,cmp<y> > X[N];
std::set<int,cmp<x> > Y[N];
char ans[N];
int main()
{
	n=read(); _n=n;
	fr(i,1,n)
	{
		x[i]=read(); y[i]=read();
		X[x[i]].insert(i);
	}
	fr(i,1,n+n) c[i]=-1;
	fr(i,1,m)
	{
		std::vector<int> d;
		for(auto j:X[i])
		{
//			printf(" %d %d %d\n",i,j,int(Y[y[j]].size()));
			for(auto k:Y[y[j]])
			{
				if(X[x[k]].size()>=2)
				{
					_n++; A[_n]=j; B[_n]=k;
					int l=0;
					for(auto L:X[x[k]]) if(L!=k){ l=L; break; }
					C[_n]=l; x[_n]=x[j]; y[_n]=y[l];
//					printf("%d %d %d\n",j,k,l);
					d.push_back(j); d.push_back(_n); X[x[k]].erase(k); Y[y[k]].erase(k); X[x[l]].erase(l); Y[y[l]].erase(l);
					if(X[i].find(_n)!=X[i].end())
					{
						c[_n]=0; c[*X[i].lower_bound(_n)]=1;
					}
				}
				break;
			}
		}
//		if(i<=4) printf("%d\n",int(d.size()));
		for(auto j:d)
			if(X[i].find(j)!=X[i].end()) X[i].erase(j);
			else X[i].insert(j);
//		if(i==2) return 0;
//		if(X[i].size()){ for(auto j:X[i]) printf("%d ",j); putchar(10); }
//		if(i==2) continue;
		std::vector<int> _x,p;
		for(auto j:X[i]){ _x.push_back(j); p.push_back(Y[y[j]].size()>=1?-1:0); }
		int k=0,o=0;
		fr(j,0,_x.size()-1) if(p[j]==-1)
		{
			res:;
			while(k<_x.size()&&(k==j||p[k]!=o)) k++;
			if(k>=_x.size()){ if(o==0){ o--; k=0; goto res; } else break; }
			int l=0;
			for(auto L:Y[y[_x[j]]]) if(L!=_x[j]){ l=L; break; }
			p[j]=p[k]=1; X[x[l]].erase(l); Y[y[l]].erase(l);
			_n++; A[_n]=_x[k]; B[_n]=_x[j]; C[_n]=l; x[_n]=x[l]; y[_n]=y[_x[k]];
//			printf("%d %d %d\n",_x[j],_x[k],l);
			X[x[_n]].insert(_n); Y[y[_n]].insert(_n);
		}
		fr(j,0,_x.size()-1) if(p[j]==1) X[i].erase(_x[j]);
//		for(auto j:X[i]) printf("%d ",j); if(X[i].size()) putchar(10);
		for(auto j:X[i]) Y[y[j]].insert(j);
	}
//	fr(i,1,m) for(auto j:X[i]) printf("%d\n",j);
	fr(i,1,m) if(X[i].size()>=2)
	{
		int v=0;
		for(auto j:X[i]) c[j]=(v^=1);
	}
	fr(i,1,m) if(Y[i].size()>=2)
	{
		int v=0;
		for(auto j:Y[i]) c[j]=(v^=1);
	}
	fr(i,1,m) for(auto j:X[i]) if(c[j]==-1) c[j]=0;
	fd(i,_n,n+1)
	{
		c[A[i]]=c[C[i]]=c[i]; c[B[i]]=c[i]^1;
	}
	fr(i,1,n) ans[i]=(c[i]?'r':'b');
	printf("%s\n",ans+1);
	return 0;
}
/*
5
3 1
4 4
2 1
4 1
1 1
*/