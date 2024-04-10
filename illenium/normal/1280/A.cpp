#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 1000005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll x,cnt,f,f2;
ll len;
char s2[maxn];
const ll modc=1e9+7;

int main()
{
	ll T=read();
	while(T--)
	{
		x=read(); scanf("%s",s2);
		len=strlen(s2); f2=0;
		ll nlen=len;
		for(int i=0;i<x;i++)
		{
			if(i>len) {cout<<strlen(s2)<<endl; f2=1; break;}
			if(s2[i]=='1') continue;
			if(f2==0)
			{
				char tmp[maxn]; int cnt=0;
				for(int j=i+1;j<len;j++) tmp[++cnt]=s2[j];
				for(int j=1;j<=s2[i]-'0'-1&&len<=x;j++) for(int k=1;k<=cnt&&len<=x;k++) s2[len++]=tmp[k];
				if(len>x) f2=1;
				ll tmp1=(nlen-i-1+modc)%modc;
				nlen=(nlen+(tmp1*(s2[i]-'0'-1)))%modc;
			}
			else
			{
				ll tmp1=(nlen-i-1+modc)%modc;
				nlen=(nlen+(tmp1*(s2[i]-'0'-1)))%modc;
			}
		}
		cout<<nlen<<endl;
	}
	return 0;
}