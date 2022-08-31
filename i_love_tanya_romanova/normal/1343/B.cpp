/*
Nailed to a pleasant sleep
Under the fullmoon light
Calculated ancient knowledge
Of Arab's wise words

I dreamed about a temple
I saw it in my dreams
A temple made of silver
With emeralds above

It is in the wood
Spoken by animal lips
My seal and my epitaph
It is the Sumerian Cry

I visited the temple
In my imaginations it welcomed my
I tried to understand the language
And the sumerian cuneiform

I read about their gods
And in my dreams they spoke to me
They showed me the tablets of fate
Which since a battle belong to them

It is in the wood
Spoken by animal lips
My seal and my epitaph
It is the Sumerian Cry

Then I saw the Ancient Ones
Slumbering in their cave
My dreams and my nightmares
The liers in wait bred my fear

I woke up from my dreams
The night had become day
Highly strung, rigid and struck
I peered through the morning fog

It is in the wood
Spoken by animal lips
My seal and my epitaph
It is the Sumerian Cry
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

const int N = 100031;

int tests,n;
vector<int> ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  if (n%4==2){
		  cout<<"NO"<<endl;
		  continue;
	  }
	  ans.clear();
	  for (int i=1;i<=n/2;i++){
		  ans.push_back(i*8);
	  }
	  for (int i=1;i<=n/2;i++){
		  if (i%2==1)
			  ans.push_back(i*8+1);
		  else
			  ans.push_back(i*8-1);
	  }
	  cout<<"YES"<<endl;
	  for (int i=0;i<ans.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<ans[i];
	  }
	  cout<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}