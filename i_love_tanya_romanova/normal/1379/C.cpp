/*
I'm supposed to talk to you
Don't even know where to start
Don't want to stand with the setting sun
Tell me does it really show?

I'll promise you anything
Place your hand over your heart
Don't want to fool myself anymore
Think nobody else will ever know

Mr. White up all night
Hiding in my room
Mr. White so uptight
Black shapes of doom

Could never show you how I feel
Even so I didn't care
It's only that inside
I'm so tired
So tired of being all alone

Now the hours are breathing
Gone like tears in yesterdays rain
I remember voices telling me
Secrets of mind-changing reality

Mr. White up all night
Hiding in my room
Mr. White so uptight
Black shapes of doom

Mr. White up all night
Always likes to sing
Mr. White so uptight
Even knows my name
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

int tests,n,m;
vector<pair<long long, long long> > order;
long long ans;
long long a[N],b[N];
long long S[N];
long long cur_sum_A,cur_best_B,cur_rem;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  order.clear();
	  ans=0;
	  for (int i=1;i<=m;i++){
		  cin>>a[i]>>b[i];
		  order.push_back(make_pair(a[i],i));
	  }
	  sort(order.begin(),order.end());

	  S[order.size()]=0;

	  S[order.size()-1]=order.back().first;
	  for (int i=(int)order.size()-2;i>=0;--i){
		  S[i]=S[i+1]+order[i].first;
	  }

	  // all one type
	  for (int i=1;i<=m;i++){
		  ans=max(ans,1ll*a[i]+(n-1)*b[i]);
	  }

	  cur_best_B=0;
	  cur_sum_A=0;
	  cur_rem=n;

	  // some As, then best B
	  for (int i=order.size()-1;i>=0;--i){
		  int id=order[i].second;
		cur_best_B=max(cur_best_B,b[id]);
		cur_sum_A+=order[i].first;
		cur_rem--;
		if (cur_rem<0)
			break;
		ans=max(ans,cur_sum_A+cur_rem*1ll*cur_best_B);
	  }

	  // take some id, take suff of better ones, fill in the rest with B

	  for (int i=0;i<order.size();i++){
		  int id=order[i].second;
		  int bound=lower_bound(order.begin(),order.end(),make_pair(b[id],-1ll))-order.begin();
		//  cout<<i<<"@@"<<bound<<" "<<id<<endl;
		  int how_many=min(0ll+n-1,(long long)(order.size())-bound);
		  if (order.size()-how_many<=i)
			  continue;// already covered in the case above
	//	  cout<<"@"<<how_many<<"@@@"<<endl;
		  long long val_here=a[id]+S[order.size()-how_many];
//		  cout<<val_here<<"!!!"<<endl;
		  val_here+=(n-how_many-1)*b[id];
		  ans=max(ans,val_here);
	  }
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}