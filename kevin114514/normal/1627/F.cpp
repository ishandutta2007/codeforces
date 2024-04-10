#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<pair<pii,int> > G[550][550];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int dist[550][550];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&k,&n);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				G[i][j].clear();
				for(int d=0;d<4;d++)
				{
					int nx=i+dx[d];
					int ny=j+dy[d];
					if(nx>=0&&ny>=0&&nx<=n&&ny<=n)
						G[i][j].pb(mp(mp(nx,ny),0));
				}
				srt(G[i][j]);
			}
		for(int i=0;i<k;i++)
		{
			int r1,c1,r2,c2;
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			if(r1==r2)
			{
				r1--;
				c1=c2=min(c1,c2);
			}
			else
			{
				c1--;
				r1=r2=min(r1,r2);
			}
			G[r1][c1][lb(G[r1][c1],mp(mp(r2,c2),0))].second++;
			G[r2][c2][lb(G[r2][c2],mp(mp(r1,c1),0))].second++;
//			cout<<G[r1][c1][lb(G[r1][c1],mp(mp(r2,c2),0))].second<<" "<<G[r2][c2][lb(G[r2][c2],mp(mp(r1,c1),0))].second<<endl;
//			cout<<" $ "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
//			puts("hello?");
			r1=n-r1;
			c1=n-c1;
			r2=n-r2;
			c2=n-c2;
//			cout<<G[r1][c1][lb(G[r1][c1],mp(mp(r2,c2),0))].second<<" "<<G[r2][c2][lb(G[r2][c2],mp(mp(r1,c1),0))].second<<endl;
			G[r1][c1][lb(G[r1][c1],mp(mp(r2,c2),0))].second++;
			G[r2][c2][lb(G[r2][c2],mp(mp(r1,c1),0))].second++;
//			puts("hello?");
//			cout<<" # "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
		}
		memset(dist,inf,sizeof(dist));
		dist[n/2][n/2]=0;
		priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > pq;
		pq.push(mp(0,mp(n/2,n/2)));
		while(!pq.empty())
		{
			auto p=pq.top();
			pq.pop();
			int x=p.second.first;
			int y=p.second.second;
			int dis=p.first;
//			cout<<x<<" "<<y<<" "<<dis<<endl;
			if(dis!=dist[x][y])
				continue;
			for(auto p1:G[x][y])
				if(dis+p1.second<dist[p1.first.first][p1.first.second])
				{
					dist[p1.first.first][p1.first.second]=dis+p1.second;
					pq.push(mp(dist[p1.first.first][p1.first.second],mp(p1.first.first,p1.first.second)));
				}
		}
		printf("%d\n",k-dist[0][0]);
	}
	return 0;
}