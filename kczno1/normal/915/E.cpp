#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=500+5,inf=1e9;
/*
ll mi(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}*/
map<int,int>s;int ans;
void del(int l,int r)
{
		map<int,int>::iterator it=s.lower_bound(l);
		if(it!=s.begin())
		{
			--it;
			if(it->second>=l)
			{
				if(it->second>r)
				{
					int _l=it->first,_r=it->second;
					ans-=r-l+1;
					s.erase(it);
					s[_l]=l-1;s[r+1]=_r;
					return ; 
				}
				ans-=it->second-l+1;
				it->second=l-1;
			}
			++it;
		}
		while(it!=s.end()&&it->second<=r)
		{
			ans-=it->second-it->first+1;
			map<int,int>::iterator tmp=it;++it;
			s.erase(tmp);
		}
		if(it!=s.end()&&it->first<=r)
		{
			ans-=r-it->first+1;
			int _r=it->second;
			s.erase(it);
			s[r+1]=_r;
		}
}  

int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int n,m;
	cin>>n>>m;	
	s[1]=n;
	ans=n;
	while(m--)
	{
		int l=read(),r=read(),k=read();
		
		//for(map<int,int>::iterator it=s.begin();it!=s.end();++it)printf("%d %d\n",it->first,it->second);
		del(l,r);
		
		if(k==2){s[l]=r;ans+=r-l+1;}
		printf("%d\n",ans);
	}
}