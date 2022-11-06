#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int a[N],cnt[N],tr[N],n,T,fi[N],la[N],f[N];
#define low(x) (x&(-x))
void add(int x,int v){
	for (;x<=n;x+=low(x))tr[x]=max(tr[x],v);
}
int query(int x){
	int ans=0;
	for (;x;x-=low(x))ans=max(ans,tr[x]);
	return ans;
}
int main(){
	for (cin>>T;T--;){
		scanf("%d",&n);
		int c1=0,mn=n+1;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (!cnt[a[i]])fi[a[i]]=i,c1++;
			cnt[a[i]]++;
			la[a[i]]=i;
			mn=min(mn,a[i]);
		}
		int ans=1,now=1,las=mn;
		for (int i=mn+1;i<=n;i++){
			if (!cnt[i])continue;
			if (la[las]<fi[i])now++;
			else now=1;
			las=i;
			ans=max(ans,now);
		}
		for (int i=1;i<=n;i++)cnt[i]=tr[i]=fi[i]=la[i]=f[i]=0;
		printf("%d\n",c1-ans);
	}
}