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

char s[maxn],t[maxn];
int vec[30][maxn],cnt[30];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); scanf("%s",t+1); 
		int lens=strlen(s+1),lent=strlen(t+1),f=0,ans=0;
		for(int i=1;i<=lens;i++) vec[s[i]-'a'][++cnt[s[i]-'a']]=i;
		int nw=1;
		
		for(int i=1;i<=lent;i++)
		{
			int x=t[i]-'a';
			if(cnt[x]==0) {f=1; break;}
			int p=lower_bound(vec[x]+1,vec[x]+cnt[x]+1,nw)-vec[x];
			if(p==cnt[x]+1)
			{
				ans++,nw=1;
				p=lower_bound(vec[x]+1,vec[x]+cnt[x]+1,nw)-vec[x];	
			}
			nw=vec[x][p]+1;
			if(nw==lens+1) ans++,nw=1;
			//cout<<nw<<endl;
		}
		
		if(nw==1) ans--;
		if(f==1) puts("-1");
		else printf("%d\n",ans+1);
		
		for(int i=0;i<=26;i++) for(int j=1;j<=cnt[i];j++) vec[i][j]=0;
		for(int i=0;i<=26;i++) cnt[i]=0;
	}
	return 0;
}