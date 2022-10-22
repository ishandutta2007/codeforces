#include <bits/stdc++.h>

using namespace std;

mt19937 s(chrono::steady_clock::now().time_since_epoch().count() ^ 19260817);

inline int rnd(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(s);
}

const int N = 1e6 + 50;
int n, m, cnt[N];

template<int mod = 19260817>
struct ht
{
	int head[mod], nxt[N], cnt;
	long long ver[N];
	ht()
	{
		cnt = 0;
		memset(head, 0, sizeof head);
	}
	inline void add(long long v)
	{
		int u = v % mod;
		nxt[++cnt] = head[u];
		ver[cnt] = v;
		head[u] = cnt;
	}
	inline bool chk(long long v)
	{
		int u = v % mod;
		for (int i = head[u]; i; i = nxt[i])
			if (ver[i] == v)
				return true;
		return false;
	}
};

ht<19260817> H;

inline long long id(int u, int v)
{
	if (u > v) swap(u, v);
	return 233333ll * u + v;
}

int main()
{
	time_t aa=clock();
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		H.add(id(u, v));
	}
	int a[5];
	for (int i = 1; i <= 2e6; ++i)
	{
		for (int j=0;j<5;++j)
		{
			a[j]=rnd(1,n);
			while(cnt[a[j]])a[j]=rnd(1,n);
			cnt[a[j]]=1;
		}
		int cnt = 0;
		for (int i=0;i<5;++i)
			for(int j=0;j<i;++j)
				cnt += H.chk(id(a[i],a[j]));
		if(cnt==0||cnt==10)
		{
			for(int i=0;i<5;++i)printf("%d ", a[i]);
			cerr<<endl<<(clock()-aa)*1./CLOCKS_PER_SEC;
			return 0;
		}
		for(int j=0;j<5;++j)::cnt[a[j]]=0;
	}
	puts("-1");
	cerr<<(clock()-aa)*1./CLOCKS_PER_SEC;
}