#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxp=1e7+20;
const int maxn=1e5+20;

int prime[maxp],mark[maxp],d[maxp],ptot;
int a[maxn];

inline void prepare()
{
	REP(i,2,1e7)
	{
		if(!mark[i])prime[++ptot]=i,d[i]=i;
		for(int j=1,k;j<=ptot && i*prime[j]<=1e7;j++)
		{
			k=i*prime[j]; mark[k]=1;
			d[k]=prime[j];
			if(!(i%prime[j]))break;
		}
	}
}

int n,k;
vector<int>ys[maxn];
vector<int>ys1[maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)
	{
		int x=a[i];
		while(x>1)
		{
			int p=d[x];
			while(!(x%p))x/=p;
			ys[i].push_back(p);
		}

		int len=SZ(ys[i]);
		REP(j,0,(1<<len)-1)
		{
			int res=1;
			REP(k,0,len-1)if(j>>k&1)
				res*=ys[i][k];
			ys1[i].push_back(res);
		}
	}
}

vector<int>newbie; int In[maxn];
unordered_map<int,int>mp;

inline int ask(int x){ return mp.count(x)?mp[x]:0;}

vector<int>ed[maxn];
int m;

void solve(int l,int r,vector<int> id)
{
	if(l==r)
	{
		for(int x:id)ed[l].push_back(x);
		return ;
	}
	mp.clear();
	int mid=l+r>>1;
	REP(i,l,mid)for(int x:ys1[newbie[i]])mp[x]++;
	vector<int>L,R;
	for(int i:id)
	{
		int res=0;
		REP(j,0,SZ(ys1[i])-1)res+=(__builtin_parity(j)?-1:1)*ask(ys1[i][j]);
		if(res)L.push_back(i);
		else R.push_back(i);
	}
	solve(l,mid,L);
	solve(mid+1,r,R);
}

int num[maxn],id[maxn];

inline void doing()
{
	REP(i,1,n)
	{
		int len=SZ(ys[i]);
		int ans=0;
		REP(j,0,(1<<len)-1)
		{
			ans+=(__builtin_parity(j)?-1:1)*ask(ys1[i][j]);
		}
		if(!ans)
		{
			In[i]=1;
			newbie.push_back(i);
			REP(j,0,(1<<len)-1)mp[ys1[i][j]]++;
		}
	}
	if(SZ(newbie)>=k)
	{
		REP(i,0,k-1)printf("%d ",newbie[i]); puts("");return;
	}else
	{
		mp.clear();
		m=SZ(newbie);
		vector<int>now;
		REP(i,1,n)if(!In[i])now.push_back(i);
		solve(0,m-1,now);
		REP(i,0,m-1)num[i]=SZ(ed[i]),id[i]=i;
		sort(id+1,id+m,[](int a,int b){ return num[a]>num[b];});
		int have=0;
		REP(i,0,m-1)if(num[id[i]])have+=num[id[i]]+1;
		REP(i,0,m-1)if(num[id[i]])
		{
			int t=min(num[id[i]]-1,have-k);
			num[id[i]]-=t;
			have-=t;
		}
		if(have>k)
		{
			if(have-k&1)
			{
				REP(i,0,m-1)if(SZ(ed[i])>1)num[i]++,have++;
			}
			REP(j,0,m-1)if(have>k && num[j]==1)num[j]--,have-=2;
		}
		vector<int>ans;
		REP(i,0,m-1)if(num[i])
		{
			ans.push_back(newbie[i]);
			REP(j,0,num[i]-1)ans.push_back(ed[i][j]);
		}
		for(int x:ans)printf("%d ",x);
	}
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}