// Hydro submission #62c6d4b2c3a9fda5622b1d87@1657197747619
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
const double eps=1e-9;
int n,m;
ll dp[maxn][30][4];
int len[maxn];
pii gate[maxn][2];
int getlen(pii x,pii y){
	int i=max(x.first,x.second);
	if(x.first==i&&y.first==i)return abs(x.second-y.second);
	else if(x.second==i&&y.second==i)return abs(x.first-y.first);
	else return 4*i-(x.first+y.first+x.second+y.second);
}
int dis(int dir,pii x,pii y){
	int i=max(x.first,x.second);
	int ans0,ans1;
	if(!dir){
		x.first++;
		ans0=getlen(x,y)+1;
		x=gate[i][1];
		x.second++;
		ans1=getlen(x,y)+1+len[i];
	}
	else {
		x.second++;
		ans0=getlen(x,y)+1;
		x=gate[i][0];
		x.first++;
		ans1=getlen(x,y)+1+len[i];
	}
	return min(ans0,ans1);
}

int main(){
	int T=1;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			gate[i][0]={x1,y1};
			gate[i][1]={x2,y2};
			len[i]=i*2-y1-x2;
		}
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<n-1;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					dp[i][0][j*2+k]=dis(j,gate[i][j],gate[i+1][k]);
				}
			}
		}
		for(int i=1;i<=20;i++){
			for(int j=1;j<n-1;j++){
				int nxt=j+(1<<(i-1));
				if(nxt>=n-1)continue;
				for(int k=0;k<4;k++){
					for(int t=0;t<4;t++){
						int cur=k/2*2+t%2;
						ll temp=dp[j][i-1][k]+dp[nxt][i-1][t];
						if(k%2!=t/2)temp+=len[nxt];
						dp[j][i][cur]=min(dp[j][i][cur],temp);
					}
				}
			}
		}
		scanf("%d",&m);
		while(m--){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			pii st={x1,y1},ed={x2,y2};
			int idx=max(x1,y1),idy=max(x2,y2);
			if(idx>idy)swap(st,ed),swap(idx,idy);
			if(idx==idy)printf("%d\n",getlen(st,ed));
			else {
				ll len[2]={getlen(gate[idx][0],st),getlen(gate[idx][1],st)};
				for(int i=20;i>=0;i--){
					int nxt=(1<<i)+idx;
					if(nxt>idy-1)continue;
					ll temp[2]={inf,inf};
					for(int j=0;j<4;j++){
						temp[j%2]=min(temp[j%2],len[j/2]+dp[idx][i][j]);
					}
					idx=nxt;
					for(int j=0;j<2;j++)
						len[j]=temp[j];
				}
				len[0]+=dis(0,gate[idx][0],ed);
				len[1]+=dis(1,gate[idx][1],ed);
				printf("%lld\n",min(len[0],len[1]));
				
			}
		}
	}
	return 0;
}