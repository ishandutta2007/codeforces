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

const int N=2000+5,D=1e9+7;
void split(map<int,int> &Map,int x)
{
	auto it=--Map.lower_bound(x+1);
	Map[x]=it->second;
}
namespace A 
{
map<int,int>Map;
s64 sum;
void upd(const pii &pr)
{
	int nx=pr.first+1,ny=pr.second;
	if(nx<=Map.begin()->first)return ;
	split(Map,nx);
	while(1)
	{
		auto it=--Map.lower_bound(nx);
		if(it->second>=ny)
		{
			if(nx<=pr.first)
			{
				(sum+=1LL*(pr.first-nx+1)*ny)%=D;
				Map[nx]=ny;
			}
			break;
		}
		(sum-=1LL*(nx-it->first)*it->second)%=D;nx=it->first;
		if(it==Map.begin())
		{
			(sum+=1LL*(pr.first-nx+1)*ny)%=D;
			it->second=ny;
			break;
		}
		Map.erase(it);
	}
}
};
struct Candy
{
	int x,y,c;
};
Candy candy[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,k,L;
	cin>>n>>k>>L;
	rep(i,1,n){candy[i].x=read();candy[i].y=read();candy[i].c=read()-1;}
	sort(candy+1,candy+n+1,[&](const Candy &a,const Candy &b){return a.x<b.x;});
	candy[0].x=-1;
	s64 ans=0;
	per(i,n,1)
	if(candy[i].x>candy[i-1].x)
	{
		int now_x=candy[i].x;
		sort(candy+i,candy+n+1,[&](const Candy &a,const Candy &b){return a.y<b.y;});
		vector<vector<pii>>q(k);
		rep(i,0,k-1)q[i].push_back(pii(now_x,L+1));
		vector<vector<pii>>events(n+1);
		per(j,n,i)
		{
			int nx=candy[j].x+1,ny=candy[j].y+1;
			auto &nq=q[candy[j].c];
			int last_x=L+1;
			while(nq.back().first>nx)
			{
				events[j].push_back(pii(last_x-1,nq.back().second));
				last_x=nq.back().first;
				nq.pop_back();
			}
			events[j].push_back(pii(last_x-1,nq.back().second));
			if(nq.back().first==nx)nq.back().second=ny;
			else nq.push_back(pii(nx,ny));
		}

		A::Map.clear();
		A::Map[now_x]=0;
		A::sum=0;
		rep(i,0,k-1)
		{
			int last_x=L+1;
			for(auto it=q[i].end();--it>=q[i].begin();)
			{
				A::upd(pii(last_x-1,it->second));
				last_x=it->first;
			}
		}
		int last_y=-1;
		rep(j,i,n)
		{	
			(ans+=(1LL*(L-now_x+1)*(L+1)-A::sum)%D*(now_x-candy[i-1].x)%D*(candy[j].y-last_y))%=D;
			last_y=candy[j].y;
			for(auto pr:events[j])A::upd(pr);
		}
	}
	cout<<(ans%D+D)%D<<endl;
}