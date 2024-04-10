#include <cstdio>
#include <algorithm>
const int Maxn=5000;
int lcp[Maxn+5][Maxn+5],f[Maxn+5];
char s[Maxn+5];
int n;
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=n;i>0;i--){
		for(int j=i+1;j<=n;j++){
			if(s[i]<s[j]){
				lcp[i][j]=j-1;
			}
			else if(s[i]==s[j]&&j+1<=n){
				lcp[i][j]=lcp[i+1][j+1];
			}
			else{
				lcp[i][j]=0;
			}
		}
	}
	int ans;
	f[1]=ans=n;
	for(int i=2;i<=n;i++){
		f[i]=n-i+1;
		for(int j=i-1;j>0;j--){
			if(lcp[j][i]){
				f[i]=std::max(f[i],f[j]+n-lcp[j][i]);
			}
		}
		ans=std::max(ans,f[i]);
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