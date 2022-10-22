#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,m,cnt,now,a[110000],num[110000];
ll w,f[2][110000];
void solve(int l,int r,int x,int y){
	if (l>r) return;
	int mid=(l+r)>>1,m=min(mid,y),fr=0;
	f[now][mid]=INF;
	for (int i=l;i<=mid;i++){ w+=num[a[i]]; num[a[i]]++;}
	for (int i=x;i<=m;i++){
		num[a[i]]--; w-=num[a[i]];
		if (f[now][mid]>f[now^1][i]+w){
			f[now][mid]=f[now^1][i]+w;
			fr=i;
		}	
	}
	for (int i=x;i<=m;i++){ w+=num[a[i]]; num[a[i]]++;}
	for (int i=l;i<=mid;i++){ num[a[i]]--; w-=num[a[i]];}
	solve(l,mid-1,x,fr);
	for (int i=l;i<=mid;i++){ w+=num[a[i]]; num[a[i]]++;}
	for (int i=x;i<fr;i++){ num[a[i]]--; w-=num[a[i]];}
	solve(mid+1,r,fr,y);		
	for (int i=x;i<fr;i++){ w+=num[a[i]]; num[a[i]]++;}
	for (int i=l;i<=mid;i++){ num[a[i]]--; w-=num[a[i]];}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ll t=0;
	now=0; f[0][0]=0;
	for (int i=1;i<=n;i++){
		t+=num[a[i]];
		num[a[i]]++;
		f[0][i]=t;
	}
	for (int i=1;i<=n;i++) num[a[i]]--;
	for (int i=2;i<=m;i++){
		now^=1; f[now][0]=INF;
		solve(1,n,1,n);
	}
	printf("%lld\n",f[now][n]);
	return 0;
}