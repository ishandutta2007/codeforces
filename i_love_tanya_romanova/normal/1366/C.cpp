/*
Fed up and fucked up
Born from war and tension
Fed up and fucked up
Cut-throat generation

Fed up and fucked up
Throw down the fallen nations
Fed up and fucked up
Burn down retaliation
Fed up and fucked up
See you fall from grace
Fed up and fucked up
Scars on your two faces

Bloodbrawl - now you're falling down
Bloodcloth - it's your downfall
Bloodcloth - now you're falling down
Bloodbrawl...

Bloodbrawl, bloodcloth, bloodcloth, bloodbrawl

Born from war and tension
Fed up and fucked up
Feeding on frustration
Fed up and fucked up
Unleash devastation
Fed up and fucked up
Spell out your redemption
Fed up and fucked up

Bloodbrawl - now you're falling down
Bloodcloth - it's your downfall
Bloodcloth - now you're falling down
Bloodbrawl...

Bloodbrawl, bloodcloth, bloodcloth, bloodbrawl
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

int tests,board[100][100];
int n,m;
int c1[500][3],c2[500][3];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  for (int i=1;i<=n;i++){
		  for (int j=1;j<=m;j++){
			  cin>>board[i][j];
		  }
	  }

	  for (int i=0;i<=200;i++){
		  for (int j=0;j<=2;j++){
			  c1[i][j]=c2[i][j]=0;
		  }
	  }

	  for (int i=1;i<=n;i++){
		  for (int j=1;j<=m;j++){
			  int d1=i+j-2;
			  int d2=n-i+m-j;
			  if (d1==d2)
				  continue;
			  c1[d1][board[i][j]]++;
			  c2[d2][board[i][j]]++;
		  }
	  }
	  int ans=0;
	  for (int i=0;i<=200;i++){
		  ans+=min(c1[i][0]+c2[i][0],c1[i][1]+c2[i][1]);
	  }
	  cout<<ans/2<<endl;
  }
  cin.get(); cin.get();
  return 0;
}