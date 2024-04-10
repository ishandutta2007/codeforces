#include <bits/stdc++.h>
using namespace std;

const int MAXM=2005;

typedef pair <int,int> pii;

bitset <MAXM> b[MAXM],pre[MAXM];
int cnt[MAXM];

struct cmp
{
	bool operator () (int x,int y) const
	{
		return cnt[x]!=cnt[y]?cnt[x]<cnt[y]:x<y;
	}
};

set <int,cmp> s;
set <pii> ok;

bool check(int x,int y)
{
	return (b[x]&b[y])!=b[x];
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		s.insert(i);
	for (int i=1;i<=m;i++)
	{
		pre[i]=pre[i-1];
		pre[i].set(i);
	}
	while (q--)
	{
		int a,l,r;
		scanf("%d%d%d",&a,&l,&r);
		s.erase(a);
		auto k=s.lower_bound(a),k2=k;
		if (k!=s.begin())
		{
			--k2;
			if (check(*k2,a))
				ok.erase({*k2,a});
		}
		if (k!=s.end())
		{
			if (check(a,*k))
				ok.erase({a,*k});
		}
		if (k!=s.begin()&&k!=s.end())
			if (check(*k2,*k))
				ok.insert({*k2,*k});
		b[a]^=pre[r]^pre[l-1];
		cnt[a]=b[a].count();
		k=s.lower_bound(a);
		k2=k;
		if (k!=s.begin())
		{
			--k2;
			if (check(*k2,a))
				ok.insert({*k2,a});
			if (k!=s.end()&&check(*k2,*k))
				ok.erase({*k2,*k});
		}
		if (k!=s.end())
			if (check(a,*k))
				ok.insert({a,*k});
		s.insert(a);
		if (!ok.empty())
		{
			auto ret=*ok.begin();
			int x1=ret.first,x2=ret.second;
			auto tmp=b[x1]^b[x2];
			int y1=(b[x1]&tmp)._Find_first(),y2=(b[x2]&tmp)._Find_first();
			if (x1>x2)
				swap(x1,x2);
			if (y1>y2)
				swap(y1,y2);
			printf("%d %d %d %d\n",x1,y1,x2,y2);
		}
		else
			puts("-1");
	}
	return 0;
}