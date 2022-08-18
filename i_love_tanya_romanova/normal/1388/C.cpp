/*
You can never truly see
Inside the ones you know
Until youve found them near
The edge of self control

All I hear are lies
You're lying to yourself
And everything is out of control

You're just a fuckin' slave of discontent
I'm sick of watching you dig this hole

Time waits - for no one
Won't stop - It can't be outrun
You know - That pain in your head
Won't stop 'til the desperation ends

You've found yourself chasing death
Oblivious until the end
You'll never stop chasing death

Innocence, common sense, I don't see the relevance
Of anything that you've got to say
Parasite, socialite, you're never gonna win this fight
There is no fucking easy way out
No easy way out

I know I should have seen it all coming
But I had to find it out on my own
A whore to incompetence you hide behind
The shadow that once was your thrown
Control is a discipline even when
Frustration just stands in your way
The throes of insanity feel just like
A war inside you everyday

I know I should have seen it all coming
But I had to find it out on my own
A whore to incompetence you hide behind
The shadow that once was your thrown
Control is a discipline even when
Frustration just stands in your way
The throes of insanity feel just like
A war inside you everyday

Time waits - for no one
Won't stop - It can't be outrun
There's just - no way of knowing
How long - paranoia's growing
Cant stop the poison winning
Please - Just take away this feeling
You know - that pain in your head
Won't stop until the desperation ends

You've found yourself chasing death
Oblivious until the end
You'll never stop until you're dead

Innocence, common sense, I don't see the relevance
Of anything that you've got to say
Parasite, socialite, you're never gonna win the fight
There is no fucking easy way out
No easy way out
No easy way out
No easy way out
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

int tests,n,m;
int p[N];
int h[N];
vector<int> g[N];
int count_good[N];
int count_bad[N];
int shit;

int parity(int x){
	return abs(x)%2;
}

void solve(int v,int par=-1){
	int good_in_sons=0;
	int bad_in_sons=0;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (to==par)
			continue;
		solve(to,v);
		good_in_sons+=count_good[to];
		bad_in_sons+=count_bad[to];
	}
	int all_good=good_in_sons;
	int all_bad=bad_in_sons+p[v];
	int current_h=all_good-all_bad;
	if (parity(current_h)!=parity(h[v])){
		shit=1;
		return;
	}
	int must_convert=h[v]-current_h;
	must_convert/=2;
	//cout<<v<<"@@"<<must_convert<<" "<<all_good<< ""<<all_bad<<endl;
	if (must_convert<0)
	{
		shit=1;
		return ;
	}
	if (must_convert>all_bad){
		shit=1;
		return ;
	}
	all_good+=must_convert;
	all_bad-=must_convert;
	count_good[v]=all_good;
	count_bad[v]=all_bad;
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  for (int i=1;i<=n;i++)
		  cin>>p[i];
	  for (int i=1;i<=n;i++){
		  cin>>h[i];
	  }
	  for (int i=1;i<=n;i++){
		  g[i].clear();
	  }
	  for (int i=1;i<n;i++){
		  int a,b;
		  cin>>a>>b;
		  g[a].push_back(b);
		  g[b].push_back(a);
	  }

	  shit=0;

	  solve(1);

	  for (int i=1;i<=n;i++){
		//  cout<<count_good[i]<<" "<<count_bad[i]<<endl;
	  }

	  if (shit)
		  cout<<"NO"<<endl;
	  else
		  cout<<"YES"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}