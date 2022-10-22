#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

int a[maxn],tmp[maxn],ans1,ans2,tp1[maxn],tp2[maxn],cnt1,cnt2;
bool vis[maxn],p[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	
	for(int i=1;i<=n;i++)
	{
		if(p[a[i]]==1) continue;
		else if(p[a[i]-1]==1) continue;
		else if(p[a[i]+1]==1) continue;
		else ans1++,p[a[i]+1]=1;
	}
	
	
	for(int i=1;i<=n;i++) tmp[i]=a[i]; tmp[0]=-1;
	
	for(int i=1;i<=n;i++)
	{
		if(tmp[i]>tmp[i-1]+1) tmp[i]--;
		else if(tmp[i]==tmp[i-1]+1) ;
		else tmp[i]++;
	}
	for(int i=1;i<=n;i++) tp1[i]=tmp[i];
	ans2=unique(tp1+1,tp1+n+1)-tp1-1;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}