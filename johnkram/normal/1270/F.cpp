#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define P 999983
ll ans;
char c[MAXN];
int n,i,j,k,l,r,S=500,M=500,ne[MAXN],s[MAXN];
struct node
{
	int h[P],ne[MAXN],p[MAXN],w[MAXN],N;
	void ins(int x)
	{
		int i=(x%P+P)%P,j;
		for(j=h[i];j;j=ne[j])if(p[j]==x)
		{
			w[j]++;
			return;
		}
		p[++N]=x;
		ne[N]=h[i];
		w[N]=1;
		h[i]=N;
	}
	int ask(int x)
	{
		int i=(x%P+P)%P,j;
		for(j=h[i];j;j=ne[j])if(p[j]==x)return w[j];
		return 0;
	}
	void del(int x)
	{
		h[(x%P+P)%P]=0;
	}
}t;
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	ne[n]=ne[n+1]=n+1;
	for(i=n;i;i--)if(c[i]=='1')ne[i-1]=i;
	else ne[i-1]=ne[i];
	for(i=1;i<=n;i++)s[i]=s[i-1]+(c[i]^'0');
	for(i=1;i<=S;i++)
	{
		t.ins(0);
		for(j=1;j<=n;j++)
		{
			t.ins(j-s[j]*i);
			ans+=t.ask(j-s[j]*i)-1;
		}
		t.N=0;
		t.del(0);
		for(j=1;j<=n;j++)t.del(j-s[j]*i);
	}
	for(i=0;i<n;i++)for(j=ne[i],k=1;j<=n&&k<=M;j=ne[j],k++)
	{
		l=max(j,S*(s[j]-s[i])+i+1);
		r=ne[j]-1;
		if(l>r)continue;
		ans+=(r-i)/(s[j]-s[i])-(l-1-i)/(s[j]-s[i]);
	}
	cout<<ans<<endl;
	return 0;
}