/*
Oh Jane can you wait
I'm coming home, bit I'm running late
Just playing one more town
You know I miss you and I want you around
Oh Jane I'm alone
On the road but I'm coming home
I feel your love in my heart
And I hope that we will never part

Wish I was home to hold you tight
My hotel room is empty tonight
I want you with me let's make it a date
Oh Jane can you wait

Oh Jane can you wait
You give me love you don't hesitate
You worry that I'll stray
Never trust me when I'm away
Oh Jane stay with me
You know I want you that's the way it will be
I've told you I love you
Home or away I will always be true
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

const int N = 1200031;

int tests;
int n,m;
vector<vector<char> > board;
vector<vector<int> > used;
vector<vector<char> > colored;
pair<int,int> cycle_start;
int cycle_len;
vector<pair<int,int> > qu_list;

void trace(int a,int b){
	qu_list.push_back(make_pair(a,b));
	int na=a;
	int nb=b;
	if (board[a][b]=='U')
		--na;
	if (board[a][b]=='R')
		++nb;
	if (board[a][b]=='D')
		++na;
	if (board[a][b]=='L')
		--nb;
	if (used[na][nb]){
		cycle_start=make_pair(na,nb);
		cycle_len=used[a][b]-used[na][nb]+1;
		return;
	}
	used[na][nb]=used[a][b]+1;
	trace(na,nb);
}

int ans1,ans2;
int have_black[N];

pair<int,int> get_move(int a,int b){
	if (board[a][b]=='U')
		return make_pair(a-1,b);
	if (board[a][b]=='R')
		return make_pair(a,b+1);
	if (board[a][b]=='D')
		return make_pair(a+1,b);
	return make_pair(a,b-1);
}

void fill_in(int a,int b,int rem){
	//cout<<a<<" "<<b<<" "<<rem<<" "<<colored[a][b]<<endl;
	used[a][b]=1;
	if (colored[a][b]=='0')
		have_black[rem]=1;

	pair<int,int> togo=get_move(a,b);
	if (used[togo.first][togo.second]==0)
	{
		fill_in(togo.first,togo.second,(rem+1)%cycle_len);
	}

	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			if (abs(dx)+abs(dy)!=1)
				continue;
			if (a+dx<0||a+dx>=n||b+dy<0||b+dy>=m)
				continue;
			if (used[a+dx][b+dy])
				continue;
			//cout<<n<<" "<<m<<" "<<a+dx<<" "<<b+dy<<" "<<get_move(a+dx,b+dy).first<<" "<<get_move(a+dx,b+dy).second<<endl;
			pair<int,int> p=get_move(a+dx,b+dy);
			if (p.first==a&&p.second==b){
				fill_in(a+dx,b+dy,(rem+cycle_len-1)%cycle_len);
			}
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
	  board.resize(n);
	  used.resize(n);
	  colored.resize(n);
	  for (int i=0;i<n;i++){
		  board[i].resize(m);
		  used[i].resize(m);
		  colored[i].resize(m);
		  string labels;
		  cin>>labels;
		  for (int j=0;j<m;j++){
			  used[i][j]=0;
			  colored[i][j]=labels[j];
		  }
	  }
	  for (int i=0;i<n;i++){
		  string st;
		  cin>>st;
		  for (int j=0;j<m;j++){
			  board[i][j]=st[j];
		  }
	  }

	  ans1=ans2=0;
	  for (int i=0;i<n;i++){
		  for (int j=0;j<m;j++){
			  if (used[i][j])
				  continue;
			  used[i][j]=1;
			  qu_list.clear();
			  trace(i,j);
			  for (int q=0;q<cycle_len;q++){
				  have_black[q]=0;
			  }
			  for (int q=0;q<qu_list.size();q++){
				  int a=qu_list[q].first;
				  int b=qu_list[q].second;
				  used[a][b]=0;
			  }
			  fill_in(cycle_start.first,cycle_start.second,0);
			  ans1+=cycle_len;
			  for (int q=0;q<cycle_len;q++){
				  if (have_black[q])
					  ans2++;
			  }
//			  cout<<cycle_start.first<<" "<<cycle_start.second<<" "<<cycle_len<<endl;
		  }
	  }

	  cout<<ans1<<" "<<ans2<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}