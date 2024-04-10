/*
Funeral held for the depression of man
Holds the key to his own death
Entering a tomb of a corpse yet conceived
Tighten the tourniquet around your neck

Sifting away the debris of hated life
Cold touch of death begins to chill your spine
Seeking life beyond your perishment
Repeating words echoing through your mind

Chanting lines of blind witchery
To save yourself from extinction
Wanting to die is your reason to live
New life born from the oppressed

Taste your blood as it trickles through the air
Another casualty beyond the shadows you fall
Losing ground, the fate you feel it draws near
Fatality, reality, you await the final call

My sinful glare at nothing holds thoughts of death behind it
Skeletons in my mind commence tearing at my sanity
Vessels in my brain carry death until my birth
Come and die with me forever
Share insanity

Do you want to die!

The waves of blood are rushing near, pounding at the walls of lies
Turning off my sanity, reaching back into my mind
Non-rising body from the grave showing new reality
What I am, what I want, I'm only after death
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

typedef pair<pair<int,int>,pair<int,int> > quad;

quad make_quad(int a,int b,int c,int d)
{
	return make_pair(make_pair(a,b),make_pair(c,d));
}

int n,m,si,sj,fi,fj;
queue<quad> qu;
int used[1031][1031][5][4];

int ni,nj;
int dx[10],dy[10];

int board[1031][1031];

bool outside(int a,int b)
{
	return (a<1||a>n||b<1||b>m);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	dx[0]=1;
	dx[2]=-1;
	dy[1]=1;
	dy[3]=-1;

	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=m;j++)
		{
			if (st[j-1]=='S')
			{
				si=i;
				sj=j;
				continue;
			}
			if (st[j-1]=='T')
			{
				fi=i;
				fj=j;
				continue;
			}
			if (st[j-1]=='*')
				board[i][j]=1;
		}
	}

	for (int i=0;i<4;i++)
	{
		qu.push(make_quad(si,sj,i,0));
		used[si][sj][i][0]=1;
	}

	while (qu.size())
	{
		quad temp=qu.front();
		qu.pop();
		// mov
		ni=temp.first.first+dx[temp.second.first];
		nj=temp.first.second+dy[temp.second.first];
//		cout<<temp.first.first<<" "<<temp.first.second<<" "<<temp.second.first<<" "<<temp.second.second<<endl;

//		cout<<ni<<" "<<nj<<endl;

		if (outside(ni,nj)==1||board[ni][nj]==1||used[ni][nj][temp.second.first][temp.second.second])
		{
			;
		}
		else
		{

			qu.push(make_quad(ni,nj,temp.second.first,temp.second.second));
			used[ni][nj][temp.second.first][temp.second.second]=1;
		}

		// rotate

		if (temp.second.second==2)
			continue;

		for (int new_dir=0;new_dir<4;new_dir++)
		{
		//	cout<<temp.first.first<<" "<<temp.first.second<<" "<<new_dir<<"%"<<endl;

			if (used[temp.first.first][temp.first.second][new_dir][temp.second.second+1])
				continue;
			used[temp.first.first][temp.first.second][new_dir][temp.second.second+1]=1;
			qu.push(make_quad(temp.first.first,temp.first.second,new_dir,temp.second.second+1));
		}
	}

	int ok=0;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<=2;j++)
		{
			if (used[fi][fj][i][j])
				ok=1;
		}
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}