#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n,k;
int a[Maxn+5];
int lis[Maxn+5];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	int lst=-1,sum=0;
	int ans=0;
	int len=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		j--;
		ans++;
		if(a[i]==lst+1){
			ans--;
			lst=a[i];
			continue;
		}
		if(sum==k){
			lis[++len]=j-i+1;
			continue;
		}
		if(sum+(a[i]-lst-1)>k){
			lis[++len]=j-i+1;
			sum=k;
			continue;
		}
		sum+=a[i]-lst-1;
		lst=a[i];
		ans--;
	}
	std::sort(lis+1,lis+1+len);
	for(int i=1;i<=len;i++){
		if(sum-lis[i]>=0){
			sum-=lis[i];
			ans--;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}