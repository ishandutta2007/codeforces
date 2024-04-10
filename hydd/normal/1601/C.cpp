#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[1100000],b[1100000],p[1100000];
int cnt,c[2100000],num[2100000],tree[2100000];
void add(int x,int y){
	for (;x;x-=x&-x) tree[x]+=y;
}
int query(int x){
	int res=0;
	for (;x<=cnt;x+=x&-x) res+=tree[x];
	return res;
}
void solve(int l,int r,int x,int y){
	if (l>r) return;
	int mid=(l+r)>>1,res=n+1,sum=0,pos=0;
	for (int i=x;i<=y;i++){
		if (res>sum) res=sum,pos=i;
		sum+=(a[i]>b[mid])-(a[i]<b[mid]);
	}
	p[mid]=pos;
	solve(l,mid-1,x,pos); solve(mid+1,r,pos,y);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		sort(b+1,b+m+1); solve(1,m,1,n+1);
		
		cnt=0;
		for (int i=1,j=1;i<=n+1;i++){
			while (j<=m&&p[j]<=i) c[++cnt]=b[j++];
			if (i<=n) c[++cnt]=a[i];
		}
		for (int i=1;i<=cnt;i++) num[i]=c[i];
		sort(num+1,num+cnt+1);
		
		ll ans=0;
		for (int i=1;i<=cnt;i++){
			int x=lower_bound(num+1,num+cnt+1,c[i])-num;
			ans+=query(x+1); add(x,1);
		}
		for (int i=1;i<=cnt;i++) tree[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}