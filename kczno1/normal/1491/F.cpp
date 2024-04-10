//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
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

int query(vector<int> a,vector<int> b)
{
	printf("? %d %d\n",int(a.size()),int(b.size()));
	for(auto x:a)printf("%d ",x);puts("");
	for(auto x:b)printf("%d ",x);puts("");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
void work()
{
	int n;
	scanf("%d",&n);
	vector<int>a;
	a.push_back(1);
	rep(i,2,n)
	{
		vector<int>b;
		b.push_back(i);
		if(query(a,b))
		{
			vector<int>ans;
			int l=1,r=i-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				a.clear();
				rep(i,l,mid)a.push_back(i);
				if(query(a,b))r=mid;
				else l=mid+1;
			}
			rep(j,1,i-1)
			if(j!=l)ans.push_back(j);
			rep(j,i+1,n)
			{
				a.clear();
				a.push_back(j);
				if(query(a,b)==0)ans.push_back(j);
			}
			printf("! %d",int(ans.size()));
			for(auto x:ans)printf(" %d",x);
			puts("");
			fflush(stdout);
			return ;
		}
		a.push_back(i);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)work();
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/