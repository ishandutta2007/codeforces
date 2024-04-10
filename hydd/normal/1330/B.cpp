#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,a[210000],tot,mx,ans;
bool vis[210000],ok[210000],ok2[210000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			vis[i]=false;
			ok[i]=false; ok2[i]=false;
		}
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		tot=0; mx=0;
		for (int i=1;i<=n;i++){
			if (vis[a[i]]) break;
			vis[a[i]]=true;
			tot++; mx=max(mx,a[i]);
			if (tot==mx) ok[i]=true;
		}
		for (int i=1;i<=n;i++) vis[i]=false;
		tot=0; mx=0;
		for (int i=n;i>=1;i--){
			if (vis[a[i]]) break;
			vis[a[i]]=true;
			tot++; mx=max(mx,a[i]);
			if (tot==mx) ok2[i]=true;
		}
		ans=0;
		for (int i=1;i<n;i++)
			if (ok[i]&&ok2[i+1]) ans++;
		printf("%d\n",ans);
		for (int i=1;i<n;i++)
			if (ok[i]&&ok2[i+1]) 
				printf("%d %d\n",i,n-i);
	}
	return 0;
}