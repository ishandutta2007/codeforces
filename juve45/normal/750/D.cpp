#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

long long n, k;

long long dx[] = {1, 1, 0, -1, -1, -1,  0,  1};
long long dy[] = {0, 1, 1,  1,  0, -1, -1, -1};
long long t[33];
long long m[355][355][11], aa[355][355];

queue <pair<pair<long long,long long>, long long> > q, q1;

pair<pair<long long,long long>, long long> oo;

void add(long long x, long long y)
{
	aa[x+155][y+155] = 1; 
}

void ins(long long x, long long y, long long z)
{
	m[x+155][y+155][z] = 1;
}

long long que(long long x, long long y, long long z)
{
	return m[x+155][y+155][z];
}


void bfs()
{
	q.push({{0, 0}, 0});
	ins(0,0,0);

	for(long long i=1;i<=n;i++)
	{
		memset(m, 0, sizeof(m));

		while(!q.empty())
		{
			pair<pair<long long,long long>, long long> oo = q.front();
			q.pop();
			pair<long long, long long> p = oo.x;
			long long dir = oo.y;

			for(long long h = 1; h<=t[i]; h++)
			{
				add(p.x+dx[dir]*h, p.y+dy[dir]*h);
			}
			long long dir2 = dir-1;
			if(dir2 == -1) dir2 = 7;
			if(que(p.x+dx[dir]*t[i], p.y+dy[dir]*t[i],dir2)==0)
			{
				ins(p.x+dx[dir]*t[i], p.y+dy[dir]*t[i], dir2);
				q1.push({{p.x+dx[dir]*t[i], p.y+dy[dir]*t[i]}, dir2} );
			}
			if(que(p.x+dx[dir]*t[i], p.y+dy[dir]*t[i], (dir+1)%8)==0)
			{
				ins(p.x+dx[dir]*t[i], p.y+dy[dir]*t[i], (dir+1)%8);
				q1.push({{p.x+dx[dir]*t[i], p.y+dy[dir]*t[i]}, (dir+1)%8 } );
			}
		}
		while(!q1.empty())
		{
			q.push(q1.front());
			q1.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	long long ans = 0;
	cin >> n;
	for(long long i=1;i<=n;i++)
		cin >> t[i];
	bfs();
	for(long long i=0;i<350;i++)
		for(long long j=0;j<350;j++)
			ans += aa[i][j];
		cout << ans << '\n';


	return 0;
}