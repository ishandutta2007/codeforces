// Hydro submission #62f7ab90a9a216a74d5151f6@1660398480609
// 254D Rats
/*
Choose arbitrary rat (for say, the leftmost of the upmost).
It's cell should be cleared. 
Make a BFS that never goes further than d from this cell 
(we will call such a BFS by d-BFS). 
So, we have to blow the first grenade in one of the visited cells. 
Lets check every visited cell as a candidate. 
Make a d-BFS from the candidate cell. 
Some cells with the rats will not be visited. 
That means that they should be cleared by the second grenade. 
Choose arbitrary cell with a rat that was not cleared by the first grenade. 
Make a d-BFS from it. 
All cells visited by this BFS are candidates to blow the second grenade. 
Lets check every such cell. 
Checking a cell again means making a d-BFS from it. 
If this BFS visits all cells that were not cleared by the first grenade, 
that we have found a solution. 
*/
/*
#include <bits/stdc++.h>
#define var long long
#define SIZE 1005
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;

struct site
{
	int x;
	int y;
	int step;
};
vector<site> rats;

char a[SIZE][SIZE];
int vis[SIZE][SIZE]={0};
vector<site> been;
int m, n; 
int d; 

void d_bfs(int i, int j, bool flag, int times)
{
	queue<site> Q;
	site t={i, j, 0};
	Q.push(t);
	while(!Q.empty())
	{
		site w=Q.front(); Q.pop();
		if(w.step==d+1) continue;
		int i=w.x, j=w.y;
		if(a[i][j]=='X') continue;
		if(vis[i][j]==times) continue;
		if(flag)
			been.push_back(w);
		vis[i][j]=times;
		if(i+1<m)
		{
			site t={i+1, j, w.step+1};
			Q.push(t);	
		}
		if(i-1>=0)
		{
		//	site t={i+1, j, w.step+1};
			site t={i-1, j, w.step+1};
			Q.push(t);	
		}
		if(j+1<n)
		{
			site t={i, j+1, w.step+1};
			Q.push(t);
		}
		if(j-1>=0)
		{
			site t={i, j-1, w.step+1};
			Q.push(t);
		}
	}
}

bool Check(vector<site> v)
{
	for(site x:v)
		if(vis[x.x][x.y]==0)
			return 0;
	return 1;
}

int main()
{
	freopen("input.txt",  "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>m>>n>>d;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='R')
				rats.push_back({i, j});
		}
	}
	
	if(rats.size()>=290)
	{
		puts("-1");
		return 0;
	}
			
	d_bfs(rats[0].x, rats[0].y, 1, 1);
	auto v1=been; been.clear();
	bool f=1;
	for(site rat:rats)
		if(vis[rat.x][rat.y]==0)
		{
			f=0; break;
		}			
	if(f)
	{
		//cout<<rats[0].x+1<<' '<<rats[0].y+1<<' ';
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				if(i!=rats[0].x && j!=rats[0].y && a[i][j]!='X')
				{
					cout<<rats[0].x+1<<' '<<rats[0].y+1<<' '<<i+1<<' '<<j+1;
					return 0;
				}
			}
	}
	int times=2;
	for(auto s:v1)
		d_bfs(s.x, s.y, 0, times++);	
	
	vector<site> v2;
	for(site rat:rats)
	{
		if(vis[rat.x][rat.y]==0)
		{
			d_bfs(rat.x, rat.y, 1, times+1);
			puts("");	
			
			v2=been;
			f=0;
			break;
		}
	}
	for(site bomb1:v1)
		cout<<bomb1.x<<" "<<bomb1.y<<endl;
	cout<<endl;
	for(site bomb2:v2)
		cout<<bomb2.x<<" "<<bomb2.y<<endl;
	
	for(site bomb1:v1)
		for(site bomb2:v2)
		{
			for(int i=0; i<m; i++)
				for(int j=0; j<n; j++)
					vis[i][j]=0;
			d_bfs(bomb1.x, bomb1.y, 0, 1);
			d_bfs(bomb2.x, bomb2.y, 0, 2);
			if(Check(rats))
			{
				cout<<bomb1.x+1<<' '<<bomb1.y+1<<' '
					<<bomb2.x+1<<' '<<bomb2.y+1;
				return 0;
			}
		}
	puts("-1");

    return 0;
}
*/
// author:wzr
// date:2022/8/13
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define SIZE 1002
#define all(x) x.begin(), x.end()
#define debug(x) cerr<<#x<<":"<<x<<endl;
using namespace std;

int m, n, d;
char a[SIZE][SIZE];
bool vis[5][SIZE][SIZE];

struct node
{
	int i, j;
	int s;	
};

vector<node> rat;

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

void d_bfs(int si, int sj, int turn)
{
	queue<node> q;
	q.push({si, sj, 0});
	while(!q.empty())
	{
		node w=q.front(); q.pop(); int i=w.i, j=w.j;
		//  
		if(a[i][j]=='X') continue;
		// 
		if(vis[turn][i][j]) continue;
		if(w.s>d) continue;
		vis[turn][i][j]=1;
		for(int k=0; k<4; k++) 
		{
			int ni=i+dx[k];
			int nj=j+dy[k];
			q.push({ni, nj, w.s+1});
		}
	}
}

bool Check()
{
	/*
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
			cerr<<vis[2][i][j];
		cerr<<endl;
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
			cerr<<vis[4][i][j];
		cerr<<endl;
	}*/
	for(auto t:rat)
		if(!vis[2][t.i][t.j] && !vis[4][t.i][t.j])
			return 0;
	return 1;
}

void Solve()
{
	rat.clear();
	int empty=0;
	for(int i=1; i<=m; i++)	
	{
		for(int j=1; j<=n; j++)	
		{
			cin>>a[i][j];
			if(a[i][j]=='R') rat.push_back({i, j, 0});
			if(a[i][j]!='X') empty++;
		}
	}
	//debug(rat.size())
	if(rat.size()>8*d*d || empty<2) { printf("-1"); return; }
	if(rat.size()==0)
	{
		int cnt=0;
		for(int i=1; i<=m; i++)	
			for(int j=1; j<=n; j++)
			{
				if(a[i][j]!='X') printf("%d %d ", i, j), cnt++;
				if(cnt==2) return;
			}
	}
	if(rat.size()==1)
	{
		printf("%d %d ", rat[0].i, rat[0].j);
		for(int i=1; i<=m; i++)	
			for(int j=1; j<=n; j++)
			{
				if(a[i][j]!='X' && (i!=rat[0].i || j!=rat[0].j)) 
				{
					printf("%d %d ", i, j); return;
				}
			}
	}
	memset(vis[1], 0, sizeof(vis[1]));
	d_bfs(rat[0].i, rat[0].j, 1);
	// 
	for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) if(vis[1][i][j])
	{
		//  
		//debug(i) debug(j)
		memset(vis[2], 0, sizeof(vis[2])); 
		d_bfs(i, j, 2);
		//  
		bool f=0;
		for(auto t:rat)
		{
			if(!vis[2][t.i][t.j])
			{
				f=1;
				memset(vis[3], 0, sizeof(vis[3]));
				d_bfs(t.i, t.j, 3);
				break;						
			}
		}
		//debug(f)
		if(!f)
		{
			printf("%d %d ", i, j);
			for(int ii=1; ii<=m; ii++)
				for(int jj=1; jj<=n; jj++)	//   
					if(a[ii][jj]!='X' && (i!=ii || j!=jj))
					{
						printf("%d %d ", ii, jj);
						return;
					}
		}
		for(int ii=1; ii<=m; ii++) for(int jj=1; jj<=n; jj++) if(vis[3][ii][jj])
		{
			// 
			if(i!=ii || j!=jj)
			{
				//debug(ii) debug(jj)
				memset(vis[4], 0, sizeof(vis[4])); 
				d_bfs(ii, jj, 4);
				if(Check())
				{
					printf("%d %d %d %d", i, j, ii, jj); 
					return;
				}
			}
		}
	}
	printf("-1");
}

signed main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(scanf("%d %d %d", &m, &n, &d)!=EOF)
	{
		Solve();
		putchar('\n');
		//cerr<<"execute OK!\n";
		//system("pause");
	}

    return 0;
}