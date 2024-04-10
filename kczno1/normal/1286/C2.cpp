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
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
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

const int N=100+5;
char ans[N];

map<vector<int>,int> query(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	string s;map<vector<int>,int> mp;
	rep(tmp,1,(r-l+1)*(r-l+2)/2)
	{
		cin>>s;
		vector<int>cnt(26);
		for(auto c:s)++cnt[c-'a'];
		++mp[cnt];
	}
	return mp;
}
char find(const vector<int> &cnt)
{
	rep(i,0,25)
	if(cnt[i])return 'a'+i;
	return 0;	
}
vector<int> operator -(vector<int> a,const vector<int> &b)
{
	rep(i,0,25)a[i]-=b[i];
	return a;
}
void operator +=(vector<int> &a,const vector<int> &b)
{
	rep(i,0,25)a[i]+=b[i];
}
void brute(int l,int r)
{
	auto mp1=query(l,r);
	if(r-l+1==1)
	{
		ans[l]=find(mp1.begin()->first);
		return ;
	}
	auto mp2=query(l+1,r);vector<vector<int>>a(r-l+1);
	for(auto pr:mp1)
	if(pr.second>mp2[pr.first])a[accumulate(pr.first.begin() , pr.first.end(),0)-1]=pr.first;
	ans[l]=find(a[0]);
	rep(i,l+1,r)ans[i]=find(a[i-l]-a[i-l-1]);
}

int main()
{
#ifdef kcz
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	int m=(n+1)/2;
	brute(1,m);
	auto mp=query(1,n);
	vector<vector<int>>a(n,vector<int>(26));
	for(auto pr:mp)
	rep(tmp,1,pr.second)a[accumulate(pr.first.begin() , pr.first.end(),0)-1]+=pr.first;
	vector<int>now(26);
	rep(i,1,n/2)
	{
		++now[ans[i]-'a'];
		++now[(ans[n-i+1]=find(a[0]-(a[i]-a[i-1])-now))-'a'];
	}
	printf("! %s\n",ans+1);
}