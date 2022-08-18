/*
And it begins anew
The hatred of mankind
As it seeks to kill that which lives inside

Now we are dying,
Dying the slowest death
Held down by bonds that bind us
We breath our final breath

And it begins anew
The burning we endure
As we seek the srrength, strength to break the bonds

Now we are dying,
Dying the slowest death
No more condemnation
We fight for our last breath

Breathe life, for you are not alone
Breathe life, inside your heart of stone

From dust you were born,
And to the ashes you return

Break the bonds

Breathe life, for you are not alone
Breathe life, inside your heart of stone
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1200031;

long long n,m,a,b,ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>a>>b;

	long long above=n/m*m+m*(n%m>0);
	long long below=n/m*m;

	ans=min((above-n)*a,(n-below)*b);
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}