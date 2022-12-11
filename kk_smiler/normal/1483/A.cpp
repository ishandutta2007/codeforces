#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,ans[100010],cnt[100010],l[100010];
vector<int>a[100010];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&l[i]),a[i].resize(l[i]+1);
		for(int j=1;j<=l[i];j++) scanf("%d",&a[i][j]);
		if(l[i]==1) ans[i]=a[i][1],cnt[a[i][1]]++;
	}
	for(int i=1;i<=m;i++){
		if(l[i]!=1){
			ans[i]=0;
			for(int j=1;j<=l[i];j++) if(cnt[a[i][j]]<(m+1)/2){
				cnt[a[i][j]]++;
				ans[i]=a[i][j];
				break;
			}
			if(!ans[i]) return puts("NO"),void();
		}
	}
	for(int i=1;i<=n;i++) if(cnt[i]>(m+1)/2) return puts("NO"),void();
	puts("YES");
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);puts("");;
}
int main(){
	if(1) scanf("%d",&T);
	else T=1;
	while(T--) solve(); 
}