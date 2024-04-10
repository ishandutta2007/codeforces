#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define mp make_pair
const int D1=998244353,D2=1e9+7,w=29;
pii operator +(const pii &pr,int x)
{
	return mp(((ll)pr.first*w+x)%D1,((ll)pr.second*w+x)%D2);
}
pii operator *(const pii &p1,const pii &p2)
{
	return mp((ll)p1.first*p2.first%D1,(ll)p1.second*p2.second%D2);
}
pii operator -(const pii &p1,const pii &p2)
{
	return mp((p1.first-p2.first+D1)%D1,(p1.second-p2.second+D2)%D2);
}
const int N=5e6+5;
int n,dp[N];
pii mi_w[N];
struct HASH
{
char a[N];
pii s[N];
void init()
{
	rep(i,1,n)s[i]=s[i-1]+a[i];
}
pii qiu(int l,int r)
{
	return s[r]-s[l-1]*mi_w[r-l+1];
}
};
HASH s,ns;

int main()
{
//	freopen("1.in","r",stdin);
	scanf("%s",s.a+1);
	n=strlen(s.a+1);
	rep(i,1,n)ns.a[i]=s.a[n-i+1];
	mi_w[0]=mp(1,1);
	rep(i,1,n)mi_w[i]=mi_w[i-1]+0;
	s.init();ns.init();
	int ans=0;
	rep(i,1,n)
	{
		int j=i/2;
		if(s.qiu(1,j)==ns.qiu(n-i+1,n-(i-j+1)+1))dp[i]=dp[j]+1;
		ans+=dp[i];
	}
	cout<<ans;
}