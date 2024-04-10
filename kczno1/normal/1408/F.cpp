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

const int N=15000+5;
vector<int>a[N];
vector<pii>ans;

void P(vector<int> &a,const vector<int> &b)
{
	int sz=b.size();
	rep(i,0,sz-1)
	{
		ans.push_back(pii(a[i],b[i]));
		a.push_back(b[i]);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)a[i].push_back(i);
	int l=1,r=n;
	while(r>l)
	{
		if((r-l+1)%2)++l;
		rep(i,l,(l+r)/2)P(a[i],a[r-(i-l)]);		
		r=(l+r)/2;
	}
	//cerr<<l<<" "<<r<<endl;
	//rep(i,1,r)fprintf(stderr,"%d%c",int(a[i].size())," \n"[i==r]);
	l=1;
	while(l+1<r)
	{
		//rep(i,l,r)fprintf(stderr,"%d%c",int(a[i].size())," \n"[i==r]);
		while(a[l].size()<a[l+1].size())
		{
			vector<int>b;
			int sz=a[l].size();
			rep(tmp,1,sz){b.push_back(a[r].back());a[r].pop_back();}
			P(a[l],b);
		}
		P(a[l+1],a[l]);
		++l;
	}
	printf("%d\n",int(ans.size()));
	for(auto pr:ans)printf("%d %d\n",pr.first,pr.second);
}