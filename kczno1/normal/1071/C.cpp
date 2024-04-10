#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int a[N];
vector<s64>ans;
void rev(int x,int d)
{
	ans.push_back(s64(x)*N+d);
	a[x]^=1;a[x+d]^=1;a[x+2*d]^=1;
}

const int N1=8,U=1<<N1;
int g[U],fr[U];
void bfs(int n)
{
	int u=(1<<n)-1;
	rep(i,0,u)g[i]=U;
	g[0]=0;
	deque<int>q;
	q.push_back(0);
	while(!q.empty())
	{
		int s=q.front();q.pop_front();
		rep(x,0,n-1)
		rep(d,1,(n-1-x)/2)
		{
			int _s=s^((1+(1<<d)+(1<<d+d))<<x);
			if(g[_s]==U){g[_s]=g[s]+1;fr[_s]=x*N1+d;q.push_back(_s);}
		}
	}
	int mx=0;
	rep(i,0,u)chmax(mx,g[i]);
	cerr<<mx<<endl;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	int l=1,r=n;
	while(r-l+1>N1)
	{
		if(!a[l]){++l;continue;}
		if(!a[r]){--r;continue;}
		if(!a[l+1])
		{
			if(a[l+2])rev(l,2);
			else rev(l,3);
			continue;
		}
		if(a[l+2]){rev(l,1);continue;}
		if(!a[r-1])
		{
			if(a[r-2])rev(r-4,2);
			else rev(r-6,3);
			continue;
		}
		if(a[r-2]){rev(r-2,1);continue;}
		int d=(r-l)/2;
		if(l%2==r%2){rev(l,d);rev(l+1,d-1);}
		else{rev(l,d);rev(l+1,d);}
	}
	bfs(r-l+1);
	while(1)
	{
		int u=0;
		rep(i,l,r)u+=a[i]<<i-l;
		if(!u)break;
		if(g[u]==U){puts("NO");exit(0);}
		rev(l+fr[u]/N1,fr[u]%N1);
	}
	puts("YES");
	printf("%d\n",int(ans.size()));
	for(auto i:ans)
	{
		int x=i/N,d=i%N;
		printf("%d %d %d\n",x,x+d,x+d+d);
	}
}