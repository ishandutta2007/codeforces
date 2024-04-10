/*
I wanna be there when you call
I wanna catch you when you fall
I wanna be the one you need
I wanna be the one you breathe

Todays the day well fade away, oh
Todays the day well fade away, oh
Todays the day well find our way grown
Todays the day well fade away

I wanna be there when you cry
And when youre down Ill help you fly
I wanna be the one you need
I wanna be the one you breathe

Todays the day well fade away, oh
Todays the day well fade away, oh
Todays the day well find our way grown
Todays the day well fade away, oh

But Im coming back,
and Im taking back everything I can
Its breaking me up and tearing me up
Its all I have
And Im coming back,
and Im taking back everything I can
Its breaking me up and tearing me up
Its all I have

Todays the day well fade away, oh
Todays the day well fade away, oh
Todays the day well find our way grown
Todays the day well fade away, oh
Todays the day well fade away, oh
Todays the day well fade away
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

const int N = 110031;

int tests,n,m;
string ans;
string st[N];

int cd(string a,string b){
	int ret=0;
	for (int i=0;i<a.size();i++){
		if (a[i]!=b[i])
			++ret;
	}
	return ret;
}

bool good(string s){
	for (int i=1;i<=n;i++){
		if (cd(s,st[i])>1)
			return false;
	}
	return true;
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
		  cin>>st[i];
	  }
	  ans="-1";

	  for (int i=1;i<=n;i++){
		  for (int j=0;j<st[i].size();j++){
			  for (int q='a';q<='z';q++){
				  string temp=st[i];
				  temp[j]=q;
				  if (good(temp))
					 ans=temp;
			  }
		  }
	  }
	  cout<<ans<<endl;

  }
  // cin.get(); cin.get();
  return 0;
}