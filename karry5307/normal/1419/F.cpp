#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e3+51;
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x==rhs.x?this->y<rhs.y:this->x<rhs.x;
	}
};
map<ll,vector<Tuple>>row,col;
ll n,totr,totc,l,r,mid,res=-1;
ll ffa[MAXN],x[MAXN],y[MAXN],bel[MAXN],rows[MAXN],cols[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void merge(ll x,ll y)
{
	ll fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		ffa[fy]=fx;
	}
}
inline ll check(ll mid)
{
	ll blk=0,p,q,r,s,lx,rx;
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i+1;j<=n;j++)
		{
			if(x[i]==x[j]&&abs(y[i]-y[j])<=mid)
			{
				merge(i,j);
			}
			if(y[i]==y[j]&&abs(x[i]-x[j])<=mid)
			{
				merge(i,j);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		blk+=(find(i)==i);
	}
	if(blk==1)
	{
		return 1;
	}
	if(blk>4)
	{
		return 0;
	}
	for(register int i=1;i<=n;i++)
	{
		bel[i]=ffa[i];
	}
	if(blk==2)
	{
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=n;j++)
			{
				if(bel[i]==bel[j])
				{
					continue;
				}
				if(x[i]==x[j]&&abs(y[i]-y[j])<=2*mid)
				{
					return 1;
				}
				if(y[i]==y[j]&&abs(x[i]-x[j])<=2*mid)
				{
					return 1;
				}
				if(abs(x[i]-x[j])<=mid&&abs(y[i]-y[j])<=mid)
				{
					return 1;
				}
			}
		}
		return 0;
	}
	if(blk==3)
	{
		vector<Tuple>v;
		for(register int i=1;i<=totr;i++)
		{
			for(register int j=1;j<row[rows[i]].size();j++)
			{
				p=row[rows[i]][j-1].y,q=row[rows[i]][j].y;
				bel[p]!=bel[q]?v.push_back((Tuple){p,q}):(void)1;
			}
		}
		for(register int i=1;i<=totc;i++)
		{
			for(register int j=1;j<col[cols[i]].size();j++)
			{
				p=col[cols[i]][j-1].y,q=col[cols[i]][j].y;
				bel[p]!=bel[q]?v.push_back((Tuple){p,q}):(void)1;
			}
		}
		for(register int i=0;i<v.size();i++)
		{
			p=v[i].x,q=v[i].y;
			for(register int j=1;j<=n;j++)
			{
				if(bel[p]==bel[j]||bel[q]==bel[j])
				{
					continue;
				}
				if(x[p]==x[q])
				{
					lx=min(y[p],y[q]),rx=max(y[p],y[q]);
					if(y[j]>lx&&y[j]<rx&&abs(x[j]-x[p])<=mid)
					{
						if(abs(y[j]-y[p]<=mid)&&abs(y[j]-y[q])<=mid)
						{
							return 1;
						}
					}
				}
				else
				{
					lx=min(x[p],x[q]),rx=max(x[p],x[q]);
					if(x[j]>lx&&x[j]<rx&&abs(y[j]-y[p])<=mid)
					{
						if(abs(x[j]-x[p]<=mid)&&abs(x[j]-x[q])<=mid)
						{
							return 1;
						}
					}
				}
			}
		}
		return 0;
	}
	if(blk==4)
	{
		vector<Tuple>vx,vy;
		for(register int i=1;i<=totr;i++)
		{
			for(register int j=1;j<row[rows[i]].size();j++)
			{
				p=row[rows[i]][j-1].y,q=row[rows[i]][j].y;
				bel[p]!=bel[q]?vx.push_back((Tuple){p,q}):(void)1;
			}
		}
		for(register int i=1;i<=totc;i++)
		{
			for(register int j=1;j<col[cols[i]].size();j++)
			{
				p=col[cols[i]][j-1].y,q=col[cols[i]][j].y;
				bel[p]!=bel[q]?vy.push_back((Tuple){p,q}):(void)1;
			}
		}
		for(register int i=0;i<vx.size();i++)
		{
			for(register int j=0;j<vy.size();j++)
			{
				p=vx[i].x,q=vx[i].y,r=vy[j].x,s=vy[j].y,lx=x[p],rx=y[r];
				if(bel[p]==bel[r]||bel[p]==bel[s])
				{
					continue;
				}
				if(bel[q]==bel[r]||bel[q]==bel[s])
				{
					continue;
				}
				if(y[r]<=min(y[p],y[q])||y[r]>=max(y[p],y[q]))
				{
					continue;
				}
				if(x[p]<=min(x[r],x[s])||x[p]>=max(x[r],x[s]))
				{
					continue;
				}
				if(abs(rx-y[p])<=mid&&abs(rx-y[q])<=mid)
				{
					if(abs(lx-x[r])<=mid&&abs(lx-x[s])<=mid)
					{
						return 1;
					}
				}
			}
		}
		return 0;
	}
}
int main()
{
	n=read(),r=2e9;
	for(register int i=1;i<=n;i++)
	{
		rows[++totr]=x[i]=read(),cols[++totc]=y[i]=read();
		row[x[i]].push_back((Tuple){y[i],i});
		col[y[i]].push_back((Tuple){x[i],i});
	} 
	sort(rows+1,rows+totr+1),sort(cols+1,cols+totc+1);
	totr=unique(rows+1,rows+totr+1)-rows-1;
	totc=unique(cols+1,cols+totc+1)-cols-1;
	for(register int i=1;i<=totr;i++)
	{
		sort(row[rows[i]].begin(),row[rows[i]].end());
	}
	for(register int i=1;i<=totc;i++)
	{
		sort(col[cols[i]].begin(),col[cols[i]].end());
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?res=mid,r=mid-1:l=mid+1;
	}
	printf("%d\n",res);
}