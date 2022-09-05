#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1e6+5;
int hp[N],ans1[N];
set<pii>Set;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	int sum=0;
	rep(i,1,m)
	{
		hp[i]=read();
		sum+=hp[i]; 
	}
	int t=(sum+n-1)/n;
	printf("%d\n",t);
	hp[m]+=t*n-sum;
	vector<vector<int> > ans=vector<vector<int> >(t,vector<int>(m,1));
	rep(i,1,m)Set.insert({hp[i],i});
	int nt=0,nm=0;
	while(nm<m)
	{
		while(1)
		{
			auto it=--Set.end();
			auto p=*it;
			if(p.first<n)break;
			Set.erase(it);
			rep(i,nm,m-1)ans[nt][i]=p.second;
			++nt;
			Set.insert({p.first-n,p.second});
		}
		if(nt==t){ans1[nm]=n;break;}
		vector<pii>q;
		rep(i,nt,t-1)
		{
			auto it=Set.begin();
			q.push_back(*it);
			Set.erase(it); 
		}
		ans1[nm]=q[0].first;
//		cerr<<nm<<" "<<ans1[nm]<<endl;
		rep(i,nt,t-1)ans[i][nm]=q[i-nt].second;
		rep(i,nt+1,t-1)Set.insert({q[i-nt].first-ans1[nm],q[i-nt].second});
		n-=ans1[nm];
		++nm;
	}
	rep(i,0,m-1)printf("%d ",ans1[i]);
	puts("");
	for(auto arr:ans)
	{
		for(auto x:arr)printf("%d ",x);
		puts("");
	}
}