/*
Look at all the freaks!
Lined up head to head
They wait for out arrival
Some are here for the show
Some are here to watch
And some to preach the bible
Hats off to the faithful
That come to waltz with us
They're doing what they wanna
Come on to the next show
Parade along with us
You won't be forgotten
You won't be forgotten

Listen to the freak show
Shouting to our songs
They sound like charging rhino
A place to meet an old friend
A place to meet some new
You can always follow
You wanna meet the clowns
When the circus comes to town?
Gather all around!
We'll remember all of you
Unless our crew dismembers you!

Come in from hell or wherever you came
Slums of the world are to us all the same
Step up and join us now and don't be afraid
Our party's starting to become a charade!
Lunatics everywhere will all act the same
And when the sideshow starts there's no one to blame
There's no one left, the town is having a raid
They all have joined us in our lunatic parade!

You wanna meet the clowns
When the circus comes to town?
Gather all around!
Come on to the next show
Parade along with us
You won't be forgotten!
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

int tests,n,used[N];
vector<int> unmarried;

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  used[i]=0;
	  }
	  unmarried.clear();
	  for (int i=1;i<=n;i++){
		  int cnt;
		  cin>>cnt;
		  bool married=0;
		  for (int j=1;j<=cnt;j++){
			  int id;
			  cin>>id;
			  if (used[id]==0&&married==0){
				  married=1;
				  used[id]=1;
			  }
		  }
		  if (!married)
			  unmarried.push_back(i);
	  }

	  if (unmarried.size()==0){
		  cout<<"OPTIMAL"<<endl;
	  }
	  else
	  {
		  cout<<"IMPROVE"<<endl;
		  cout<<unmarried[0]<<" ";
		  for (int i=1;i<=n;i++){
			  if (used[i]==0){
				 cout<<i<<endl;
				 cout<<endl;
				 break;
			  }
		  }
	  }
  }

  //    cin.get(); cin.get();
  return 0;
}