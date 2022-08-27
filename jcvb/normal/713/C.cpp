#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long ll;
int a[1000005],n;
struct node{int l,r,d;}t[1000005];
int merge(int x,int y){
	if(x==0)return y;
	if(y==0)return x;
	if(a[x]<a[y])swap(x,y);
	t[x].r=merge(t[x].r,y);
	if(t[t[x].l].d<t[t[x].r].d)swap(t[x].l,t[x].r);
	t[x].d=t[t[x].r].d+1;
	return x;
}
int qu[1000005],top=0;
int sz[1000005]={0};
int main()
{
	scanf("%d",&n);
	memset(t,0,sizeof(t));
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i;
	for (int i=1;i<=n;i++){
		qu[++top]=i;sz[top]=1;
		while(top>1 && a[qu[top]]<=a[qu[top-1]]){
			int tmp=(sz[top]+1>>1)+(sz[top-1]+1>>1)-(sz[top]+sz[top-1]+1>>1);
			sz[top-1]+=sz[top];
			qu[top-1]=merge(qu[top-1],qu[top]);
			top--;
			while(tmp--)qu[top]=merge(t[qu[top]].l,t[qu[top]].r);
		}
	}
	ll ans=0;
	for (int i=1;i<=top;i++){
		int x=a[qu[i]];
		sz[i]+=sz[i-1];
		for (int j=sz[i-1]+1;j<=sz[i];j++)ans+=abs(a[j]-x);
	}
	cout<<ans<<endl;
	return 0;
}