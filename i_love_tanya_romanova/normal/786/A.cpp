/*
Spineless from the start, sucked into the part
Circus comes to town, you play the lead clown
Please, please
Spreading his disease, living by his story
Knees, knees
Falling to your knees, suffer for his glory
You will

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Marvel at his tricks, need your Sunday fix
Blind devotion came, rotting your brain
Chain, chain
Join the endless chain
Taken by his glamour
Fame, Fame
Infection is the game, stinking drunk with power
We see

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Bow to Leper Messiah
Witchery, weakening
Sees the sheep are gathering
Set the trap, hypnotize
Now you follow

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Lie.
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500331;

int n,m;
vector<int> moves[23456];
int deg[N][4];
queue<pair<int,int> > qu;

int win[N][4];

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	cin>>m;
	for (int i=1;i<=m;i++)
	{
		int a;
		cin>>a;
		moves[0].push_back(a);
	}

	cin>>m;
	for (int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		moves[1].push_back(a);
	}

	for (int i=0;i<n;i++)
	{
		deg[i][0]=moves[0].size();
		deg[i][1]=moves[1].size();
	}

	deg[0][0]=deg[0][1]=0;
	qu.push(make_pair(0,0));
	qu.push(make_pair(0,1));

	while (qu.size())
	{
		pair<int,int> p=qu.front();
		//cout<<p.first<<" "<<p.second<<endl;

		qu.pop();
		int who_moves=p.second;
		for (int i=0;i<moves[1-who_moves].size();i++)
		{
			int to=moves[1-who_moves][i];
			to=(p.first-to+n)%n;
			if (to<0)
				to+=n;

			if (win[to][1^p.second])
				continue;

			if (win[p.first][p.second]==1)// wins
			{
				deg[to][1^p.second]--;
				if (deg[to][1^p.second]==0)
				{
					qu.push(make_pair(to,1^p.second));
				}
			}
			else // lose, that one is win
			{
				win[to][1^p.second]=1;
				qu.push(make_pair(to,1^p.second));
			}
		}
	}

	for (int i=1;i<n;i++)
	{
		if (i>1)
			cout<<" ";
		if (win[i][0])
			cout<<"Win";
		else
			if (deg[i][0]==0)
				cout<<"Lose";
			else
				cout<<"Loop";
	}
	cout<<endl;

	for (int i=1;i<n;i++)
	{
		if (i>1)
			cout<<" ";
		if (win[i][1])
			cout<<"Win";
		else if (deg[i][1]==0)
			cout<<"Lose";
		else
			cout<<"Loop";
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}