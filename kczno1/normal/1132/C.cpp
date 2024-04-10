#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y; 
} 
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=5e3+5;
int s[N],cs[N][3],l[N],r[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,m)
	{
		scanf("%d%d",l+i,r+i);	
		++s[l[i]];--s[r[i]+1];
	}
	rep(i,1,n)s[i]+=s[i-1];
	rep(i,1,n)
	{
		rep(j,0,2)cs[i][j]=cs[i-1][j];
		if(s[i]<=2)++cs[i][s[i]];
	}
	int tot=n-cs[n][0];
	int ans=0;
	rep(i,1,m)
	rep(j,i+1,m)
	{
		int l1=l[i],r1=r[i],l2=l[j],r2=r[j];
		if(l1>l2)
		{
			swap(l1,l2);swap(r1,r2);
		}
		if(r1<l2)chmax(ans,tot-(cs[r1][1]-cs[l1-1][1]+cs[r2][1]-cs[l2-1][1]));
		else 
		{
			if(r1>r2)swap(r1,r2);
			chmax(ans,tot-(cs[l2-1][1]-cs[l1-1][1]+cs[r1][2]-cs[l2-1][2]+cs[r2][1]-cs[r1][1]));
		}
	}
	cout<<ans;
}