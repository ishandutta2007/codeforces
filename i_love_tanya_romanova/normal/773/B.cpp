/*
Suicide a month before I met you
Deep regrets, I never could forget you
Somehow you made your way to my decade
Ayo ayo ayo ayo my girl

In the sun, I see you with your guard down
Number one, you're moving to a hard town
Do not dismiss the promise that you made me
Ayo ayo ayo ayo, my time

Overkill you took another red pill
On the sheet is everything that you spilled
We are the ones you want to know right now
Ayo ayo ayo ayo, black light

Come again to murder your report card
Just a friend to kiss you in the court yard
You are the one I want to be stuck with
Ayo ayo ayo ayo big fight

Favor Some
Way too young
Slave to none
Way too young

Say goodbye my love
I can see it in your soul
Say goodbye my love
Thought that I could make you whole
Let your lover sail
Death was made to fail

Sticky fingers find the way to take her
Crumple up another piece of paper
I know your days are numbered when it comes to
Ayo ayo ayo ayo this life

Slip away into the solar system
Straighter rays, you find a way to twist them
Some like it dark and now I know where to
Ayo ayo ayo ayo find you

Serpentine, I think she was an Aussie
Bloody hell, a common kamikaze
Give up the ghost before you go under
Ayo ayo aye ayo wonder

Kicking hard and looking for a rescue
Watch me starve was never to impress you
I would have killed the part of me to have you
Ayo ayo ayo ayo story

Say goodbye my love
I can see it in your soul
Say goodbye my love
Thought that I could make you whole
Let your lover sail
Death was made to fail

Babe I know love is a funny thing
Born to die in the eternal spring

Your flickering is more than just a small flame
Welcome to the party, it's a ball game
Pick up the stick it's time to get hit with
Ayo ayo ayo ayo my bat

Suicide is never going to save you
When I cried, it was because I came too
You are the one I want to know right now
Ayo ayo ayo ayo kiss this
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

int n,a[N][6];
int people_solved[N];
int should_add[N];

int get_group(int problem)
{
	for (int i=1;i<=5;i++)
	{
		if (people_solved[problem]*(1<<i)>n)
			return i;
	}
	return 6;
}

int get_score(int person,int problem)
{
	if (a[person][problem]==-1)
		return 0;
	int group=get_group(problem);
	int base_score=group*500;
	return base_score-base_score/250*a[person][problem];
}

int eval(int person_id)
{
	int res=0;
	for (int j=1;j<=5;j++)
	{
		res+=get_score(person_id,j);
	}
	return res;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=5;j++)
		{
			cin>>a[i][j];
			if (a[i][j]!=-1)
				people_solved[j]++;
		}
	}

	for (int i=1;i<=5;i++)
	{
		if (a[1][i]==-1)
			continue;
		if (get_score(1,i)<get_score(2,i))
			should_add[i]=1;
		else
			should_add[i]=0;
	}


	if (eval(1)>eval(2))
	{
		cout<<0<<endl;
		return 0;
	}

	for (int i=1;i<=100000;i++)
	{
		n++;
		for (int j=1;j<=5;j++)
		{
			if (should_add[j])
			{
				people_solved[j]++;
			}
		}

/*		for (int j=1;j<=5;j++)
		{
			cout<<get_score(1,j)<<" "<<get_score(2,j)<<endl;
		}
*/
		if (eval(1)>eval(2))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;

	cin.get(); cin.get();
	return 0;
}