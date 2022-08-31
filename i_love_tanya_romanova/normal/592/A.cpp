/*
Bravery
As we've all seen on TV
Explosions and swords
Hot girls in reward

And in the games you play
You are the hero of the day
But outside that land
Your head's in the sand

And you think you are bold, and you think you are brave
When push comes to shove, you know it's a feign
You're better off if you choose to abstain
Your fear is your true grave

Turn your head
From all the things you dread
It will keep you alive
At least for a while

And all your sympathy
Is like flowers and tea
Sent by the man
Who betrayed your clan

You have covered your eyes, you have covered your ears
So easy to hide from confronting your fears
Sooner or later it will all end in tears
The cry that no-one hears

Good morning world, this is your wake-up call
It's not your war you say, while you turn your head away
A thousand deaths for you to die before you fall
Mayday, Mayday, S.M.S. Save My Soul, forget the rest

Good morning world, this is your wake-up call
Those who stand for nothing at all, for anything are bound to fall
A thousand deaths for you to die before you fall
Your lame excuses you can spare, they only live who dare!

Coins you toss
Weighted by your fear of loss
Both sides are heads
The tails between your legs

And just as well as I
You know what you should do and why
But just falter on
And hope it'd be gone

And you think you are bold, and you think you are brave
When push comes to show, you know it's a feign
You're better off if you choose to abstain
Your fear is your true grave

Good morning world, this is your wake-up call
It's not your war you say, while you turn your head away
A thousand deaths for you to die before you fall
Mayday, Mayday, S.M.S. Save My Soul, forget the rest

Die! Die you sucker die!
Let me go! Let me free motherfucker!
Die! Die you sucker die!
Let the coward die!

Time stands still
For you to write your will
What's left behind
No way to rewind
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
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define N ((1<<21)+31)
//#define root 1
#define M 150

using namespace std;

char board[100][100];
int m1,m2;

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	for (int i=1;i<=8;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=8;j++)
		{
			board[i][j]=st[j-1];
		}
	}
	
	m1=m2=1e9;
	for (int i=1;i<=8;i++)
	{
		for (int j=1;j<=8;j++)
		{
			if (board[i][j]=='W')
			{
				int dist=i-1;
				int er=0;
				for (int q=i-1;q>=1;--q)
					if (board[q][j]=='B')
						er=1;
				if (er==0)
					m1=min(m1,dist);
			}
		}
	}
	for (int i=1;i<=8;i++)
	{
		for (int j=1;j<=8;j++)
		{
			if (board[i][j]=='B')
			{
				int dist=8-i;
				int er=0;
				for (int q=i+1;q<=8;q++)
					if (board[q][j]=='W')
						er=1;
				if (er==0)
					m2=min(m2,dist);
			}
		}
	}
	if (m1<=m2)
	cout<<"A"<<endl;
	else
		cout<<"B"<<endl;
		
	return 0;
	
}