/*
Being has overwhelmed the space between the silence of eternity
Vision has intruded upon the light that pours through me, my energy
Substance has veiled, the pleasures long lost, the beauty of emptiness
This very flesh confines, and spoils this demon's seed

Waiting to light, A dead sky aflame
To suffocate, to rejoice in your misery
This waiting it seems, for so long I've yearned to see
the burning flesh of your humanity
Your withering flesh, I've longed to see

May you fall to never again arise
May you cease to ever again be
May your soul eternally be, in seas of pain
Pleading, churning, drowning
Pleading, dying, burning

The Treachery Returns to the Betraying Eyes
Your Betrayers cries, fall to unyielding ears
And oh how it came to be, That you would pray to me
That you would beg to me, that this curse not come to be
That you would plead. That this curse not be released

May you fall to never again arise
May you cease to ever again be
May your soul eternally be, in seas of pain
Pleading, churning, drowning
Pleading, dying, burning
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

int n,ar[N],tests;
string st;
int cnt[N];
set<pair<int,int> > mapp;
set<pair<int,int> > ::iterator it;

void inc_count(int val){
	mapp.erase(make_pair(cnt[val],val));
	cnt[val]++;
	mapp.insert(make_pair(cnt[val],val));
}

void dec_count(int val){
	mapp.erase(make_pair(cnt[val],val));
	cnt[val]--;
	mapp.insert(make_pair(cnt[val],val));
}

bool valid(){
	vector<int> counts;
	it=mapp.end();
	for (int i=0;i<3;i++){
		--it;
		counts.push_back((*it).first);
	}

	/*for (int i=0;i<3;i++){
		cout<<counts[i]<<" ";
	}
	cout<<endl;
*/
	if (counts[0]<4)
		return false;
	counts[0]-=4;
	for (int i=0;i<2;i++){
		sort(counts.begin(),counts.end());
//		cout<<counts[counts.size()-1]<<"@@"<<endl;
		if (counts[counts.size()-1]<2)
			return false;
		counts[counts.size()-1]-=2;
	}
	return true;
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  for (int i=0;i<=200000;i++){
	  mapp.insert(make_pair(0,i));
  }

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  inc_count(ar[i]);
  }

  cin>>tests;
  for (;tests;--tests){
	 cin>>st;
	 int val;
	 cin>>val;
	 if (st=="+")
	 {
		 inc_count(val);
	 }
	 else
	 {
		 dec_count(val);
	 }
	 if (valid())
		 cout<<"YES"<<endl;
	 else
		 cout<<"NO"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}