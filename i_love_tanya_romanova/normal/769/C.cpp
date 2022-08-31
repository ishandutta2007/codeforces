/*
Convicted witch my life will end
At midnight on the stake
My dedicated life was spent
To insubordinate
Secured by lock inside a cell
Imprisoned for no crime
The shackles will be useless
When your life is out of time

Incantation spell gone by
I will see life again
My deals will made eternally
I signed the book of red
My rage will be unleashed again
Burning the next morn
Death means nothing, there is no end
I will be reborn

No gift of exile in my fate
I'll get no amnesty
You can't control my destiny
There is no habitual need
Proclaim my death, to end my wrath
It takes more than one try
Indulge your ineffective curse
I will never die

You think by killing me tonight
My powers will not rise
There'll be nowhere for you to run
When my hatred comes to life
Condemned to fill the prophecy
Allowing no first born
Defy your morbid declaration
Leave you ripped and torn

Count your blessing would be priest
As I burn upon the stake
You'd be forgiven endlessly
But your values are all fake
Forever servant of my Lord
By choice and not submission
Maybe now I've made you wonder
Am I superstition

Incantation spell gone by
I will live again
My deals will made eternally
I signed the book in red
My rage will be unleashed again
Burning the next morn
Death means nothing there is no end
I will be reborn
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
#define BS 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1031;

int n,m,k;
int board[N][N];
int si,sj;
int dist[N][N],used[N][N];

bool outside(int a,int b)
{
	return (a<1||a>n||b<1||b>m);
}

bool valid_move(int a,int b,int D)
{
	if (outside(a,b))
		return false;
	if (board[a][b])
		return false;
	return (dist[a][b]<=D);
}

bool is_blocked(int a,int b)
{
	for (int dx=-1;dx<=1;dx++)
	{
		for (int dy=-1;dy<=1;dy++)
		{
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (valid_move(a+dx,b+dy,10000000))
				return false;
		}
	}
	return true;
}

queue<pair<int,int> > qu;

string ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=m;j++)
		{
			if (st[j-1]=='*')
			{
				board[i][j]=1;
				continue;
			}
			if (st[j-1]=='X')
			{
				si=i;
				sj=j;
			}
		}
	}

	qu.push(make_pair(si,sj));
	used[si][sj]=1;

	while (qu.size())
	{
		pair<int,int> p=qu.front();
		qu.pop();
		int a=p.first;
		int b=p.second;

		for (int dx=-1;dx<=1;dx++)
		{
			for (int dy=-1;dy<=1;dy++)
			{
				if (abs(dx)+abs(dy)!=1)
					continue;
				if (outside(a+dx,b+dy))
					continue;
				if (board[a+dx][b+dy])
					continue;
				if (used[a+dx][b+dy])
					continue;
				used[a+dx][b+dy]=1;
				dist[a+dx][b+dy]=dist[a][b]+1;
				qu.push(make_pair(a+dx,b+dy));
			}
		}

	}

	if (k%2==1||is_blocked(si,sj))// k!=0
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

	for (int i=1;i<=k;i++)
	{
		if (valid_move(si+1,sj,k-i))
		{
			ans+="D";
			si++;
		}
		else if (valid_move(si,sj-1,k-i))
		{
			ans+="L";
			sj--;
		}
		else if (valid_move(si,sj+1,k-i))
		{
			ans+="R";
			sj++;
		}
		else
		{
			ans+="U";
			si--;
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}