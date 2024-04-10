#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,a[maxn],cnt,num,mx,tmp,b[maxn];
char s[maxn];
vector <int> vec,v;
vector <vector<int> > ans;

int main()
{
	n=read(); k=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++) if(s[i]=='R') a[++cnt]=i;
	num=n-cnt+1; mx=0;
	
	for(int i=num;i<=n;i++) tmp+=(i-a[i-num+1]),mx=max(mx,i-a[i-num+1]);
	int res=tmp,nw=n;
	
	for(int i=cnt;i>=1;i--)
	{
		if(a[i]==nw)
		{
			cnt--; nw--; n--;
		}
		else break;
	}
	
	//cout<<cnt<<" "<<nw<<endl;
	//cout<<a[1]<<endl;
	for(int i=cnt+1;i<=n;i++) a[i]=inf;
	if(k>tmp) {puts("-1"); return 0;}
	
	while(k)
	{
		vec.clear(); v.clear();
		for(int i=cnt;i>=1;i--)
		{
			if(a[i]==a[i+1]-1) continue;
			else
			{
				if(res==k-1) break;
				res--; vec.pb(a[i]); v.pb(i);
			}
		}
		for(int i=0;i<v.size();i++) a[v[i]]++;
		k--;
		if(a[cnt]==nw) nw--,cnt--;
		ans.pb(vec);
	}
	
	
	if(cnt!=0) puts("-1");
	else
	{
		for(int i=0;i<ans.size();i++)
		{
			printf("%d ",ans[i].size());
			for(int j=0;j<ans[i].size();j++)
				printf("%d ",ans[i][j]);
			puts("");
		}
	}
	return 0;
}