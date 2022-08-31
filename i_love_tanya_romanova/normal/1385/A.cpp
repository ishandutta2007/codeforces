/*
Yeah! The way I feel, seems to me to be so real
So sick and tired you know just how I feel
Cops they dress in black, they bid their lives
The bribes they stack, so sick and tired
Of the same old this and that
The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel!

The man I most resent
You might know him through the government
He'll tax our lives the money's spent
He's just the president!!!
The land of liberty for all mankind and all to see
What's the use, laws a conspiracy
The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel!

Searching for answers to make life complete
No need to search for more questions
There for you to see!

The wars that we must fight
You dodge the draft before you drive
So sick and tired, why can't they realise
The rights they sympathise
So sick and tried, why can't we live our lives
The time is coming, it's too soon I can't quite tell
I don't know, I think my world has gone to hell
The time is coming, life it spins just like a wheel
I don't know, that's the way that it makes me feel!
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

int tests,x,y,z;
vector<int> v;
int found;
int a,b,c;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
		 v.clear();
		  cin>>x>>y>>z;
		  v.push_back(x);
		  v.push_back(y);
		  v.push_back(z);
		  v.push_back(1);

		  found=0;

		  for (int i=0;i<v.size();i++){
			  for (int j=0;j<v.size();j++){
				  for (int q=0;q<v.size();q++){
					  if (max(v[i],v[j])==x&&max(v[i],v[q])==y&&max(v[j],v[q])==z){
						  found=1;
						  a=v[i];
						  b=v[j];
						  c=v[q];
					  }
				  }
			  }
		  }
		  if (!found){
			  cout<<"NO"<<endl;
		  }
		  else
		  {
			  cout<<"YES"<<endl;
			  cout<<a<<" "<<b<<" "<<c<<endl;
		  }
  }

  cin.get(); cin.get();
  return 0;
}