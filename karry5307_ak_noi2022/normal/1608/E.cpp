#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
struct pnt
{
	int x,y,id;pnt(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}
};
bool xicmp(pnt a,pnt b){return a.x<b.x;}
bool xdcmp(pnt a,pnt b){return a.x>b.x;}
bool yicmp(pnt a,pnt b){return a.y<b.y;}
bool ydcmp(pnt a,pnt b){return a.y>b.y;}

pnt C[4][4][400000],P[1000000];int cntc[4];
vector<int> V[4];
bool vis[4];

int xu,xd,yu,yd;

bool dfs(int cur,int x)
{
	//printf("dFS: %d %d %d %d %d %d\n",cur,x,xu,xd,yu,yd);
	int XU=xu,XD=xd,YU=yu,YD=yd;
	V[cur].clear();
	for(int i=1;i<=3;i++)
	{
		if(!vis[i])
		{
			//printf("goto: %d\n",i);
			if(cur==3)
			{
				int cnt=0;
				for(int j=1;j<=n&&cnt<x;j++)if(C[i][0][j].x>xd&&C[i][0][j].x<xu&&C[i][0][j].y>yd&&C[i][0][j].y<yu)cnt++,V[cur].push_back(C[i][0][j].id);
				//printf("CNT: %d %d\n",i,cnt);
				if(cnt==x)return 1;
				V[cur].clear();
			}
			else
			{
				vis[i]=1;
				for(int k=0;k<4;k++)
				{
					int cnt=0;
					for(int j=1;j<=n&&cnt<x;j++)if(C[i][k][j].x>xd&&C[i][k][j].x<xu&&C[i][k][j].y>yd&&C[i][k][j].y<yu)
						cnt++,V[cur].push_back(C[i][k][j].id);
					if(cnt<x){V[cur].clear();continue;}
					int u=V[cur][x-1];
					if(k==0)xd=max(xd,P[u].x);else if(k==1)xu=min(xu,P[u].x);else if(k==2)yd=max(yd,P[u].y);else yu=min(yu,P[u].y);
					if(dfs(cur+1,x))return 1;
					V[cur].clear();xd=XD,xu=XU,yd=YD,yu=YU;
				}
				vis[i]=0;
			}
			V[cur].clear();
		}
	}
	return 0;
}

const int INF=1e9+1;

bool check(int x)
{
	for(int i=1;i<=3;i++)V[i].clear(),vis[i]=0;
	xu=yu=INF,xd=yd=-INF;
	return dfs(1,x);
}

int main()
{
	scanf("%d",&n);n/=3;
	for(int i=1,x=0,y=0,c=0;i<=3*n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);C[c][0][++cntc[c]]=(pnt(x,y,i));
		P[i].x=x,P[i].y=y,P[i].id=c;
	}
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)for(int k=1;k<=n;k++)C[i][j][k]=C[i][0][k];
	for(int i=1;i<=3;i++)sort(C[i][0]+1,C[i][0]+n+1,xicmp),
	sort(C[i][1]+1,C[i][1]+n+1,xdcmp),
	sort(C[i][2]+1,C[i][2]+n+1,yicmp),
	sort(C[i][3]+1,C[i][3]+n+1,ydcmp);
	//puts("OK");return 0;
	//check(1);return 0;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;if(check(mid))l=mid;else r=mid-1;
		//printf("%d\n",mid);
	}
	printf("%d\n",3*l);
	//check(l);for(int i=1;i<=3;i++)for(int j=0;j<l;j++)printf("%d ",V[i][j]);puts("");
}