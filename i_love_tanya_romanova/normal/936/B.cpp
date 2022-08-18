/*
Dark shadows lie over the city, tonight someone will die
You can hear some painful scream the air is full of flies
The mayhemic legions are ready to steal the human souls
Come into my vault and do what you've been told

I'll eat your intestines
No matter if you pray or please
I'll bring you down to your knees
Tonight you're gonna meet your fate
You'll try to run but it's too late
I am here to liquidate

Time to raise your flag of hate
Destroy the world is our only aim
To strike 'em down is the only way
To make 'em death and let 'em pay

The galleys of the underground sail on the sea of blood
All what we want is to crucify your god
The posers on this Earth have no right to live
We're gonna split their brains, torture is what we give
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n,m;
vector<int> g[N],gr[N];
queue<pair<int,int> > qu;
int used[N][2];
pair<int,int> par[N][2];

int was[N];
int found_cycle;

void dfs(int v){
	was[v]=1;
	if (found_cycle)
		return;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (was[to]==2)
			continue;
		if (was[to]==1){
			found_cycle=1;
			return;
		}
		dfs(to);
	}
	was[v]=2;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		for (;cnt;--cnt){
			int to;
			cin>>to;
			g[i].push_back(to);
			gr[to].push_back(i);
		}
	}

	for (int i=1;i<=n;i++){
		if (g[i].size()==0){
			used[i][0]=1;
			qu.push(make_pair(i,0));
		}
	}

	while (qu.size()){
		pair<int,int> p=qu.front();
		qu.pop();
		int v=p.first;
		for (int i=0;i<gr[v].size();i++){
			int to=gr[v][i];
			if (used[to][p.second^1])
				continue;
			used[to][p.second^1]=1;
			qu.push(make_pair(to,p.second^1));
			par[to][p.second^1]=p;
		}
	}

	int start;

	cin>>start;

	int cur=1;

	if (used[start][cur]==1)
	{
		cout<<"Win"<<endl;

		int flag=0;

		while (true){
			if (flag)
				cout<<" ";
			flag=1;
			cout<<start;
			pair<int,int> to=par[start][cur];
			int new_start=to.first;
			if (new_start==0)
				break;
			start=new_start;
			cur^=1;
		}
		cout<<endl;
		return 0;
	}

	dfs(start);
	if (found_cycle){
		cout<<"Draw"<<endl;
	}
	else
	{
		cout<<"Lose"<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}