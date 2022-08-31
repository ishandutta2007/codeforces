/*
Give me purity, strength and affection
Give me lust to ignite my devotion for life
It's where beauty comes alive

Can't you see I'm a slave to the darkness
Cutting down
And I know I have done this before
As I stare into the wall

And no it's time to let it shine
Cause don't you know I'm addicted

Massive addictive
And suddenly I'm greatly affected
Like burning fire inside
My cyanide
Scared of losing my mind
Massive addictive
I'm totally completely afflicted
As I inspire the lie like a lullaby
Crawling around in my mind

Unremitting
Demand of my hunger
Time stands still
As I am losing the grip of it all
Like a thousand times before

Give me antidotes
Constant removers
Make an instant deductive denial in vain
Cause I always stay the same

And now it's time to be reborn
Although I know it's addictive

It's massive destruction
Combination of glory and hope
A schematic affliction
Of a feeling inside what I sworn
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define ry asdgasdg
#define rx iqowputtew

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 250;

using namespace std;

int n,m,tests;
string st;
int board[N][N];
int dx[N],dy[N];
int used[N][N];
bool have_cycle;
pair<int, int> cycle_start,cycle_end;
vector<pair<int, int> > g[N][N];
pair<int, int> par[N][N];
pair<int, int> cur;
vector<vector<pair<int, int> > > cycles;
vector<int> cycle_masks;
int lent[100];
int on_cycle[N][N];

bool outside(int a,int b)
{
	return (a<0||a>=n||b<0||b>=m);
}

void dfs(int a,int b)
{
	used[a][b]=1;
	for (int i=0;i<g[a][b].size();i++)
	{
		int tox,toy;
		tox=g[a][b][i].first;
		toy=g[a][b][i].second;
		if (used[tox][toy]==2)
			continue;
		if (used[tox][toy]==1)
		{
			have_cycle=1;
			cycle_start=make_pair(tox,toy);
			cycle_end=make_pair(a,b);
			continue;
		}
		par[tox][toy]=make_pair(a,b);
		dfs(tox,toy);
	}
	used[a][b]=2;
}

int found;
int indeg[N][N];
vector<pair<int, int> > starts;

void solve(int a,int b, int ps)
{
//	cout<<"@"<<a<<" "<<b<<" "<<ps<<" "<<board[a][b]<<endl;
	
	if (ps<0)
	{
		found=1;
		return ;
	}
	if (st[ps]==board[a][b]+'0')
		--ps;
	//cout<<"@"<<ps<<endl;
	
	if (ps<0)
	{
		found=1;
		return;
	}
	for (int i=0;i<g[a][b].size();i++)
	{
		int tox,toy;
		tox=g[a][b][i].first;
		toy=g[a][b][i].second;
		solve(tox,toy,ps);
	}
}

string compress(string st)
{
	string res="";
	for (int i=0;i<st.size();i++)
		if (i==0||st[i]!=st[i-1])
			res+=st[i];
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m>>tests;
	for (int i=0;i<n;i++)
	{
		cin>>st;
		for (int j=0;j<m;j++)
		{
			board[i][j]=st[j]-48;
		}
	}
	
	for (int i=0;i<10;i++)
		cin>>dx[i]>>dy[i];
	
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			int ni=i+dx[board[i][j]];
			int nj=j+dy[board[i][j]];
			if (outside(ni,nj))
				continue;
			g[ni][nj].push_back(make_pair(i,j));
			indeg[i][j]=1;
//			cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
		}
		
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (used[i][j])
				continue;
			have_cycle=0;
			dfs(i,j);
			if (!have_cycle)
			{
				if (indeg[i][j]==0)
					starts.push_back(make_pair(i,j));
				continue;
			}
			cur=cycle_end;
			vector<pair<int, int> > this_cycle;
			int mask=0;
			
			while (cur!=cycle_start)
			{
				this_cycle.push_back(cur);
				on_cycle[cur.first][cur.second]=1;
				mask|=(1<<board[cur.first][cur.second]);
				pair<int, int> temp=par[cur.first][cur.second];
				cur=temp;
			}
			mask|=(1<<board[cur.first][cur.second]);
			this_cycle.push_back(cur);
			on_cycle[cur.first][cur.second]=1;
			cycles.push_back(this_cycle);
			cycle_masks.push_back(mask);
			/*for (int q=0;q<this_cycle.size();q++)
				cout<<this_cycle[q].first<<"  % "<<this_cycle[q].second<<endl;
			cout<<"@"<<endl;
			*/
		}
	}
	
	for (;tests;--tests)
	{
	//	string st;
		cin>>st;
		
		st=compress(st);
		
		for (int i=0;i<10;i++)
			lent[i]=-1;
		for (int i=0;i<st.size();i++)
			lent[st[i]-'0']=i;
		
		found=0;
		
		for (int i=0;i<cycles.size();i++)
		{
			int fbad=-1;
			for (int j=0;j<10;j++)	
				if (!(cycle_masks[i]&(1<<j)))
					fbad=max(fbad,lent[j]);
			if (fbad==-1)
				found=1;
			for (int j=0;j<cycles[i].size();j++)
			{
				pair<int, int> p = cycles[i][j];
				for (int q=0;q<g[p.first][p.second].size();q++)
				{
					pair<int, int> P=g[p.first][p.second][q];
					if (on_cycle[P.first][P.second])
						continue;
					solve(P.first,P.second,fbad);
				}
			}
		}
		
		//cout<<"@"<<found<<endl;
		
		for (int i=0;i<starts.size();i++)
		{
			solve(starts[i].first,starts[i].second,st.size()-1);
		}
		if (found)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}