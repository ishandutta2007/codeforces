#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6+10;
const int NN=1e6;
struct re{
	int a,b;
}b[N];
int v[N];
bool cmp(re x,re y)
{
	if (x.a!=y.a) return x.a<y.a;
	return x.b>y.b;
}
#define lowbit(x) (x&(-x))
void add(int x,int y)
{
	while (x>0)
	{
		v[x]=max(v[x],y);
		x-=lowbit(x);
	}
}
int q(int x)
{
	int ans=-1e9;
	while (x<=NN)
	{
		ans=max(ans,v[x]);
		x+=lowbit(x);
	}
	return ans;
}
int main()
{
	rep(i,0,N-1) v[i]=-1e9;
	int n;
	cin>>n;
	rep(i,1,n) { cin>>b[i].a; b[i].b=i;}
	sort(b+1,b+n+1,cmp);
	add(n,0);
	int ans2=0;
	rep(i,1,n)
	{
		int ans=q(b[i].a-b[i].b+n);
		ans2=max(ans2,ans+1);
		add(b[i].a-b[i].b+n,ans+1);
	}
	cout<<ans2<<endl;
	return 0;
}

/*%4=0
0110
1001 */ 
//0110 1001 1001