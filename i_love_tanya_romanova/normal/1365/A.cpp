/*
Fingers scratching blackboards
Make cowards of the brave
A natural reaction
From the cradle to the grave

Rats and bats and spiders
And little things that crawl
Never make me tremble
I'm bothered not at all

Then I saw you
Something new inside of me
What's this shakin'
You made me shiver

Cemetery midnights
Walking on the dead
Never seemed to matter
It's all inside your head

Names are only letters
Mentioned on a stone
And If you're going somewhere
You're going it alone

Then I saw you
Something new inside of me
What's this shakin'
You made me shiver

Magic charms and voodoo
And all those other spells
Didn't make impressions
I never slept so well

If I had a nightmare
I'm sure that I would know
I really don't remember
But I'm sure it isn't so

Then I saw you
Something new inside of me
What's this shakin'

Turn out the lights it won't matter
A bucket of blood and I'm still fine
A black cat's only a color
But you can do it any time
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

const int N = 610031;

int tests,n,m,ui[N],uj[N];
int board[53][53];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  for (int i=1;i<=n;i++){
		  ui[i]=0;
	  }
	  for (int j=1;j<=m;j++){
		  uj[j]=0;
	  }

	  for (int i=1;i<=n;i++){
		  for (int j=1;j<=m;j++){
			  cin>>board[i][j];
			  if (board[i][j]==1){
				  ui[i]=1;
				  uj[j]=1;
			  }
		  }
	  }

	  int c1=0;
	  int c2=0;
	  for (int i=1;i<=n;i++){
		  if (ui[i]==0)
			  c1++;
	  }
	  for (int j=1;j<=m;j++){
		  if (uj[j]==0)
			  c2++;
	  }
	  c1=min(c1,c2);
	  if (c1%2)
		  cout<<"Ashish"<<endl;
	  else
		  cout<<"Vivek"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}