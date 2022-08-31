/*
I can still remember
The words and what they meant
As we etched them with our fingers
In years of wet cement
The days blurred into each other
Though everything seemed clear
We cruised along at half speed
But then we shifted gears

We ran like vampires from a thousand burning suns
But even then we should have stayed
But we ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?

Identities assume us
As nine and five add up
Synchronizing watches
To the seconds that we lost
I looked up and saw you
I know that you saw me
We froze but for a moment
In empathy

I brought down the sky for you but all you did was shrug
You gave my emptiness a name
But you ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?

We're all ok, until the day we're not
The surface shines, while the inside rots
We raced the sunset and we almost won
We slammed the brakes, but the wheels went on

We ran away
Now all my friends are gone
Maybe we've outgrown all the things that we once loved
Runaway
But what are we running from?
A show of hands from those in this audience of one
Where have they gone?
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300;

int n,m,q,p;

int ban[N][N];

vector<pair<int,int> > let_list;

int pw[N][N];

bool outside(int a,int b){
	return (a<1||a>n||b<1||b>m);
}

queue<pair<int,int> > qu;
vector<pair<int,int> > visited;
int used[N][N];
int ans;
long long score[N][N];
int P,Q;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>Q>>P;
	for (int i=1;i<=n;i++){
		string st;
		cin>>st;
		for (int j=1;j<=m;j++)
		{
			if (st[j-1]=='*')
				ban[i][j]=1;
			else
			{
				if (st[j-1]>='A'&&st[j-1]<='Z'){
					let_list.push_back(make_pair(i,j));
					pw[i][j]=st[j-1]-'A'+1;
				}
			}
		}
	}

	for (int i=0;i<let_list.size();i++)
	{
		pair<int,int> p=let_list[i];
		visited.clear();
		qu.push(p);
		used[p.first][p.second]=1;
		while (qu.size()){
			pair<int,int> p=qu.front();
			qu.pop();
			visited.push_back(p);
			if (used[p.first][p.second]>30)
				continue;
			for (int dx=-1;dx<=1;dx++)
			{
				for (int dy=-1;dy<=1;dy++)
				{
					if (abs(dx)+abs(dy)!=1)
						continue;
					if (outside(p.first+dx,p.second+dy))
						continue;
					if (ban[p.first+dx][p.second+dy])
						continue;
					if (used[p.first+dx][p.second+dy])
						continue;
					used[p.first+dx][p.second+dy]=used[p.first][p.second]+1;
					qu.push(make_pair(p.first+dx,p.second+dy));
				}
			}
		}
		int starting_power=pw[p.first][p.second]*Q;
		for (int j=0;j<visited.size();j++)
		{
			int a=visited[j].first;
			int b=visited[j].second;
			int here=starting_power;
			here>>=(used[a][b]-1);
			score[a][b]+=here;
			used[a][b]=0;
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
		//	cout<<score[i][j]<<" ";
			if (score[i][j]>P)
				++ans;
		}
//		cout<<endl;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}