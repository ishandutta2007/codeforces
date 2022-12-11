#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int m,start_seg[MAXN],sum[MAXN],C[2][MAXN];
LL Cll[2][MAXN];
vector <int> end_seg[MAXN];
deque <int> p[2];
multiset <int> s[2];

void add(int x,int d)
{
	int *T=C[x&1];
	for (;x<=m;x+=x&-x)
		T[x]+=d;
}

int query(int t,int x)
{
	int *T=C[t],ret=0;
	for (;x;x-=x&-x)
		ret+=T[x];
	return ret;
}

void addll(int x,int d)
{
	LL *T=Cll[x&1];
	for (;x<=m;x+=x&-x)
		T[x]+=d;
}

LL queryll(int t,int x)
{
	LL *T=Cll[t],ret=0;
	for (;x;x-=x&-x)
		ret+=T[x];
	return ret;
}

void add(int d)
{
	p[d&1].push_back(d);
	add(d,1);
	addll(d,d);
}

void del(int d)
{
	add(d,-1);
	addll(d,-d);
}

int main()
{
	int n;
	scanf("%d%d",&n,&m);
	while (n--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		sum[l]++;
		sum[r+1]--;
		start_seg[l]++;
		end_seg[r].push_back(l);
	}
	for (int i=1;i<=m;i++)
		sum[i]+=sum[i-1];
	LL ans=0;
	for (int i=1;i<=m;i++)
	{
		while (start_seg[i]--)
			s[i&1].insert(i);
		for (int j=0;j<end_seg[i-1].size();j++)
		{
			int l=end_seg[i-1][j];
			s[l&1].erase(s[l&1].find(l));
			deque <int> &t=p[i&1];
			while (!t.empty()&&t.back()>=l)
			{
				del(t.back());
				t.pop_back();
			}
			if ((i-l&1)==0)
			{
				while (!t.empty()&&t.front()<=l)
				{
					del(t.front());
					t.pop_front();
				}
				deque <int> &t2=p[i&1^1];
				while (!t2.empty()&&t2.front()<=l)
				{
					del(t2.front());
					t2.pop_front();
				}
			}
		}
		if (sum[i])
		{
			add(i);
			for (int j=i-1;j>0&&sum[j]==0;j--)
				add(j);
			if (!s[i&1^1].empty())
			{
				int k=*s[i&1^1].rbegin();
				ans+=(i+1LL)*(query(i&1,i)-query(i&1,k))-(queryll(i&1,i)-queryll(i&1,k));
			}
			else
			{
				int k=*s[i&1].begin();
				ans+=(i+1LL)*(query(i&1,i)+query(i&1^1,k))-queryll(i&1,i)-queryll(i&1^1,k);
			}
		}
		else
			ans+=(i+1LL)*(query(0,i)+query(1,i))-queryll(0,i)-queryll(1,i);
	}
	printf("%lld",ans);
	return 0;
}