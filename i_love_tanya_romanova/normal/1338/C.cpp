/*
Another emergency truck keeps rolling fast
Two lane highway and they run on the wrong track
You still don't know that you're never going back
You're going to the science hospital
You guess that your body is still alive
They estimate you're in pretty good health
Good shape for some of our sadistic tests
Doctor said you must stay in bed
Surgical scourge on you
Surgical scourge on you
Electric shock through you
Electric shock through you
Feel the scalpel they cut you with
Going into the experimental room
How much radiation can your body stand?
You did very well, you'll feel better soon
The red cross is turning black
Wake up in another department
You see the nurse with blood on her clothes
They got another experience for today
Maybe the worst of them
Diagnosing the pain, the ravenous medicine
Discovering the cure, the ravenous medicine
Died through illness, the ravenous medicine
Don't care how many organs you gave
Injecting the drugs
Till you become the slave
Turn off the machine that keeps your heart beating
They're gonna do it to you!
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

int used[1000000];

long long n,start,iters;

long long MAGIC2;

long long solver(long long n,long long start){

//	long long fi=restore_first(n,start);

	long long group_id=n/3;
	if (n%3==0)
		return start+group_id;
	long long baseline=start*2;
	if (n%3==1){
		return MAGIC2;
	}
	return solver(n-1,start)^solver(n-2,start);
}

long long cool_solver(long long iter){
	--iter;
	long long full=1;
	while (iter>=full)
	{
		iter-=full;
		full*=4;
	}
	long long res=full*2;
	vector<int> digs;
	long long P=1;
	while (full>=1){
		long long
		int here=iter%4;
		if (here==1)
			res+=2*P;
		if (here==2)
			res+=3*P;
		if (here==3)
			res+=P;
		P*=4;
		iter/=4;
		full/=4;
	}
	return res;
}
int tests;

long long smart(long long n){
	long long nn=n;
	MAGIC2=cool_solver((nn+1)/3);
	--n;

	 long long start,iters;
	  start=1;
	  iters=1;
	  while (n>=iters*3){
		  n-=iters*3;
		  start*=4;
		  iters*=4;
	  }
	//  cout<<n<< ""<<start<<endl;
	  return solver(n,start);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int itr=0;

   //some random magic.
 /* for (int iter=1;iter<=250;iter++){
	  int ai=0;
	  int aj=0;

	  for (int i=1;i<=3000;i++){
		  for (int j=i+1;j<=3000;j++){
			  if (ai)
				  break;
			  if ((i^j)<=j)
				  continue;
			  if (used[i]||used[j]||used[i^j])
				  continue;
			  ai=i;
			  aj=j;
		  }
	  }
	  cout<<ai<<" "<<aj<<" "<<(ai^aj)<<endl;
	  cout<<smart(iter*3-2)<<" "<<smart(iter*3-1)<<" "<<smart(iter*3)<<endl;

	  used[ai]=used[aj]=used[ai^aj]=1;
  }
*/
  int tests;
  cin>>tests;
  for (;tests;--tests){
	  cin>>n;

	  cout<<smart(n)<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}