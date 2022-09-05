#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=6e5+5;
int a[N],b[N],s[N];
int n,l;

void add(int l,int r,int w)
{
	l=(l%n+n)%n;r=(r%n+n)%n;
	if(l>r){add(l,n-1,w);add(0,r,w);}
	else {s[l]+=w;s[r+1]-=w;}
}
bool ok(int len)
{
	rep(i,0,n)s[i]=0;
	int l=1,r=0;
	rep(i,1,n)
	{
		while(a[i]-b[l]>len)++l;
		while(r<3*n&&b[r+1]-a[i]<=len)++r;
		if(r-l+1>=n)add(0,n-1,1);
		else 
		if(l<=r)add(l-i,r-i,1);
	}
	rep(i,1,n)s[i]+=s[i-1];
	rep(i,0,n-1)
	if(s[i]==n)return 1;
	return 0;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>l;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	rep(i,1,n)b[i]-=l; 
	rep(i,n+1,n*3)b[i]=b[i-n]+l;
	int l=-1,r=::l;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	cout<<r;
}