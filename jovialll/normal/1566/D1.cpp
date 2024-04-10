#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define pb push_back
#define mod 998244353
#define pn cout<<"No\n"
#define py cout<<"Yes\n"

vector<int>son[N];
struct node{
	int v,pos,ee;
}a[N];
inline bool cmp(node aa,node bb){return aa.v==bb.v?aa.pos<bb.pos:aa.v<bb.v;}
int n,m,T,i,j,las,ans[N],dp[305][305],ANS,x,y;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n*m;++i)cin>>a[i].v,a[i].pos=i;
		sort(a+1,a+n*m+1,cmp);
		a[n*m+1].v=-1;
		for(i=1;i<=n*m;++i)ans[i]=-1;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)dp[i][j]=0;
		for(i=las=1;i<=n*m;++i){
			if(a[i].v!=a[i+1].v){
				if((las-1)/m==(i-1)/m){
					for(j=las;j<=i;++j){
						ans[a[j].pos]=las+i-j;
					}
				}
				else{
					T=(las-1)/m*m+m-1;
					for(j=las;j<=T;++j){
						ans[a[j].pos]=las+T-j;
					}
					las=(i-1)/m*m+1;
					for(j=las;j<=i;++j){
						ans[a[j].pos]=las+i-j;
					}
				}
				las=i+1;
			}
		}
//		for(i=1;i<=m;++i)cout<<ans[i]<<" ";
		ANS=0;
		for(i=1;i<=n*m;++i){
			if(ans[i]!=-1){
				x=(ans[i]-1)/m+1;
				y=(ans[i]-1)%m+1;
				for(j=1;j<y;++j)ANS+=dp[x][j];
				dp[x][y]=1;
			}
		}
		cout<<ANS<<"\n";
	}
}