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

const int P=1e9+7;

char ch[maxn];
ll pre[maxn],h[26][maxn],A[26],B[26];
int n,m;

inline ll gethash(int chr,int l,int r)
{
	return (h[chr][r]-h[chr][l-1]*pre[r-l+1]%P+P)%P;
}

inline bool check(int x,int y,int len)
{
	for(int i=0;i<26;i++) A[i]=gethash(i,x,x+len-1),B[i]=gethash(i,y,y+len-1);
	sort(A,A+26); sort(B,B+26);
	for(int i=0;i<26;i++) if(A[i]!=B[i]) return false;
	return true;
}

int main()
{
	n=read(); m=read(); scanf("%s",ch+1); pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*233)%P;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) h[j][i]=(h[j][i-1]*233+(ch[i]-'a'==j))%P;
	while(m--)
	{
		int x=read(),y=read(),len=read();
		if(check(x,y,len)) puts("YES");
		else puts("NO");
	}
	return 0;
}