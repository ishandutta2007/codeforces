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

int n;
vector<int> p;

int main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#else
	freopen("1.in","r",stdin);
#endif
	cin>>n;
	p.resize(n);
	for(int i=0;i<n;++i) {
		cin>>p[i];
	}
	vector<pii>mx(3);
	for(int i=0;i+1<n;)
	{
		int j=i+1;
		while(j+1<n && (p[i]<p[i+1])==(p[j]<p[j+1]))++j;
		
		mx.push_back({j-i,i});
		
		i=j;
	} 
	sort(mx.begin(),mx.end(),greater<pii>());
	if(mx[0].first%2){
		puts("0");
		exit(0);
	}
	if(mx[0].first!=mx[1].first){
		puts("0");
		exit(0);
	}
	if(mx[1].first>mx[2].first && mx[1].second+mx[1].first==mx[0].second && p[mx[0].second]>p[mx[0].second+1]){
		puts("1");
	}
	else puts("0");
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/