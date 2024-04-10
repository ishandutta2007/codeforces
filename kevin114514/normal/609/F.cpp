#include<bits/stdc++.h>
using namespace std;
int a[500500],b[500500];
int addr[500500]; 
struct SegTree
{
	int key[1502000];
	const static int SIZE=524288;
	inline void clear()
	{
		memset(key,0,sizeof(key));
	}
	inline void Change(int x,int val)
	{
		key[x+SIZE]+=val;
		int pos=x+SIZE;
		while(pos)
		{
			key[pos]=max(key[pos],key[x+SIZE]);
			pos/=2;
		}
		return ;
	}
	inline int RangeMax(int r)
	{
		int res=0;
		int l=SIZE;
		r+=SIZE;
		while(l!=r)
		{
			int len=r-l;
			int nlen=len&(-len);
			res=max(res,key[(r-1)/nlen]);
			r-=nlen;
		}
		return res;
	}
};
SegTree ST;
multiset<pair<int,int> > food;
pair<pair<int,int>,int> INPUT[500500];
int ind[500500];

int main()
{
	ST.clear();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>INPUT[i].first.first>>INPUT[i].first.second;
		INPUT[i].second=i;
	}
	sort(INPUT,INPUT+n);
	for(int i=0;i<n;i++)
	{
		addr[i]=INPUT[i].first.first;
		b[i]=INPUT[i].first.second;
		ST.Change(i,addr[i]+b[i]);
		ind[INPUT[i].second]=i;
	}
	while(m--)
	{
		int x,delta;
		cin>>x>>delta;
		int lb=0,ub=n;
		while(lb<ub)
		{
			int mid=(lb+ub-1)/2;
			//cout<<lb<<" "<<ub<<" "<<mid<<endl;
			if(ST.RangeMax(mid+1)<x)
				lb=mid+1;
			else	ub=mid;
		}
		if(lb>=n||addr[lb]>x)
		{
			food.insert(make_pair(x,delta));
			continue;
		}
		ST.Change(lb,delta);
		a[lb]++;
		b[lb]+=delta;
		multiset<pair<int,int> >::iterator it=food.lower_bound(make_pair(addr[lb],-1));
		while(it!=food.end()&&ST.key[ST.SIZE+lb]>=it->first)
		{
			ST.Change(lb,it->second);
			a[lb]++;
			b[lb]+=it->second;
			multiset<pair<int,int> >::iterator ittmp=it;
			it++;
			food.erase(ittmp);
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[ind[i]]<<" "<<b[ind[i]]<<endl;
	return 0;
}