#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

string s;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); cin>>s;
		string ans=s; int f=1;
		for(int i=1;i<=n;i++)
		{
			string tmp=s;
			for(int j=0;j<=n-1-i;j++) tmp[j]=s[j+i];
			if((n-i)%2==0) for(int j=n-i,k=0;j<n;j++,k++) tmp[j]=s[k];
			else for(int j=n-i,k=i-1;j<n;j++,k--) tmp[j]=s[k];
			if(tmp<ans) ans=tmp,f=i+1;
			//cout<<tmp<<endl;
		}
		cout<<ans<<endl<<f<<endl;
	}
	return 0;
}