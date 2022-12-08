#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e6+5;
int n,m,t[M];
const int N = 310;
int dis[N][N];
char s[N];

int last[N];
int f[N];
int d[M];
int pre[M];
stack<int> stk;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)dis[i][j]=s[j]-'0';
		for(int j=1;j<=n;j++)if(i!=j&&dis[i][j]==0){
			dis[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++){
		dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
	}
	cin >> m;
	for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int to;scanf("%d",&to);d[i]=to;
		f[to]=0x3f3f3f3f;
		// cout << i << "--" << endl;
		for(int from=1;from<=n;from++)if(last[from]){
			// cout << from << "," << dis[from][to] << endl;
			if(dis[from][to]==i-last[from]){
				// cout << from << " " << to << endl;
				if(f[from]+1<f[to]){
					pre[i]=last[from];
					f[to]=f[from]+1;
				}
			}
		}
		last[to]=i;
		if(i==1){
			f[to]=1;
		}
	}
	cout << f[d[m]] << endl;
	int cur=m;
	while(cur){
		stk.push(d[cur]);
		cur=pre[cur];
	}
	while(stk.size()){
		printf("%d ",stk.top());
		stk.pop();
	}
}