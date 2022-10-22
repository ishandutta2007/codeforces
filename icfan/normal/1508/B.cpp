#include <cstdio>
typedef long long ll;
const int Maxn=100000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
ll k;
ll f[Maxn+5],g[Maxn+5];
ll find_val(int l,int r){
	if(l>r){
		return 0;
	}
	if(g[r]==Inf){
		return Inf;
	}
	return g[r]-g[l-1];
}
void solve(){
	scanf("%d%lld",&n,&k);
	f[1]=1;
	g[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=g[i-1]+1;
		g[i]=g[i-1]+f[i];
		if(f[i]>=k){
			for(int j=i+1;j<=n;j++){
				f[j]=g[j]=Inf;
			}
			break;
		}
	}
	if(f[n]<k){
		puts("-1");
		return;
	}
	for(int i=1;i<=n;){
		int left=1,right=n-i+1;
		int len=n-i+1;
		while(left<right){
			int mid=(left+right)>>1;
			if(find_val(len-mid,len-1)<k){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
		k-=find_val(len-left+1,len-1);
		for(int j=left;j>0;j--){
			printf("%d ",i+j-1);
		}
		i+=left;
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}