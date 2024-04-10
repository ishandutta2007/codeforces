/*
Why put this sadness inside of me
Why be so matter-of-fact
Why put this one bit of hope in me
You sold me out and that's that
I hope that you're having fun with me
There's not much left to attack
I hope that you're nearly done with me
You sold me out and that's that
All sold out i'd never seen
A mind so tangled, a girl so strangled
All sold out well i felt so green
It was just like that
I was put down flat
I was sold out just like that
Oh baby
All sold out i'd never seen
A mind so tangled, a girl so strangled
All sold out well i felt so green
It was just like that
I was put down flat
I was sold out just like that
I missed the point of you doing it
Your mind has just jumped the track
I took a bit different view of it
You sold me out and that's that
Hey hey, that's that
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int n,ar[N];
set<int> S;
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		if (ar[i]!=0)
			S.insert(ar[i]);
	}

	cout<<S.size()<<endl;

//	cin.get(); cin.get();
	return 0;
}