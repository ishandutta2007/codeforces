#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e6+5,L=20,D=1e9+7;
int n,k,a[N];
pii mx[L][N];int lo[N];
s64 ans;

int query_max(int l,int r)
{
	int j=lo[r-l+1];
	return max(mx[j][l],mx[j][r-(1<<j)+1]).second;
}
s64 V(int l,int r)
{
	if(l>r)swap(l,r);
	s64 ans=0;
	rep(i,0,l-1)ans+=(i+r-1)/(k-1)-(i+k-2)/(k-1)+1;
	return ans%D;
}
void solve(int l,int r)
{
	if(l>r)return ;
	int m=query_max(l,r);
	solve(l,m-1);solve(m+1,r);
	(ans+=a[m]*V(m-l+1,r-m+1))%=D;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>k;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)mx[0][i]={a[i],i};
	rep(j,1,L-1)
	rep(i,1,n-(1<<j)+1)mx[j][i]=max(mx[j-1][i],mx[j-1][i+(1<<j-1)]);
	rep(i,2,n)lo[i]=lo[i/2]+1;
	solve(1,n);
	rep(i,1,n)ans-=a[i];
	cout<<(ans%D+D)%D;
}