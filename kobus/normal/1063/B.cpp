#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

char mx[2123][2123];

int vx[4]={1,0,0,-1};
int vy[4]={0,1,-1,0};

int n,m;

int isvalid(int i,int j){
	return mx[i][j]=='.'&&i>=0&&j>=0&&i<n&&j<m;
}

int dis[2123][2123];

void dij(int r,int c){
	//cout<<r<<" "<<c<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dis[i][j]=-1;
		}
	}
	priority_queue<pair<int,pii>> q;
	dis[r][c]=0;q.push(mp(0,mp(r,c)));
	while(!q.empty()){
		r=q.top().s.f;c=q.top().s.s;
		int ct=-q.top().f;q.pop();
		if(dis[r][c]!=ct)continue;
		for(int i=0;i<4;i++){
			int nr=r+vx[i];
			int nc=c+vy[i];
			if(!isvalid(nr,nc))continue;
			int ctp=0;
			if(i==2)ctp=1;
			if(dis[nr][nc]==-1||dis[r][c]+ctp<dis[nr][nc]){
				dis[nr][nc]=dis[r][c]+ctp;
				q.push(mp(-dis[nr][nc],mp(nr,nc)));
			}
		}
	}
}




int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	int r,c;
	cin>>r>>c;
	r--;c--;
	int x,y;
	cin>>x>>y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mx[i][j];
		}
	}
	dij(r,c);
	int resp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!isvalid(i,j) || dis[i][j]==-1)continue;
			int ux=dis[i][j];
			int uy=ux+j-c;
			if(ux<=x&&uy<=y)resp++;
		}
	}
	cout<<resp<<endl;


}