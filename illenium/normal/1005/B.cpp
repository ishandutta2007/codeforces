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
#define ull unsigned long long
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

ull pre[maxn],h1[maxn],h2[maxn];
char ch1[maxn],ch2[maxn];
int l1,l2,ans;

inline ull gethash(int op,int l,int r)
{
	if(op==1)  return h1[r]-h1[l-1]*pre[r-l+1];
	else return h2[r]-h2[l-1]*pre[r-l+1];
}

inline bool jud(int x)
{
	if(gethash(1,l1-x+1,l1)==gethash(2,l2-x+1,l2)) return true;
	return false;
}

int main()
{
	scanf("%s",ch1+1); scanf("%s",ch2+1);
	pre[0]=1; l1=strlen(ch1+1); l2=strlen(ch2+1);
	for(int i=1;i<=maxn-5;i++) pre[i]=pre[i-1]*233;
	for(int i=1;i<=l1;i++) h1[i]=h1[i-1]*233+ch1[i];
	for(int i=1;i<=l2;i++) h2[i]=h2[i-1]*233+ch2[i];
	int l=0,r=min(l1,l2);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<l1+l2-2*ans;
	return 0;
}