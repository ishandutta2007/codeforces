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
#define maxn 200005
#define re register
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

char s[maxn],s2[maxn];
int len,len2;

inline bool jud()
{
	if(len<len2)
	{
		for(int i=1;i<=len;i++)
		{
			if(s[i]==s2[i]) continue;
			else if(s[i]<s2[i]) return true;
			else return false;
		}
		return true;
	}
	else
	{
		for(int i=1;i<=len;i++)
		{
			if(s[i]==s2[i]) continue;
			else if(s[i]<s2[i]) return true;
			else return false;
		}
		return false;
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); scanf("%s",s2+1);
		len=strlen(s+1); len2=strlen(s2+1);
		if(jud()) {cout<<(s+1)<<endl; continue;}
		int f=0,f2=0,tmp=0;
		for(tmp=0;tmp<=25;tmp++)
		{
			f=0; f2=0;
			for(int i=len;i>=1;i--) if((s[i]-'A')==tmp) {f=i; break;}
			for(int i=1;i<=f;i++) if((s[i]-'A')>tmp) {f2=i; break;}
			if(f2) break;
		}
		
		//cout<<tmp<<" "<<f<<" "<<f2<<endl;
		if(f2==0) {puts("---"); continue;}
		swap(s[f],s[f2]);
		if(jud()) {cout<<(s+1)<<endl; continue;}
		else {puts("---"); continue;}
	}
	return 0;
}