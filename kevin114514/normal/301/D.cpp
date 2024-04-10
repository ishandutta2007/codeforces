#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
struct BinaryCountTree
{
	private:
		const static int SIZE=(1<<18);
		int value[SIZE+SIZE];
		const inline int Count(int x)
		{
			int len=x;
			int ret=0;
			while(len)
			{
				int nlen=len&(-len);
//				cout<<nlen<<endl;
				ret+=value[(x+SIZE-1)/nlen];
				len-=nlen;
				x-=nlen;
			}
			return ret;
		}
	
	public:
		const inline int size()
		{
			return SIZE;
		}
		const inline void clear()
		{
			memset(value,0,sizeof(value));
		}
		const inline int key(int p)
		{
			return value[p+SIZE];
		}
		const inline int RangeSum(int l,int r)
		{
			if(l)
				return Count(r)-Count(l-1);
			else	return Count(r);
		}
		const inline void update(int p)//operation:add 1 ; comparision:+
		{
			register int pp=p;
			pp--;
			pp+=SIZE;
			while(pp)
			{
				value[pp]++;
				pp/=2;
			}
			return ;
		}
};
BinaryCountTree T;
int ind[200200];
pair<int,int> p[4002000];
int sz;
pair<pair<int,int>,int> q[200200];
int ans[200200];
int main()
{
	T.clear();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ind[x]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			p[sz++]=mp(max(ind[i],ind[j]),min(ind[i],ind[j]));
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q[i]=mp(mp(r,l),i);
	}
//	cout<<sz<<endl;
//	puts(">");
	sort(p,p+sz);
//	puts(">");
	sort(q,q+m);
//	puts(">");
	int pos=0;
//	cout<<m<<endl;
	for(int i=0;i<m;i++)
	{
//		puts(">!!!!");
//			cout<<pos<<endl;
		while(pos<sz&&p[pos].first<=q[i].first.first)
		{
//			puts("!>!");
			T.update(p[pos].second);
			pos++;
		}
//		puts(">");
		ans[q[i].second]=T.RangeSum(q[i].first.second,q[i].first.first);
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}