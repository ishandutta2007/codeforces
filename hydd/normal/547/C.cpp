#include<bits/stdc++.h>
using namespace std;
const int m=5e5;
typedef long long ll;
int n,q,a[210000],b[210000],dp[510000];
vector<int> fac[510000]; ll ans;
ll calc(int x){ return 1ll*x*(x-1)/2;}
void work(int x,int c){
	int tot=fac[x].size();
	int lim=(1<<tot)-1;
	for (int s=0;s<=lim;s++){
		int mul=1,op=1;
		for (int i=0;i<tot;i++)
			if ((s>>i)&1){
				mul*=fac[x][i];
				op=-op;
			}
		ans-=op*calc(dp[mul]); dp[mul]+=c; ans+=op*calc(dp[mul]);
	}
}
int main(){
	for (int i=2;i<=m;i++)
		if (fac[i].empty())
			for (int j=i;j<=m;j+=i)
				fac[j].push_back(i);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=-1;
	}
	int x;
	while (q--){
		scanf("%d",&x); b[x]=-b[x];
		work(a[x],b[x]);
		printf("%lld\n",ans);
	}
	return 0;
}