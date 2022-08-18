/*
Perched alone he sits there broken
An elder man with storm clouds setting in his eyes
He counts the sands of time, remembering days gone by
it's seemed like yesterday before it washed away

Hey don't wait for me there, just find your own way
Hey don't wait for me there, I'll be there soon enough

A widows life ticks out like clock work
A thousand tears she's cried a hundred times before
But now that he is gone, she's ready to move on
It all just fell away, it seems like yesterday

Hey don't wait for me there, just find your own way
Hey don't wait for me there, I'll be there soon enough

I'll be there soon enough
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

int tests;
int n;
int ar[N];

bool check0(){
	for (int i=1;i<=n;i++){
		if (ar[i]!=i)
			return false;
	}
	return true;
}

int count_blocks(){
	int res=0;
	int cur=0;
	for (int i=1;i<=n;i++){
		if (ar[i]==i){
			if (cur)
				res++;
			cur=0;
		}
		else
			++cur;
	}
	if (cur)
		++res;
	return res;
}

int solver(){
	if (check0())
		return 0;
	if (count_blocks()==1)
		return 1;
	return 2;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;

  for (;tests;--tests){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	cout<<solver()<<endl;
  }

  cin.get(); cin.get();
  return 0;
}