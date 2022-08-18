/*
Bred from the bowels
Sheep one and all
Bound by the doctrine of lies
To fucked human shit, I shout blasphemy!
As I make my way thru to
The promised land

Smell of shit is so foul
Writhe in disgust
Earth heaves and death comes to call
All the waste - Cling to your lie
You are as sand and the wind blows
My disgust - A fever
To kill a thousand more

Gene dead from birth
God's holy fuck
Canonized but of no use to me
Human shit, untermensch waste begone from my earth!

Desolation - No life bodies littering
Beast of earth devour!
Cleanse this world for those who deserve

Burning cities, all is well
I remain in my conviction
As the waste in sewer flows thru the promised land
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

int n,m;
char board[2031][2031];
string st;
int ans[2031][2031];
vector<pair<int,int> > painted,new_painted;

bool is_1(int a,int b){
	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (board[a+dx][b+dy]!=board[a][b])
				return true;
		}
	}
	return false;
}

bool outside(int x,int y){
	return (x<1||x>n||y<1||y>m);
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m;
  for(int i=0;i<=n+1;i++){
	  for (int j=0;j<=m+1;j++){
		  board[i][j]='-';
	  }
  }

  for (int i=1;i<=n;i++){
	  cin>>st;
	  for (int j=1;j<=m;j++){
		  board[i][j]=st[j-1];
	  }
  }

  for (int i=1;i<=n;i++){
	  for (int j=1;j<=m;j++){
		  if (is_1(i,j)){
			  ans[i][j]=1;
			  painted.push_back(make_pair(i,j));
		  }
	  }
  }

  while (painted.size()){
	  new_painted.clear();
	  for (int i=0;i<painted.size();i++){
		  pair<int,int> v=painted[i];
		  int x,y;
		  x=v.first;
		  y=v.second;
		  for (int dx=-1;dx<=1;dx++){
			  for (int dy=-1;dy<=1;dy++){
				  if (outside(x+dx,y+dy))
					  continue;
				  if (ans[x+dx][y+dy])
					  continue;
				  if (abs(dx)+abs(dy)!=1)
					  continue;
				  new_painted.push_back(make_pair(x+dx,y+dy));
				  ans[x+dx][y+dy]=ans[x][y]+1;
			  }
		  }
	  }
	  painted=new_painted;
  }

  long long answ=0;

  for (int i=1;i<=n;i++){
	  for (int j=1;j<=m;j++){
	//	  cout<<ans[i][j];
		  answ+=ans[i][j];
	  }
	//  cout<<endl;
  }

  cout<<answ<<endl;

  cin.get(); cin.get();
  return 0;
}