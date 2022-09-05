//# pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}

#define gc (c=getchar())
int read()
{
	char c;
    while(gc<'-');
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}

const int N=5e3+5,D=998244353;
int C[N][N],jie[N];

ll F(int n,int m)
{
	int mi=min(n,m);
	ll ans=0;
	rep(i,0,mi) (ans+=(ll)C[n][i]*C[m][i]%D*jie[i])%=D;
	return ans;
}

int main()
{
    //freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    int n=5e3;
    rep(i,0,n)
    {
    	C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%D; 
	} 
	jie[0]=1;
	rep(i,1,n)jie[i]=(ll)jie[i-1]*i%D;
	cout<<F(a,b)*F(a,c)%D*F(b,c)%D;
}