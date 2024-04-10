/*
Yeah!
Grown from a seed of hope I've never known
Been raised by the surroundings of a home so cold, so cold
If I only knew what I know

I'll shake my fist up to the sky
Just keeping my dreams alive
I'm one part saint and two part sinner,
And the last part is still on the line

We pray even when we know nobody cares, ah ya
And make everything we know turn into fear
And then disappear
If I only knew what I know

I'll shake my fist up to the sky
Just keeping my dreams alive
I'm one part saint and two part sinner,
And the last part is still on the line

I'll shake my fist up to the sky
Just keeping my dreams alive
Im one part saint and two part sinner,
And the last part is still on the line
Ya... Ya... Ya...
Eye for an eye they told me for some time
No way to hide from what's inside, what's inside of me!

I'll shake my fist up to the sky
Just keeping my dreams alive
I'm one part saint and two part sinner,
And the last part is still on the line

I'll shake my fist up to the sky
Just keeping my dreams alive
Im one part saint and two part sinner,
And the last part is still on the line
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

const int N = 500031;

int tests,n,xor_all,ar[N];
int cnt_with,cnt_without;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  xor_all=0;
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
		  xor_all^=ar[i];
	  }
	  if (xor_all==0)
	  {
		  cout<<"DRAW"<<endl;
		  continue;
	  }
	  int ps=30;
	  while (!(xor_all&(1<<ps)))
		  --ps;

	  int cnt_with=0;
	  int cnt_without=0;
	  for (int i=1;i<=n;i++){
		  if(ar[i]&(1<<ps))
			  cnt_with++;
		  else
			  cnt_without++;
	  }
	  // cnt with is definitely odd

	  if (n%2==1){ // cnt without %2==0
		  if (cnt_with%4==1)
			  cout<<"WIN"<<endl;
		  else
			  cout<<"LOSE"<<endl;
	  }
	  else // cnt without %2 ==1
	  {
		  if (cnt_with%4==1)
			  cout<<"WIN"<<endl;
		  else
			  cout<<"WIN"<<endl;
	  }

  }
  cin.get(); cin.get();
  return 0;
}