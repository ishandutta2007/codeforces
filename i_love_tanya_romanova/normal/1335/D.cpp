/*
What happened to all the great leaders
The ideals that they believed
They have all died and perished
With ideas that they conceived

What happened to the great war hero
The cause for what he fought
His medals were tarnished in Vietnam
His honour we forgot

No one to follow
No one to lead the way
No one to follow
Nothing is here to stay

What happened to trust and faith
For all the good they do
Corrupt church and child abuse
Have both obscured our view

Inconclusive
So illusive
In confusion
disolutioned

No one to follow
Nothing is here to stay

What happened to the laws of the land
Justice for all
Corner stones are broken
Civilization will fall

Inconclusive
So illusive
In confusion
disolutioned

No one to follow
No one to follow
No one to follow
No one to lead the way
No one to follow
Nothing is here to stay
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

const int N = 200031;

int tests;
int board[20][20];

void paint(int a,int b){
	board[a][b]++;
	if (board[a][b]==10)
		board[a][b]=1;
}


int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  for (int i=1;i<=9;i++){
		  string st;
		  cin>>st;
		  for (int j=1;j<=9;j++){
			  board[i][j]=st[j-1]-'0';
		  }
	  }

	  paint(1,1);
	  paint(2,5);
	  paint(3,9);
	  paint(4,2);
	  paint(5,6);
	  paint(6,7);
	  paint(7,3);
	  paint(8,4);
	  paint(9,8);

	  for (int i=1;i<=9;i++){
		  for (int j=1;j<=9;j++){
			  cout<<board[i][j];
		  }
		  cout<<endl;
	  }
  }

  // cin.get(); cin.get();
  return 0;
}