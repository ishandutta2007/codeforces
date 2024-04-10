/*
On a journey ill
My mind floats astray
Over withered fields
I cross the river

This shortness of breath
Between birth and grave
Fading in the distance
I am nothing

Watch the skeleton dance
Dancing on my grave
My frozen hour of death

Here I am alone
Casting my own shadows
Traversing the mundane
Desperate cry

Boundless darkness
A voiceless fear
Unheard, Unseen
It is coming near

Watch the skeleton dance
Dancing on my grave
My frozen hour of death
Watch the skeleton dance
Here I am - Alone...

Had I not known
That I was dead
I would have mourned
My loss of life
Loss of life...

Between birth and grave
Here I am alone
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

int tests,n;
vector<pair<int,int> > order;
int t[N*4];
int ans;
int ar[N];

void build(int v,int tl,int tr){
	t[v]=0;
	if (tl==tr)
		return;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

int get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v]=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=max(t[v*2],t[v*2+1]);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  /*cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  order.clear();
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
		  order.push_back(make_pair(ar[i],i));
	  }
	  sort(order.begin(),order.end());

	  build(1,1,n);

	  ans=0;

	  for (int i=0;i<order.size();i++){
		  int ps=order[i].second;
		  int val=get(1,1,n,1,ps-1);
		  ans=max(ans,val+1);
		  update(1,1,n,ps,val+1);
	  }
	  cout<<n-ans<<endl;
  }*/

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  order.clear();
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
		  order.push_back(make_pair(ar[i],i));
	  }
	  sort(order.begin(),order.end());
	  int cnt=0;
	  int ans=0;
	  for (int i=0;i<order.size();i++){
		  if (i>0&&order[i].second<order[i-1].second)
			  cnt=0;
		  cnt++;
//		  cout<<" "<<order[i].first;
		  ans=max(ans,cnt);
	  }
	 // cout<<endl;
	  cout<<n-ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}