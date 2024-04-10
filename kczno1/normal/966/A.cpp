#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int a1[N],a2[N];

int main()
{
	int n,m,c1,c2,v;
	cin>>n>>m>>c1>>c2>>v;
	rep(i,1,c1)scanf("%d",a1+i);
	rep(i,1,c2)scanf("%d",a2+i);
	sort(a1+1,a1+c1+1);
	sort(a2+1,a2+c2+1);
	int q;
	cin>>q;
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		swap(x1,y1);swap(x2,y2);
		int d=abs(y1-y2),ans=1e9;
		if(!d)
		{
			printf("%d\n",abs(x1-x2));
			continue;
		}
		int i=lower_bound(a1+1,a1+c1+1,x1)-a1;
		rep(j,0,1)
		{
			if(i>0&&i<=c1)chmin(ans,d+abs(a1[i]-x1)+abs(a1[i]-x2));
			--i;
		}
		i=lower_bound(a2+1,a2+c2+1,x1)-a2;
		rep(j,0,1)
		{
			if(i>0&&i<=c2)chmin(ans,(d+v-1)/v+abs(a2[i]-x1)+abs(a2[i]-x2));
			--i;
		}
		printf("%d\n",ans);
	}
}