/*
What am i supposed to be
In my life
In your life
In our life
In this life

In shut the door and close my sight
At the end of the day

It's not the way that it used to be
There's no way i'll see
The beginning of things to come
Trapped in the ways of the weak
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

int tests,n,ar[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		int ok=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>ar[i];
			if (i>1&&ar[i]>=ar[i-1])
				ok=1;
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    //cin.get(); cin.get();
    return 0;
}