/*
To slit the grinning wounds
from childhood's seven moons
the palette stained with the ejaculated passions
(of forbidden, hedonistic colors...)

Strike from omnipotence; all-seer, all-deemer
and haunt my severed country with your
dripping, secret games

You pick the unripe lilies
deflored and peeled the bleeding petals
made known to me
the grainy stains, the crimson lotus
of the Black-Ash Inheritance,
the semen feed of gods and masters
The worms still in me,
still a part of me,
racing out from leaking rooms,
swoop from broken lungs to block the transmission
to put an end to the nomad years

Father
you are the
dead god in me
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

const int N = 1000031;

int tests;
string st;
int ans;

int count1(int val){
	int res=0;
	for (int i=0;i<st.size();i++){
		if (st[i]==val+48)
			++res;
	}
	return res;
}

int count2(int v1,int v2){
	int res=0;
	for (int i=0;i<st.size();i++){
		if (st[i]==v1+48&&res%2==0)
			res++;
		else if (st[i]==v2+48&&res%2==1)
			res++;
	}
	if (res%2)
		res--;
	return res;
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>st;
	 ans=0;
	 for (int i=0;i<10;i++){
		 ans=max(ans,count1(i));
	 }
	 for (int i=0;i<10;i++){
		 for (int j=0;j<10;j++){
			 ans=max(ans,count2(i,j));
		 }
	 }
	 cout<<st.size()-ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}