/*
Cesspool in orbit, our end has begun
We live on the third lump of shit from the sun
Planet in peril, but why give a fuck
Soon the earth will run out of luck
Wreck it all until the land is stripped
Rejoice in the coming apocalypse
Sing loud the world's last lullaby
But my replies

Good riddance, goodbye
So long to this fucking world, sit back and watch it fry
Good riddance, goodnight
Adios planet earth, now die

Parasitic infestation, never ending procreation
Our shit stained constellation headed for its cancellation
Eternity of desecration, another misread calculation
Give the earth one last ovation before it starts the final
Crash and burn

Get down to business, cut to the chase
It's time for mankind's fall from grace
The end's coming sooner than you'll ever know
So sit back, relax and enjoy the show
No time to cry, I won't shed a tear
This is, after all the event of the year
We can save the world
You testify, but my replies

Good riddance, goodbye
So long to this fucking world, sit back and watch it fry
Good riddance, goodnight
Adios planet earth, now die
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

int pr[N];
vector<int> primes;
int ptr;
int n;
int count_of_queries;
vector<int> ans;

void answer_it(int val){
	++count_of_queries;
	cout<<"C "<<val<<endl;
}

int used[N];
int x;

int LOCAL = 1;

int query_B(int val){
	++count_of_queries;
	cout<<"B "<<val<<endl;
	if (LOCAL){
		int ret=0;
		for (int i=val;i<=n;i+=val){
			if (used[i]==0)
				++ret;
			if (used[i]==0&&i!=x)
				used[i]=1;
		}
		return ret;
	}
	else
	{
		int ret;
		cin>>ret;
		return ret;
	}
}

int query_A(int val){
	++count_of_queries;
	cout<<"A "<<val<<endl;
	if (LOCAL){
		int ret=0;
		for (int i=val;i<=n;i+=val){
			if (used[i]==0)
				ret++;
		}
		return ret;
	}
	else
	{
		int ret;
		cin>>ret;
		return ret;
	}
}

void find_it(int l,int r){
	for (int i=l;i<=r;i++){
		int here=query_B(primes[i]);
		if(here==1)
			ans.push_back(primes[i]);
	}
}

int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  //ios_base::sync_with_stdio(0);
  // cin.tie(0);

  LOCAL=0;

  pr[1]=1;
  cin>>n;
  if (LOCAL){
	  cin>>x;
  }

  if (n==1){
	  answer_it(1);
	  return 0;
  }

  for (int i=2;i<=n;i++){
	  if (pr[i]==0){
		  for (int j=i*2;j<=n;j+=i){
			  pr[j]=1;
		  }
	  }
  }

  for (int i=2;i<=n;i++){
	  if (pr[i]==0){
		  primes.push_back(i);
	  }
  }

  ptr=-1;

  for (int i=0;i<primes.size();i++){
	  if (1ll*primes[i]*primes[i]>n)
		  continue;
	  ptr=i;
	  int val1=query_B(primes[i]);
	  int val2=query_B(primes[i]);
	  if (val2>0)
		  ans.push_back(primes[i]);
  }

  int before=query_A(1);

  int should_remove=0;

  for (int i=ptr+1;i<primes.size();i++){
	int here=query_B(primes[i]);
	should_remove+=here;
	if (should_remove>=100){
		int now=query_A(1);
		if (now!=before-should_remove){
			find_it(ptr+1,i);
		}
		before=now;
		ptr=i;
		should_remove=0;
	}
  }

  int now=query_A(1);
  if (now!=before-should_remove){
	  find_it(ptr+1,primes.size()-1);
  }

  int answer=1;

  for (int i=0;i<ans.size();i++){
	  int val=ans[i];
	  while (true){
		  if (val*1ll*ans[i]>n)
			  break;
		  if (query_A(val*ans[i])==0)
			  break;
		  val*=ans[i];
	  }
	  answer*=val;
  }

  answer_it(answer);

  if (LOCAL){
	  cout<<count_of_queries<<" total queries"<<endl;
  }

  //cin.get(); cin.get();
  return 0;
}