#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 800005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,cnt,tot,l[maxn],r[maxn],a[maxn<<1],lx[maxn],rx[maxn],p[maxn],t[maxn],p2[maxn],h[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); cnt=0; tot=0;
		for(int i=1;i<=n;i++)
		{
			l[i]=read(),r[i]=read();
			a[++cnt]=l[i],a[++cnt]=r[i];
		}
		sort(a+1,a+cnt+1);
		tot=unique(a+1,a+cnt+1)-a-1;
		
		//for(int i=1;i<=tot;i++) cout<<a[i]<<" "; cout<<endl;
		
		for(int i=1;i<=n;i++)
		{
			lx[i]=lower_bound(a+1,a+tot+1,l[i])-a;
			rx[i]=lower_bound(a+1,a+tot+1,r[i])-a; lx[i]<<=1; rx[i]<<=1;
			//cout<<lx[i]<<" "<<rx[i]<<endl;
		}
		
		int tmp=0;
		for(int i=1;i<=tot*2;i++) p2[i]=0,h[i]=0,p[i]=0;
		
		for(int i=1;i<=tot*2;i++) t[i]=0;
		for(int i=1;i<=n;i++) t[lx[i]]++,t[rx[i]+1]--;
		for(int i=1;i<=tot*2;i++) tmp+=t[i],p[i]=tmp;
		
		for(int i=1;i<=tot*2;i++) if(p[i]!=p[i-1]&&p[i]==1) p2[i]=1;
		for(int i=1;i<=tot*2;i++) h[i]=h[i-1]+p2[i];
		
//		for(int i=1;i<=tot*2;i++) cout<<i<<" "; cout<<endl;
//		for(int i=1;i<=tot*2;i++) cout<<p[i]<<" "; cout<<endl;
//		for(int i=1;i<=tot*2;i++) cout<<p2[i]<<" "; cout<<endl;
//		for(int i=1;i<=tot*2;i++) cout<<h[i]<<" "; cout<<endl;
		
		int ans=-inf,ans1=0;
		for(int i=1;i<=tot*2+1;i++) if(p[i]!=0&&p[i-1]==0) ans1++;
		for(int i=1;i<=n;i++)
		{
			int q=h[rx[i]]-h[lx[i]-1]; q-=(p[rx[i]]==1),q-=(p[lx[i]]==1);
			ans=max(ans,q);
		}
		cout<<ans1+ans<<endl;
	}
	return 0;
}