#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

bool is[maxn];
int pri[maxn],cnt,f[maxn],P[maxn];

inline void pre()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!is[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			int k=pri[j]*i; if(k>maxn-5) break; is[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}


int main()
{
	pre();
	rep(i,1,maxn-5) P[i]=P[i-1]+(!is[i]);
	//rep(i,1,20) cout<<i<<" "<<is[i]<<" "<<P[i]<<endl;
	int T=read();
	while(T--)
	{
		int x=read();
		printf("%d\n",P[x]-P[(int)sqrt(x)]+1);
	}
	return 0;
}