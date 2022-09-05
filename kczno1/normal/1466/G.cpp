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

const int N=1e5+5,L=1e6+5,D=1e9+7;
vector<string>s;
s64 wt[N][26],pow_2[N];
int nxt[L*3];
bool ok_pre[L],ok_suf[L];

void init_next(const string &a)
{
	int i,j,n=a.size();
	for(nxt[0]=j=-1,i=1;i<n;nxt[i++]=j){
 		while(~j&&a[j+1]!=a[i])j=nxt[j];
 		if(a[j+1]==a[i])j++;
 	}
}
int calc_appear_count(const string &b,const string &a)
{
	init_next(a);
	int i,j,n=a.size(),m=b.size(),count=0;
	for(j=-1,i=0;i<m;i++){
		while(~j&&a[j+1]!=b[i])j=nxt[j];
		if(a[j+1]==b[i])j++;
		if(j==n-1){++count;j=nxt[j];}
	}
	return count;
}

int q;
void init()
{
	int n;
	cin>>n>>q;
	string s0,t;
	cin>>s0>>t;
	s.push_back(s0);
	pow_2[0]=1;
	rep(i,1,n)
	{
		pow_2[i]=pow_2[i-1]*2%D;
		rep(j,0,25)wt[i][j]=wt[i-1][j]*2%D;
		wt[i][t[i-1]-'a']++;
	}
	int i=0;
	for(;i<n && s.back().size()<1e6;++i)
		s.push_back(s.back()+t[i]+s.back());
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	init();
	
	while(q--)
	{
		int k=read();
		string w;
		cin>>w;
		int i=0;
		while(s[i].size() < w.size() && i<k)++i;
		if(s[i].size() < w.size()){puts("0");continue;}
		s64 ans=calc_appear_count(s[i],w)*pow_2[k-i]%D;

		int n=s[i].size()+w.size(),m=w.size();
		rep(i,0,m+1)ok_pre[i]=ok_suf[i]=0;
		init_next(s[i]+w);
		for(int j=n-1;j>=0;j=nxt[j])
		if(j+1<=m)ok_suf[j+1]=1;
		init_next(w+s[i]);
		for(int j=n-1;j>=0;j=nxt[j])
		if(j+1<=m)ok_pre[j+1]=1;

		ok_pre[0]=ok_suf[0]=1;
		int cnt[26]={};
		rep(i,0,m-1)
		if(ok_pre[i] && ok_suf[m-1-i])++cnt[w[i]-'a'];

		rep(j,0,25)(ans+=cnt[j]*(wt[k][j]-wt[i][j]*pow_2[k-i]%D))%=D;

		printf("%d\n",int( (ans%D+D)%D ));
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/