#include <bits/stdc++.h>
using namespace std;

const int MAXB=(1<<10)-1,MAXN=205;

struct str
{
	bitset <MAXB> b;
	string pre,suf;
	bool lar;
	int ret;

	void get_ans()
	{
		for (int i=ret+1;i<10;i++)
		{
			bool flag=true;
			int st=(1<<i)-2;
			for (int j=0;j<(1<<i);j++)
				if (!b.test(st+j))
				{
					flag=false;
					break;
				}
			if (!flag)
				break;
			ret=i;
		}
	}

	void init()
	{
		string s;
		cin >> s;
		for (int i=1;i<10&&i<=s.length();i++)
		{
			int st=(1<<i)-2,now=0;
			for (int j=0;j<i;j++)
				if (s[j]=='1')
					now|=1<<j;
			b.set(st+now);
			for (int j=i;j<s.length();j++)
			{
				if (s[j-i]=='1')
					now^=1;
				now>>=1;
				if (s[j]=='1')
					now|=1<<(i-1);
				b.set(st+now);
			}
		}
		if (s.length()<10)
			pre=suf=s;
		else
		{
			pre=s.substr(0,9);
			suf=s.substr(s.length()-9,9);
			lar=true;
		}
		get_ans();
	}

	void merge(const str& s1,const str& s2)
	{
		b=s1.b|s2.b;
		string s=s1.suf+s2.pre;
		for (int i=1;i<10&&i<=s.length();i++)
		{
			int st=(1<<i)-2,now=0;
			for (int j=0;j<i;j++)
				if (s[j]=='1')
					now|=1<<j;
			b.set(st+now);
			for (int j=i;j<s.length();j++)
			{
				if (s[j-i]=='1')
					now^=1;
				now>>=1;
				if (s[j]=='1')
					now|=1<<(i-1);
				b.set(st+now);
			}
		}
		ret=max(s1.ret,s2.ret);
		if (s1.lar)
			pre=s1.pre;
		else
		{
			pre=s1.pre+s2.pre;
			if (pre.length()>9)
			{
				lar=true;
				pre=pre.substr(0,9);
			}
		}
		if (s2.lar)
			suf=s2.suf;
		else
		{
			suf=s1.suf+s2.suf;
			if (suf.length()>9)
			{
				lar=true;
				suf=suf.substr(suf.length()-9,9);
			}
		}
		lar=lar||s1.lar||s2.lar;
		get_ans();
	}
}s[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		s[i].init();
	int m;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[n+i].merge(s[a],s[b]);
		printf("%d\n",s[n+i].ret);
	}
	return 0;
}