/*
Two face woman with your two face lies
I hope your two face livin's made you satisfied
Told me baby I'm was you're only one
While ya been runnin' round town with every mothers son

Two times told about a woman like you
Two times told about the things you do
I used to think that you were sugar and spice
I should have listened to my ma's advice

Kicked in the teeth again
Sometimes you lose sometimes you win
Kicked in the teeth again
Ain't this misery ever gonna end
And I been kicked in the teeth
Kicked in the teeth again

Two face woman such a cryin' shame
Double or nothin' you're all the same
You run around hope you had your fun
You never know who's gonna win
Til' the race been
Run

Kicked in the teeth again
Sometimes you lose sometimes you win
Kicked in the teeth again
Ain't this misery ever gonna end
I been kicked in the teeth
Kicked in the teeth
Kicked in the teeth again
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

const int N = 210031;

int n,ar[N];
int ans;
int cur_min,cur_s;
int in_block,S[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  S[i]=S[i-1]+ar[i];
  }

  ans=-1e9;

  for (int mx=-30;mx<=30;mx++){

	  cur_min=1e9;
	  in_block=0;

	  for (int i=1;i<=n;i++){
		  if (ar[i]>mx){
			  cur_min=1e9;
			  in_block=1e9;
		  }
		  else if (ar[i]==mx){
			  cur_min=min(cur_min,in_block);
			  in_block=S[i];
		  }
		  else
		  {
			  in_block=min(in_block,S[i]);
		  }
		    if (in_block<1e8)
			  ans=max(ans,S[i]-cur_min-mx);
	  }

  }
  cout<<ans<<endl;

  // cin.get(); cin.get();
  return 0;
}