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

const int N=20000+5;
int a[N];
vector<vector<int>> work(int l,int r)
{
	vector<vector<int>> ans;
	if(l==r)return ans;
	int mid=(l+r)/2;
#define A(i) (a[i]>mid) 
	while(1)
	{
		bool ok=1;
		rep(i,l,mid)ok&=!A(i);
		rep(i,mid+1,r)ok&=A(i);
		if(ok)break;

		vector<int>D;
		int last_0=-1,last_1=-1,i=l;
		while(i<=r)
		{
			int j=i;
			while(j<=r && A(j)==A(i))++j;
			if(A(i))
			{
				if(last_0==-1)
					D.push_back(j-i);
				else 
					last_1=i;
			}
			else 
			{
				if(last_0==-1)
					last_0=i;
				else 
				{
					D.push_back(i-last_0);
					D.push_back(j-i);
					last_0=last_1=-1;
				}
			}
			i=j;
		}
		if(last_0!=-1)
			D.push_back(i-last_0);
		ans.push_back(D);
		i=l;
		for(auto x:D)
		{
			reverse(a+i,a+i+x);
			i+=x;
		}
		reverse(a+l,a+r+1);
	}

	auto ans_l=work(l,mid),ans_r=work(mid+1,r);
	int sz=max(ans_l.size(),ans_r.size());
	rep(i,0,sz-1)
	{
		vector<int>D;
		if(i%2==0)
		{
			if(i<(int)ans_l.size())D.insert(D.end(),ans_l[i].begin(),ans_l[i].end());
			else D.push_back(mid+1-l);
			if(i<(int)ans_r.size())D.insert(D.end(),ans_r[i].begin(),ans_r[i].end());
			else D.push_back(r-mid);
		}
		else 
		{
			if(i<(int)ans_r.size())D.insert(D.end(),ans_r[i].begin(),ans_r[i].end());
			else D.push_back(r-mid);
			if(i<(int)ans_l.size())D.insert(D.end(),ans_l[i].begin(),ans_l[i].end());
			else D.push_back(mid+1-l);
		}
		ans.push_back(D);
	}
	if(sz%2)
	{
		vector<int>D;
		D.push_back(r-mid);
		D.push_back(mid+1-l);
		ans.push_back(D);
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)a[i]=read();
	auto ans=work(1,n);	
	assert(ans.size()<=120);
	printf("%d\n",int(ans.size()));
	for(auto D:ans)
	{
		printf("%d",int(D.size()));
		for(auto x:D)printf(" %d",x);
		puts("");
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/