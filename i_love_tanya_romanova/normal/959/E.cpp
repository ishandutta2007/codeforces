/*
What comes as no surprise
To a jaded mind no less
Insight comes to soothing grace
Left to waiting days
Another chord unstrummed

Our secret's safe and sound
Solid now unless it breaks in two
Faithfully unbound
None of this was ever built to last

In the paleness of a less than life
From a corner watching old paint dry
Never once a break
Into the self again
An endeavour that will flat our fail
What maturity comes to end
Never one to face
Another beat undone

Our secret's safe and sound
Solid now unless it breaks in two
Faithfully unbound
None of this was ever built to last

Once again
Another instant saved today
Left a print that leads nowhere
Never built to last
What makes it work
A part of life that makes the weak hearts grow
Take it in if youre willing to say
Willing to do
Prepared to lay it down
Just know this

No!
The prayer, the lord, the weaker, the faith
We never ever built to last
We never ever built to last
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

const int LOT = 1600031;

long long n;
long long solve(long long x){
	if (x==1)
		return 0;
	return solve((x+1)/2)*2+x/2;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	cout<<solve(n)<<endl;

//	cin.get(); cin.get();
	return 0;
}