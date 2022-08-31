/*
What a big man you are
Could fight a war with just your face
Take it on the chin and leave me open-jawed.

What big words you've got,
Reciting lines you've heard on film,
Could write a script with just your lust for respect.

Rip off this face, it can't persist,
Like shadows in the rain, undefined lines,
A symphony muted and greying.
You're not real, and neither are your goals.

Your goals:
Exposed and fruitless,
Suspended from a childhood insecurity,
Perpetuated beyond the boundaries of logic and reality.
Many times i held my hand out to you,
When it should have been me was destructive.
In my own rights i should have been..

I had hoped somewhere that through your clouded portrait of rage
I could eventually count on human nature to rear its head
And shine over the darkness that we had created for ourselves.
And human nature did shine through,
but I never realized that human nature was truly so jealous and vile.

That is the nature of men,
The very man you strive to be,
And you will succeed.
Stretch up to your pain as long as it may carry you,
Until your body becomes consumed and decayed by the ravages of time.

For one day it will forever change your mask,
And you will be carved in stone...
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
string st;
string found;

string Z="abacaba";

string try_solve(string st,int ps){
	for (int i=0;i<st.size();i++){
		if (i<ps){
			if (st[i]=='?')
				st[i]='d';
			continue;
		}
		if (i>=ps+7){
			if (st[i]=='?')
				st[i]='d';
			continue;
		}
		if (st[i]=='?')
			st[i]=Z[i-ps];
	}
	return st;
}

int c_sub(string st){
	int ret=0;
	for (int i=0;i+7<=st.size();i++){
		int ok=1;
		for (int j=0;j<7;j++){
			if (Z[j]!=st[i+j]){
				ok=0;break;}
		}
		if (ok)
			++ret;
	}
	return ret;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  int trash;cin>>trash;
	 cin>>st;
	 found="";
	 for (int i=0;i+7<=st.size();i++){
		 string temp=try_solve(st,i);
		 if (c_sub(temp)==1)
			 found=temp;
		 if (found.size())
			 break;
	 }
	 if (found.size())
		 cout<<"Yes"<<endl<<found<<endl;
	 else
		 cout<<"No"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}