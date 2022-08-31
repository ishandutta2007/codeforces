/*
Dying swans twisted wings, beauty not needed here
Lost my love, lost my life, in this garden of fear
I have seen many things, in a lifetime alone
Mother love is no more, bring this savage back home

Wilderness house of pain, makes no sense of it all
Close this mind dull this brain, Messiah before his fall
What you see is not real, those who know will not tell
All is lost sold your souls to this brave new world

A brave new world, in a brave new world
A brave new world, in a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

Dragon kings dying queens, where is salvation now
Lost my life lost my dreams, rip the bones from my flesh
Silent screams laughing here, dying to tell you the truth
You are planned and you are damned in this brave new world

A brave new world, in a brave new world
A brave new world, in a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

A brave new world, in a brave new world
A brave new world, in a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

Dying swans twisted wings, bring this savage back home
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m,k;
pair<int,int> start,finish;
char board[200][200];
vector<pair<int,int> > order;
string prog;

int ans;

bool outside(int a,int b){
	return (a<1||a>n||b<1||b>m);
}

bool valid(){
	pair<int,int> cur=start;
	for (int i=0;i<prog.size();i++){
		int d=prog[i]-'0';
		cur.first+=order[d].first;
		cur.second+=order[d].second;
		if (outside(cur.first,cur.second))
			return false;
		if (board[cur.first][cur.second]=='#')
			return false;
		if (cur==finish)
			return true;
	}
	return false;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		string st;
		cin>>st;
		for (int j=1;j<=m;j++){
			board[i][j]=st[j-1];
			if (board[i][j]=='S')
				start=make_pair(i,j);
			if (board[i][j]=='E')
				finish=make_pair(i,j);
		}
	}

	cin>>prog;

	order.push_back(make_pair(-1,0));
	order.push_back(make_pair(1,0));
	order.push_back(make_pair(0,-1));
	order.push_back(make_pair(0,1));
	sort(order.begin(),order.end());
	do
	{
		if (valid())
			++ans;
	}
	while (next_permutation(order.begin(),order.end()));

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}