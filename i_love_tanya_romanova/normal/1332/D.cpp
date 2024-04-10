/*
Devoid of life
Far from the strengthening force
From which it feeds
The unbroken silence swear allegiance to thee
Behold the answers that darkness sets free

Freedom beyond the enslavement

Never let loose upon the world
Con we forgive the enchanter that
Dance beyond the skyline dark
The stains of fire, the one begotten ancestor
To one of far greater strength
Starvation divine

For he shall stand no taller than the flames
That is his feed
Let us not go gently
Into the endless winternight
We are but strangers
Acting on our fragmentary perception

Perception is the lie of the misled
Things are not what they appear
So swear by your deception

There shan't be fire, nor shall the flame
Quench the desire to reign
With fear of its dawning
Appears now in sight
The one brooding warning
Stand clearer than night

Devoid of life
Far from the strengthening force
From which it feeds
The unbroken silence swear allegiance to thee
Behold the answers that darkness sets free

Freedom beyond the enslavement
Never let loose upon the world
Con we forgive the enchanter that
Dance beyond the skyline dark

There shan't be fire, nor shall the flame
Quench the desire to reign
With fear of its dawning
Appears now in sight
The one brooding warning
Stand clearer than night
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

#define bs 998244353

const int N = 600031;

int k;
int dp[10][10];
int board[10][10];

int naive_dp(){
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			if (i==1&&j==1){
				dp[i][j]=board[i][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j]&board[i][j],dp[i][j-1]&board[i][j]);
			}
		}
	}
	return dp[4][4];
}
int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>k;

  int F=(1<<18)-1;

  for (int i=1;i<=4;i++){
	  for (int j=1;j<=4;j++){
		  if (i==1&&j==4||i==4&&j==4)
			  board[i][j]=k;
		  else
			  board[i][j]=F-k;
	  }
  }

  board[1][1]=F;

  board[1][2]=board[1][3]=board[2][4]=board[3][4]=k;

  board[3][4]=F;

  //cout<<naive_dp()<<endl;

  cout<<4<<" "<<4<<endl;
  for (int i=1;i<=4;i++){
	  for (int j=1;j<=4;j++){
		  if (j>1)
			  cout<<" ";
		  cout<<board[i][j];
	  }
	  cout<<endl;
  }

  //    cin.get(); cin.get();
  return 0;
}