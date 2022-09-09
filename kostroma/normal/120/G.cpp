#include<iostream>
#include<cstdio>
#include<string>
#include <queue>
#include <vector>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}
//#define int li
int n, t;
pair <int, int> skill[200][2];
int m;
pair < int, string > cards[200];
queue < int > q;
int d[200][200];
int points[200];
vector < string > solved[200];
pi newcur (pi cur)
{
	if ( cur.first<n-1 )
		return mp ( cur.first+1, cur.second );
	return mp (0, (cur.second+1)%2);
}
void solve()
{
	cin>>n>>t;
	for (int i=0; i<n; i++)
		cin>>skill[i][0].first>>skill[i][0].second>>skill[i][1].first>>skill[i][1].second;
	cin>>m;
	for (int i=0; i<m; i++)
	{
		cin>>cards[i].second>>cards[i].first;
		q.push(i);
	}
	pi cur=mp (0, 0);
	int curt=t;
	while (!q.empty())
	{
		int num=q.front();
		int timer=max(1, cards[num].first-skill[cur.first][cur.second].first-skill[cur.first][(cur.second+1)%2].second-d[cur.first][num] );
		if ( timer<curt )
		{
			curt-=timer;
			points[cur.first]++;
			solved[cur.first].pb ( cards[num].second );
			q.pop();
		}
		else 
			if (timer==curt)
			{
				points[cur.first]++;
				solved[cur.first].pb ( cards[num].second );
				q.pop();
				curt=t;
				cur=newcur(cur);
			}
		else 
		{
			d[cur.first][num]+=curt;
			curt=t;
			pi next=newcur(cur);
			q.pop();
			q.push(num);
			cur=next;
		}
	}
	for (int i=0; i<n; i++)
	{
		cout<<points[i]<<' ';
		for (int j=0; j<points[i]; j++)
			cout<<solved[i][j]<<' ';
		cout<<endl;
	}
}