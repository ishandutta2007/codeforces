#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> a(n,vector<int>(m));
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&a[i][j]);
		vector<pair<int,int>> q;
		for(int j=0;j<m;++j){
			int mx=0;
			for(int i=0;i<n;++i)mx=max(mx,a[i][j]);
			q.push_back({mx,j});
		}
		sort(q.begin(),q.end());
		vector<int> dp(1<<n);
		for(int h=m-1;h>=0 && h>=m-n;--h){
			int j=q[h].second;
			vector<int> dp1=dp;
			for(int s=0;s<(1<<n);++s){
				int mx=0;
				for(int i=0;i<n;++i){
					int sum=0;
					for(int k=0;k<n;++k)
					if(s&(1<<k))sum+=a[(i+k)%n][j];
					mx=max(mx,sum);
				}
				int ns=(1<<n)-1-s;
				for(int t=ns;;(--t)&=ns){
					dp1[s+t]=max(dp1[s+t],dp[t]+mx);		
					if(!t)break;
				}
			}
			dp=dp1;
		}
		cout<<dp[(1<<n)-1]<<endl;
	}
}