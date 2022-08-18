/*
Getting edgy all the time
Someone around me just a step behind
It's kinda scary, the shape I'm in
The walls are shakin' and they're closing in

Too fast or a bit too slow
Paranoid of people and it's starting to show
One guy that I can't shake
Over my shoulder is a big mistake

Sitting on the bed
Or lying wide awake
There's demons in my head
And it's more than I can take
I think I'm on a roll
But I think it's kinda weak
Saying all I know is
I gotta get away from me

I tell you something just ain't right
My head is on loose but my shoes are tight
Avoiding my friends 'cause they all bug
Life is like a riddle and I'm really stumped

If you reason, don't you know
Your own preoccupation is where you'll go
I think I'm being followed, I look around
It's only my shadow creepin' on the ground

Sitting on the bed
Or lying wide awake
There's demons in my head
And it's more than I can take
I think I'm on a roll
But I think it's kinda weak
Saying all I know is
I gotta get away from me
Gotta get away from me
Gotta get away from me

Sitting on the bed
Or lying wide awake
There's demons in my head
And it's more than I can take
I think I'm on a roll
But I think it's kinda weak
Saying all I know is
I gotta get away from me
Gotta get away from me
Gotta get away from me
Gotta get away from me
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

int tests,n,m;
int used[55][55];
char board[55][55];

bool outside(int a,int b){
	return (a<1||a>n||b<1||b>m);
}

bool invalid(int a,int b){
	if (outside(a,b))
		return false;
	return (board[a][b]=='B');
}

bool is_bad(int a,int b){
	if (board[a][b]=='#')
		return true;
	return invalid(a,b)||invalid(a,b-1)||invalid(a,b+1)||invalid(a-1,b)||invalid(a+1,b);
}

void dfs(int a,int b){
	used[a][b]=1;
	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (outside(a+dx,b+dy))
				continue;
			if (used[a+dx][b+dy])
				continue;
			if (is_bad(a+dx,b+dy))
				continue;
			dfs(a+dx,b+dy);
		}
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  for (int i=1;i<=n;i++){
		  string st;
		  cin>>st;
		  for (int j=1;j<=m;j++){
			  board[i][j]=st[j-1];
		  }
	  }

	  for (int i=1;i<=n;i++){
		  for (int j=1;j<=m;j++){
			  used[i][j]=0;
		  }
	  }

	  if (board[n][m]!='B'&&is_bad(n,m)==0)
		  dfs(n,m);

	  int 	ok=1;

	  for (int i=1;i<=n;i++){
		  for (int j=1;j<=m;j++){
			  if (board[i][j]=='G'&&used[i][j]==0)
				  ok=0;
		  }
	  }

	  if (ok)
		  cout<<"Yes"<<endl;
	  else
		  cout<<"No"<<endl;

  }
  cin.get(); cin.get();
  return 0;
}