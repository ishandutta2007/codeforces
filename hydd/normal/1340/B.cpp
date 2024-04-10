#include<cstdio>
using namespace std;
const int b[]={119, 18,93,91, 58,107,111, 82,127,123};
const int c[]={6, 2,5,5, 4,5,6, 3,7,6};
int n,k,ans[2100],a[2100],tot[2100];
bool f[2100][2100];
char s[11];
void solve(){
	for (int i=1;i<=n;i++){
		bool flag=false;
		for (int d=9;d>=0;d--)
			if ((a[i]&b[d])==a[i]&&(c[d]-tot[i])<=k&&f[i+1][k-(c[d]-tot[i])]){
				ans[i]=d; flag=true; k-=(c[d]-tot[i]);
				break;
			}
		if (!flag){
			puts("-1");
			return;
		}
	}
	int i=1;
	while (i<n&&!ans[i]) i++;
	while (i<=n) printf("%d",ans[i++]);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1); a[i]=0;
		for (int j=1;j<=7;j++){
			a[i]=(a[i]<<1)|(s[j]=='1');
			tot[i]=tot[i]+(s[j]=='1');
		}
	}
	for (int j=0;j<=k;j++) f[n+1][j]=false;
	f[n+1][0]=true;
	for (int i=n;i>=1;i--){
		for (int j=0;j<=k;j++) f[i][j]=false;
		for (int d=0;d<=9;d++)
			if ((a[i]&b[d])==a[i])
				for (int j=(c[d]-tot[i]);j<=k;j++)
					f[i][j]=f[i][j]||f[i+1][j-(c[d]-tot[i])];
	}
	solve();
	return 0;
}