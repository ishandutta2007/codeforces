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

char s1[maxn],s2[maxn];
int cnt1[30],cnt2[30];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=26;i++) cnt1[i]=0,cnt2[i]=0;
		scanf("%s",s1+1); scanf("%s",s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2) {puts("NO"); continue;}
		for(int i=1;i<=len1;i++) cnt1[s1[i]-'a'+1]++,cnt2[s2[i]-'a'+1]++;
		int fl=0;
		for(int i=1;i<=26;i++)
		{
			if(cnt1[i]!=cnt2[i])
			{
				fl=1;
				break;
			}
		}
		if(fl==1) {puts("NO"); continue;}
		fl=0;
		for(int i=1;i<=26;i++)
		{
			if(cnt1[i]>=2)
			{
				fl=1;
				break;
			}
		}
		if(fl==1) {puts("YES"); continue;}
		int cnt3=0,cnt4=0;
		for(int i=1;i<=len1;i++) for(int j=i+1;j<=len1;j++) if(s1[i]>s1[j]) cnt3++;
		for(int i=1;i<=len1;i++) for(int j=i+1;j<=len1;j++) if(s2[i]>s2[j]) cnt4++;
		if((cnt3+cnt4)%2==1) puts("NO");
		else puts("YES");
	}
	return 0;
}