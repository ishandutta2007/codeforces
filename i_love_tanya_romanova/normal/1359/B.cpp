/*
On the day I was born the rain fell down
There was trouble brewin' in my home town
It was the seventh day I was the seventh son
And it scared the hell out of every one
They said stop
I said go
They said fast
I said slow
They said yes
I said no
I do the bad boy boogie

Bein' a bad boy ain't that bad
I had me more dirty women than most men ever had
All you women come along with me
And I'll show how good a bad boy can be
I said right
And they said left
I said east
And they said west
I said up
And they said down
I do the bad boy boogie
All over town

I wouldn't tell you no story
Tell you no lie
I was born to love till the day I die
I just line em up
And I knock em down
And they all came a runnin' when the word got around
Just keep runnin'
I said up
They said down
They said straight
I said round
They said lost
I said found
I said free
They said bound
Bad boy boogie
Do the bad boy
Bad boy boogie
Bad boy boogie
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 210031;

int tests,n,m,x,y;
int ans;

int solve(string st){
	int ret=0;
	int cnt=0;
	st+="*";
	for (int i=0;i<st.size();i++){
		if (st[i]=='.')
			++cnt;
		else
		{
			ret+=y*(cnt/2)+x*(cnt%2);
			cnt=0;
		}
	}
	return ret;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m>>x>>y;
	  if (y>2*x)
		  y=2*x;
	  ans=0;
	  for (int i=1;i<=n;i++){
		  string st;
		  cin>>st;
		  ans+=solve(st);
	  }
	  cout<<ans<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}