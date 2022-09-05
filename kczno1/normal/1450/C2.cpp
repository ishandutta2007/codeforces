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

const int N=300+5;
char s[N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		rep(i,1,n)scanf("%s",s[i]+1);
		vector<pii>X[3],O[3];
		rep(i,1,n)
		rep(j,1,n)
		if(s[i][j]=='X')X[(i+j)%3].push_back(pii(i,j));
		else 
		if(s[i][j]=='O')O[(i+j)%3].push_back(pii(i,j));
		pii mn={0,1};
		rep(i,0,2)
		rep(j,0,2)
		if(i!=j&&X[i].size()+O[j].size()<X[mn.first].size()+O[mn.second].size())
			mn={i,j};
		for(auto pr:X[mn.first])s[pr.first][pr.second]='O';
		for(auto pr:O[mn.second])s[pr.first][pr.second]='X';
		rep(i,1,n)printf("%s\n",s[i]+1);
	}	
}