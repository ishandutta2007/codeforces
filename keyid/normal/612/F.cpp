#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=2005,INF=0x3f3f3f3f;

map <int,vector<int>> ms;

int n,a[MAXN],pre[MAXN],dir[MAXN],val[MAXN],d[MAXN];
stack <int,vector<int>> sta;

inline int get_dis(const int &x,const int &y)
{
	return min((x-y+n)%n,(y-x+n)%n);
}

void output(int x)
{
	if (sta.size()==n)
		return;
	const auto &v=ms[a[x]];
	sta.push(x);
	for (int i=0;i<v.size();i++)
		if (v[i]==x)
		{
			for (int j=(i+dir[x]+(int)v.size())%v.size();j!=i;j=(j+dir[x]+(int)v.size())%v.size())
				sta.push(v[j]);
			output(pre[v[(i-dir[x]+(int)v.size())%v.size()]]);
			break;
		}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif // KeyID
	int s;
	scanf("%d%d",&n,&s);
	s--;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ms[a[i]].pb(i);
	}
	for (int i=0;i<n;i++)
		val[i]=INF;
	for (const int &p:ms.begin()->second)
	{
		pre[p]=s;
		d[p]=get_dis(p,s);
	}
	for (auto it=ms.begin();;)
	{
		auto &v=it->second;
		for (int i=0;i<v.size();i++)
		{
			int p0=v[(i+v.size()-1)%v.size()],p1=v[i],p2=v[(i+1)%v.size()];
			val[p1]=min(d[p0]+(p0-p1+n)%n,d[p2]+(p1-p2+n)%n);
			dir[p1]=d[p0]+(p0-p1+n)%n==val[p1]?1:-1;
		}
		if (++it==ms.end())
			break;
		auto &nxt=it->second;
		int mn=INF;
		for (const int &p:v)
			mn=min(mn,-(p-n)+val[p]);
		for (const int &p:nxt)
			d[p]=p+mn;
		mn=INF;
		for (const int &p:v)
			mn=min(mn,p+n+val[p]);
		for (const int &p:nxt)
			d[p]=min(d[p],mn-p);
		mn=INF;
		int h=0;
		for (int i=0;i<nxt.size();i++)
		{
			while (h<v.size()&&v[h]<nxt[i])
			{
				mn=min(mn,-v[h]+val[v[h]]);
				h++;
			}
			d[nxt[i]]=min(d[nxt[i]],mn+nxt[i]);
		}
		mn=INF;
		h=(int)v.size()-1;
		for (int i=(int)nxt.size()-1;i>=0;i--)
		{
			while (h>=0&&v[h]>nxt[i])
			{
				mn=min(mn,v[h]+val[v[h]]);
				h--;
			}
			d[nxt[i]]=min(d[nxt[i]],mn-nxt[i]);
		}
		mn=INF;
		int id=-1;
		for (const int &p:v)
			if (mn>-(p-n)+val[p])
			{
				mn=-(p-n)+val[p];
				id=p;
			}
		for (const int &p:nxt)
			if (d[p]==p+mn)
				pre[p]=id;
		mn=INF;
		id=-1;
		for (const int &p:v)
			if (mn>p+n+val[p])
			{
				mn=p+n+val[p];
				id=p;
			}
		for (const int &p:nxt)
			if (d[p]==mn-p)
				pre[p]=id;
		mn=INF;
		id=-1;
		h=0;
		for (int i=0;i<nxt.size();i++)
		{
			while (h<v.size()&&v[h]<nxt[i])
			{
				if (mn>-v[h]+val[v[h]])
				{
					mn=-v[h]+val[v[h]];
					id=v[h];
				}
				h++;
			}
			if (d[nxt[i]]==mn+nxt[i])
				pre[nxt[i]]=id;
		}
		mn=INF;
		id=-1;
		h=(int)v.size()-1;
		for (int i=(int)nxt.size()-1;i>=0;i--)
		{
			while (h>=0&&v[h]>nxt[i])
			{
				if (mn>v[h]+val[v[h]])
				{
					mn=v[h]+val[v[h]];
					id=v[h];
				}
				h--;
			}
			if (d[nxt[i]]==mn-nxt[i])
				pre[nxt[i]]=id;
		}
	}
	int ans=INF;
	for (const auto &p:ms.rbegin()->second)
		ans=min(ans,val[p]);
	printf("%d\n",ans);
	for (const auto &p:ms.rbegin()->second)
		if (ans==val[p])
		{
			output(p);
			break;
		}
	int now=s;
	while (!sta.empty())
	{
		int x=sta.top();sta.pop();
		int d=get_dis(x,now);
		putchar(d==(x-now+n)%n?'+':'-');
		printf("%d\n",d);
		now=x;
	}
	return 0;
}