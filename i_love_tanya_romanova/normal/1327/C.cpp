/*
Murder, drugs, cash, and greed
It touches everyone and everything
Within the walls there's no escaping the disease
Sidwalks turn to pharmacies
All the pimps and pushers territories
Dollars pouring in from the victims trapped within
Schoolyard's a place of sorrow
Pray your children live to see tomorrow
A place where mothers cry, and kiss their dying sons goodbye
Living in a state of fear
Afraid of everything they see or hear
Someone they love may get shot
For drugs they never even bought!

Violence is a way of life
Revenge delivered with a gun or knife
Paybacks are a bitch
They'll leave you dying in a ditch
Caught in the hypnotic spell
Their life's story they'll never life to tell
In a hazy curtain, they can't see the end is certain
Imprisoned by narcotic chains
Life for some will never be the same
Trapped in walls of glass
Hoping that this all will pass
But some will find their way outside
Face the evil, eyes open wide
Break the bonds that pull you in
Escape the hell that thrives...

Within the walls
Of chaos and despair
Most are unemployed
Living on welfare
Prowling the halls
The vultures come to feed
On the flesh of those
Who are enslaved to the need
The final curtain falls
And no one sheds a fear
Their pleas for help always seem to fall
Upon deaf ears
Within the walls of chaos they forgot
That dignity and sanity
Are things that can't be bought

With every passing day
Another life is cast astray
Wear the wrong colors
And you might get blown away

Turn of a page
Another name's crossed off the list
Shot between the eyes
With a rig clenched in his fist

Driven to the grave
Ruled by need for kicks
Extract their own gold teeth
To satisfy their fix

There's cracks in the foundation
The time will soon arrive
When the walls will crumble down
And bury everyone alive!

Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos!
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

const int N = 300031;

int n,m,k;
vector<string> ans;

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m>>k;
  for (int i=1;i<=m;i++){
	  if (i%2){
		  for (int j=2;j<=n;j++){
			  ans.push_back("D");
		  }
	  }
	  else
	  {
		  for (int j=n-1;j>=1;--j){
			  ans.push_back("U");
		  }
	  }
	 if (i<m)
		 ans.push_back("R");
  }

  int sz=ans.size();
  for (int i=sz-1;i>=0;--i){
	  if (ans[i]=="U")
		  ans.push_back("D");
	  if (ans[i]=="D")
		  ans.push_back("U");
	  if (ans[i]=="R")
		  ans.push_back("L");
  }

  cout<<ans.size()<<endl;
  for (int i=0;i<ans.size();i++){
	  cout<<ans[i];
  }
  cout<<endl;

  //    cin.get(); cin.get();
  return 0;
}