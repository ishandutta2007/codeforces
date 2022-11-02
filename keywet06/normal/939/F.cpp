#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define rg register
using namespace std;
typedef long long ll;
const int maxn=100010,INF=0x3f3f3f3f;
template <typename Tp> inline int getmin(Tp &x,Tp y){return y<x?x=y,1:0;}
template <typename Tp> inline int getmax(Tp &x,Tp y){return y>x?x=y,1:0;}
template <typename Tp> inline void read(Tp &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') f=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
struct data{
	int l,r;
	bool operator < (const data &t)const{return l<t.l;}
}a[maxn];
int n,k,len,f[2][maxn<<1];
deque<int> q;
void input()
{
	read(n);read(k);
	for(rg int i=1;i<=k;i++) read(a[i].l),read(a[i].r);
	sort(a+1,a+k+1);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int pre=0,cur=1;
	input();
	for(rg int i=1;i<=n+n;i++) f[cur][i]=INF;
	for(rg int i=1;i<=k;i++)
	{
		pre^=1;cur^=1;len=a[i].r-a[i].l+1;
		while(!q.empty()) q.pop_front();
		memmove(f[cur],f[pre],sizeof(f[cur]));
		for(rg int j=a[i].r;~j;j--)
		{
			while(!q.empty()&&f[pre][q.back()]>=f[pre][a[i].r-j]) q.pop_back();
			q.push_back(a[i].r-j);
			while(!q.empty()&&q.front()<a[i].l-j) q.pop_front();
			if(!q.empty()) getmin(f[cur][j],f[pre][q.front()]+1);
		}
		while(!q.empty()) q.pop_front();
		q.push_back(0);
		for(rg int j=0;j<=n&&j<=a[i].r;j++)
		{
			while(!q.empty()&&f[pre][q.back()]>=f[pre][j]) q.pop_back();
			q.push_back(j);
			while(!q.empty()&&q.front()<=j-len) q.pop_front();
			if(!q.empty()) getmin(f[cur][j],f[pre][q.front()]+2);
		}
	}
	if(f[cur][n]>=INF) puts("Hungry");
	else printf("Full\n%d\n",f[cur][n]);
	return 0;
}