/*
Our lives run different ways
Through the rain I see you in the sun
Our star shines anyway
If you wish upon it we are one
Dog eat Dog
Every day
On our fellow man we prey
Dog eat Dog
To get by
Hope you like my genocide
I find it such a shame
Through the pain I see things as they are
We're served up on a plate
The pedestal is high enough to fall
And if in time
We can see the errors of our ways
Would anyone change it anyhow
Our time is up
I bet you'd only run
If you saw what goes inside our own
I bet you'd lead the way
If it were up to you decide
But it's not
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int n;
set<string> have;
string name[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>name[i];
		if (have.find(name[i])!=have.end())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		have.insert(name[i]);
	}

	cin.get(); cin.get();
	return 0;
}