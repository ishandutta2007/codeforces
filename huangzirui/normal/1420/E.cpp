#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=85;
int i,j,k,n,m,a[maxn],s[maxn],d[maxn],dp[maxn][maxn][maxn*maxn],ans[maxn*maxn];
inline int f(int x){return x<0?84*84:x;}
inline int get(int x){return x*(x-1)/2;}
int main() {
	cin>>n;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==1)d[++m]=i;
		else s[m]++;
	}memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=0;k<=n*(n-1)/2;k++){
				for(int h=0;h<i;h++){
					dp[i][j][k]=min(dp[i][j][k],dp[h][j-1][f(k-abs(i-d[j]))]+get(i-h-1));
				}if(j==m)ans[k]=max(ans[k],(n-m)*(n-m-1)/2-dp[i][j][k]-get(n-i));
				//if(dp[i][j][k]<=1e9)cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<' '<<d[j]<<endl;
			}
		}
	}for(i=0;i<=n*(n-1)/2;i++)ans[i]=max(ans[i],ans[max(0,i-1)]),printf("%d ",ans[i]);puts("");
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}