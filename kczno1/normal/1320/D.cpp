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
 
const int N=2e5+5;
int D[3];
s64 mi_2[N][3],Hash[N][3];
char s[N];int c1[N],dy[N],a[N],pre[N],nex[N];
 
void get_Hash(s64 a[],int l,int r)
{
	rep(i,0,2)a[i]=((Hash[r][i]-Hash[l][i]*mi_2[r-l][i])%D[i]+D[i])%D[i];
}
void get(s64 a[],int l,int r)
{
	--l;
	r=l+r;
	a[3]=c1[r]-c1[l];
	//cerr<<a[3]<<endl;
	if(a[3]==r-l)
	{
		rep(i,0,2)a[i]=0;
		return ;
	}
	int l1,r1;
	if(s[r]=='0')r1=r;
	else r1=pre[r]-1;
	if(s[l+1]=='1')l1=nex[l+1]+1;
	else l1=l+1;
	get_Hash(a,dy[l1]-1,dy[r1]);
	int len=dy[r1]-dy[l1]+1;
	if((r-r1)%2)
	{
		++len;
		rep(i,0,2)a[i]=(a[i]*2+1)%D[i];
	}
	if((l1-l+1)%2)
	{
		rep(i,0,2)a[i]=(a[i]+mi_2[len][i])%D[i];
	}
}
 
int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	srand(time(0));
	D[0]=1e9+7;D[1]=998244353;D[2]=(1LL*rand()*32768+rand())%100000000+1e9;
	int n=read();
	scanf("%s",s+1);
	rep(i,1,n)c1[i]=c1[i-1]+(s[i]=='1');
	rep(i,1,n)
	if(s[i]=='1')pre[i]=(s[i-1]=='1')?pre[i-1]:i;
	per(i,n,1)
	if(s[i]=='1')nex[i]=(s[i+1]=='1')?nex[i+1]:i;
	int t=0;
	rep(i,1,n)
	if(s[i]=='0')dy[i]=++t;
	else 
	{
		if((nex[i]-i+1)%2)a[++t]=1;
		i=nex[i];
	}
	rep(j,0,2)mi_2[0][j]=1;
	rep(i,1,n)
	rep(j,0,2)
	{
		mi_2[i][j]=mi_2[i-1][j]*2%D[j];
		Hash[i][j]=(Hash[i-1][j]*2+a[i])%D[j];
	}
	
	int m=read();
	while(m--)
	{
		static s64 a[2][4];
		int l1=read(),l2=read(),l=read();
		get(a[0],l1,l);
		get(a[1],l2,l);
		bool ok=1;
		rep(i,0,3)ok&=a[0][i]==a[1][i];
		puts(ok?"Yes":"No");
	}
}