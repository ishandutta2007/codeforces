/*
When war cries echo let it all begin
Never known any other way to fight just win
Blood of the enemy when penance is due
You know that sacrifice starts with you

Cast the first stone
Stand in my way
It's vengeance you owe
With blood you will pay

I live for battle the intensity knows no peer
Your defiance will prove severe
Choking on blood, beaten in pain
Realizing the fighting is all in vain

Cast the first stone
Stand in my way
It's vengeance you owe
With blood you will pay

When the war cries echo sacrifice is you

You can feel that it's with me everywhere I walk
Like a devil spitting fire every time I talk
Manifested confidence you can't stop
A block of granite on my shoulder you can't knock off

Cast the first stone
Stand in my way
It's vengeance you owe
With blood you will pay
On fields of blood, you will pay
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

int tests,n,ans[N];

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  ans[i]=9;
	  }
	  int rem_rem=n;
	  for (int i=n;i;--i){
		  if(rem_rem>=1)
			  ans[i]=8;
		  rem_rem-=4;
	  }
	  for (int i=1;i<=n;i++){
		  cout<<ans[i];
	  }
	  cout<<endl;
  }
  cin.get(); cin.get();
  return 0;
}