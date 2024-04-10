#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,sb,res,a[200500],dp[25][200500],nxt[200500],nx[200500][25],l;
unordered_map<int,vector<int> > mp;

int used[5050];
vector<int> pr;

inline int min(int a,int b){return (a<b)?a:b;}
priority_queue<int, vector<int>, greater<int> > q,q2;

int main(){
	for(i=2;i<=4000;i++){
		if(!used[i]){
			pr.push_back(i);
			for(j=i;j<=4000;j+=i){
				used[j]=1;
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		mp.clear();
		while(!q.empty()){
			q.pop();
		}
		for(i=0;i<=k;i++){
			dp[i][n+1]=dp[i][n+2]=0;
			for(j=0;j<=n;j++){
				dp[i][j]=11451419;
				nx[j][i]=n+1;
				nxt[j]=n+1;
			}
		}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(auto j:pr){
				if(j*j>a[i]){break;}
				while(!(a[i]%(j*j))){
					a[i]/=(j*j);
				}
			}
			sb=mp[a[i]].size();
			if(sb){
				nxt[mp[a[i]][sb-1]]=i;
			}
			mp[a[i]].push_back(i);
		}
		for(i=n;i>=1;i--){
			q.push(nxt[i]);
			for(j=0;j<=k;j++){
				if(q.empty()){break;}
				sb=q.top();q.pop();q2.push(sb);
				nx[i][j]=sb;
			}
			while(!q2.empty()){
				sb=q2.top();q2.pop();
				q.push(sb);
			}
		}
		for(i=n;i>=1;i--){
			for(j=0;j<=k;j++){
				for(l=0;l<=j;l++){
					dp[j][i]=min(dp[j][i],dp[j-l][nx[i][l]]+1);
				}
			}
		}
		printf("%d\n",dp[k][1]);
	}
}