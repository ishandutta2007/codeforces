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

const int N=60+5;
char s[N][N];
bool row[N],col[N],ap_row[N],ap_col[N];
int work()
{
	int n=read(),m=read();
	rep(i,1,n)scanf("%s",s[i]+1);
	bool a_ap=0,p_ap=0;
	rep(i,1,N-1){row[i]=col[i]=1;ap_row[i]=ap_col[i]=0;} 
	rep(i,1,n)
	rep(j,1,m)
	if(s[i][j]=='A'){a_ap=1;ap_row[i]=ap_col[j]=1;}
	else {p_ap=1;row[i]=col[j]=0;}
	if(a_ap==0)return -1;
	if(p_ap==0)return 0;
	if(row[1]||row[n]||col[1]||col[m])return 1;
	if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A')return 2;
	rep(i,1,n)
	if(row[i])return 2;
	rep(j,1,m)
	if(col[j])return 2;
	if(ap_row[1]||ap_row[n]||ap_col[1]||ap_col[m])return 3;
	return 4;
} 

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int ans=work();
		if(ans==-1)puts("MORTAL");
		else printf("%d\n",ans);
	}
}