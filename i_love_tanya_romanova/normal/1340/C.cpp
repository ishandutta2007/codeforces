/*
I used to be crustacean
In an underwater nation
And I surf in celebration
Of a billion adaptations

Got me a big wave, ride me a big wave, got me a big wave.
Got me a big wave, ride me a big wave, got me a big wave.

I feel the need
Planted in me
Millions of years ago
Can't you see
The oceans size?
Defining time
And time
Arising
Arms laid upon me
Being so kind
To let me ride

I scream in affirmation
Of connecting dislocations
And exceeding limitations
By achieving levitation

Got me a big wave, ride me a big wave, got me a big wave.
Got me a big wave, ride me a big wave, got me a big wave.

I feel the need
Planted in me
Millions of years ago
Can't you see
The oceans size?
Defining time
And time
Arising
Arms laid upon me
Being so kind
To let me ride

Got me a ride.
I got me a ride.
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

int n,m,d[10031];
int used[10031][1031];
int g,r;
long long ans;
queue<pair<int,int> > qu[10];
int TTL;

void update(int ps,int rem,int new_ps,int new_rem){
	if (new_rem>g)
		return;
	int flag=0;
	if (new_rem==g)
	{
		new_rem=0;
		flag=1;
	}
	if (used[new_ps][new_rem])
		return;
	used[new_ps][new_rem]=used[ps][rem]+flag;
	int id=used[ps][rem]+flag;
	qu[id%2].push(make_pair(new_ps,new_rem));
	++TTL;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m;
  for (int i=1;i<=m;i++)
	  cin>>d[i];
  sort(d+1,d+m+1);

  cin>>g>>r;

  used[1][0]=1;
  qu[1].push(make_pair(1,0));

  TTL=1;

  ans=1e18;

  int iter=1;

  while (TTL){
//	  cout<<TTL<<" "<<iter<<endl;
	  while (qu[iter%2].size()){
		  pair<int,int> p=qu[iter%2].front();
		  --TTL;
		  qu[iter%2].pop();
		  int q_pos=p.first;
		  int q_rem=p.second;
		//  cout<<q_pos<<" "<<q_rem<<" "<<iter<<endl;
		  if (q_rem==0){
			  long long here=1ll*(g+r)*(used[q_pos][q_rem]-1);
			  if (g-q_rem>=n-d[q_pos]){
				  ans=min(ans,here+(n-d[q_pos]));
			  }
		  }
		  if (q_pos>1){
			  update(q_pos,q_rem,q_pos-1,q_rem+d[q_pos]-d[q_pos-1]);
		  }
		  if (q_pos+1<m){
			  update(q_pos,q_rem,q_pos+1,q_rem+d[q_pos+1]-d[q_pos]);
		  }
	  }
	  ++iter;
  }

  if (ans>1e17)
	  ans=-1;
  cout<<ans<<endl;

  // cin.get(); cin.get();
  return 0;
}