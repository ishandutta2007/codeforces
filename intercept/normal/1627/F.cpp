 #include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,k;
int lx[M],ly[M],rx[M],ry[M];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dp[509];
int val[509][509][4];
ll dis[509*509];
int sz;
int id[509][509];
int t[509*509*2];
void push(int x,int y){
    for(t[x+=sz-1]=y;x;x>>=1)t[x>>1]=dis[t[x]]<dis[t[x^1]]?t[x]:t[x^1];
}
bool in(int x,int y){
	return x>=0&&x<=n/2&&y>=0&&y<=n;
}
ll ans;
void solve(){
	dis[0]=1ll<<60;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(i)dis[id[i][j]]=1ll<<60;
			else dis[id[i][j]]=0,push(id[i][j],id[i][j]);
			for(int o=0;o<4;++o)val[i][j][o]=0;
		}
	}
	for(int i=0;i<=n;++i)dp[i]=0;
	for(int i=1;i<=k;++i){
		if(lx[i]>rx[i])swap(lx[i],rx[i]),swap(ly[i],ry[i]);
		if(lx[i]==n/2&&rx[i]==n/2+1){
			int l=ly[i],r=n-l;
			if(l<=r){
				dp[l-1]++;
				dp[r+1]++;
			}
			else{
				dp[l]++;
				dp[r]++;
			}
		}
		else{
			if(lx[i]==rx[i]){
				if(lx[i]>n/2){
					int x=n-lx[i]+1,ay=n-ly[i]+1,by=n-ry[i]+1;
					if(ay>by)swap(ay,by);
					val[x-1][ay][0]++;
					val[x][ay][2]++;
				}
				else {
					int x=lx[i],ay=ly[i],by=ry[i];
					if(ay>by)swap(ay,by);
					val[x-1][ay][0]++;
					val[x][ay][2]++;
				}
			}
			else{
				if(lx[i]>n/2){
					int ax=n-lx[i]+1,bx=n-rx[i]+1,y=n-ly[i]+1;
					if(ax>bx)swap(ax,bx);
					val[ax][y-1][1]++;
					val[ax][y][3]++;
				}
				else {
					int ax=lx[i],bx=rx[i],y=ly[i];
					if(ax>bx)swap(ax,bx);
					val[ax][y-1][1]++;
					val[ax][y][3]++;
				}
			}
		}
	}
	for(int i=n/2+1;i<=n;++i)dp[i]+=dp[i-1];
	for(int i=n/2-1;i>=0;--i)dp[i]+=dp[i+1];
	while(1){
		int o=t[1];
		push(o,0);
		if(o==0)break;
		int x=(o-1)/(n+1),y=(o-1)%(n+1);
		if(x==n/2){
			ans=min(ans,dis[o]+dp[y]);
			continue;
		}
		for(int z=0;z<4;++z){
			int nx=x+dx[z],ny=y+dy[z];
			if(in(nx,ny)&&dis[id[nx][ny]]>dis[o]+val[x][y][z]){
				dis[id[nx][ny]]=dis[o]+val[x][y][z];
				push(id[nx][ny],id[nx][ny]);
			}
		}
	}
}
void work(){
	sz=0;
	ans=1ll<<60;
	scanf("%d%d",&k,&n);
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			id[i][j]=++sz;
		}
	}
	for(int i=1;i<=k;++i){
		scanf("%d%d%d%d",&lx[i],&ly[i],&rx[i],&ry[i]);
	}
	solve();
	for(int i=1;i<=k;++i){
		swap(lx[i],ly[i]);
		swap(rx[i],ry[i]);
	}
	solve();
	printf("%lld\n",k-ans);
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
7 2
1 1 1 2
2 1 2 2
1 1 1 2
1 1 2 1
1 2 2 2
1 1 2 1
1 2 2 2
*/