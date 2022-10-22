#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+9;
int n,k,num=0;
ll ans=0;
map<int,int>mp[M];
int a[M],b[1000009],c[M],pos[M][25];
int Min(int l,int r){return a[l]>a[r]?l:r;}
int ask(int l,int r){
	int p=log2(r-l+1);
	return Min(pos[l][p],pos[r-(1<<p)+1][p]);
}
void solve(int l,int r){
	if(l==r)b[c[l]]--,ans++;
	if(l>=r)return;
	int mid=ask(l,r),x=mid-l,y=r-mid;
	if(x<y){
		for(int i=l;i<mid;++i)b[c[i]]--;
		for(int i=l-1;i<mid;++i)ans+=b[(c[i]+a[mid])%k];
		b[c[mid]]--;
		solve(mid+1,r);
		for(int i=l;i<mid;++i)b[c[i]]++;
		solve(l,mid-1);
	}
	else {
		for(int i=mid;i<=r;++i)b[c[i]]--;
		b[c[l-1]]++;
		for(int i=mid;i<=r;++i)ans+=b[((c[i]-a[mid])%k+k)%k];
		b[c[l-1]]--;
		solve(l,mid-1);
		for(int i=mid+1;i<=r;++i)b[c[i]]++;
		solve(mid+1,r);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pos[i][0]=i;
	}
	for(int j=1;j<=23;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			pos[i][j]=Min(pos[i][j-1],pos[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=n;++i)c[i]=(a[i]+c[i-1])%k,b[c[i]]++;
	solve(1,n);
	printf("%lld\n",ans-n);
	return 0;
}