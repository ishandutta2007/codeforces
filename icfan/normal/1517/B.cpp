#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100;
int b[Maxn+5][Maxn+5];
std::pair<int,std::pair<int,int> > a[Maxn*Maxn+5];
int len;
int n,m;
bool vis[Maxn+5][Maxn+5];
int p[Maxn+5];
int ans[Maxn+5][Maxn+5];
void solve(){
	len=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
		}
		std::sort(b[i]+1,b[i]+1+m);
		for(int j=1;j<=m;j++){
			vis[i][j]=0;
			a[++len]=std::make_pair(b[i][j],std::make_pair(i,j));
			ans[i][j]=0;
		}
		p[i]=0;
	}
	std::sort(a+1,a+1+len);
	for(int i=1;i<=m;i++){
		int x=a[i].second.first,y=a[i].second.second;
		vis[x][y]=1;
		p[x]++;
		ans[x][i]=a[i].first;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ans[j][i]>0){
				continue;
			}
			ans[j][i]=b[j][++p[j]];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}