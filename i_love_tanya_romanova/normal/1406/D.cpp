/*
Land of enchantment and fake reality
Where they put in vitro breeding machines
On the cover of a magazine
Trailer trash and human freaks
They grab their minute of fame
And still the puppets watch
And everybody knows the names
That's why I say

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames

So young, bitch and famous
Hotel heiress, glamour queen
The only reason we know your name
Is bad night vision pornography
From the "real" housewives of botox hills
To the cunts of Bel-Aire
You can't look away from the cathode ray
Why does anybody fucking care

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames
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

long long n,ar[N];
long long sum_of_jumps;
long long first_element;
long long q;
long long l,r,val;
long long dif[N];

void update_dif(int ps,int val){
	if (dif[ps]>0)
		sum_of_jumps-=dif[ps];
	dif[ps]+=val;
	if (dif[ps]>0)
		sum_of_jumps+=dif[ps];
}

void update(int l,int r,long long val){
	if (l==1){
		first_element+=val;
	}
	if (l>1)
		update_dif(l-1,val);
	if (r<n)
		update_dif(r,-val);
}

long long get_middle(long long l,long long r){
	long long s=l+r;
	if (s>=0)
		return s/2;
	if (s%2==0)
		return s/2;
	s*=-1;
	s/=2;
	s++;
	return -s;
}

bool is_doable(long long fi,long long jumps,long long thold){
	long long start_of=fi-thold;
	return start_of+jumps<=thold;
}

long long solver(long long fi,long long jumps){
	long long l,r;
	l=-1e18;
	r=1e18;
	while (l<r){
		long long mid=get_middle(l,r);
		if (is_doable(fi,jumps,mid))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}


int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

//  cout<<get_middle(-1,-2)<<endl;
//  cout<<get_middle(1,2)<<endl;

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
  }

  for (int i=1;i<n;i++){
	  dif[i]=ar[i+1]-ar[i];
	  if (ar[i]<ar[i+1]){
		  sum_of_jumps+=ar[i+1]-ar[i];
	  }
  }

  first_element=ar[1];

  cout<<solver(first_element,sum_of_jumps)<<endl;

  cin>>q;
  for (;q;--q){
	  cin>>l>>r>>val;
	  update(l,r,val);

	/*  for (int i=1;i<n;i++){
		  cout<<dif[i]<<" ";
	  }
	  cout<<endl;
*/
	  cout<<solver(first_element,sum_of_jumps)<<endl;
  }

  cin.get(); cin.get();
  return 0;
}