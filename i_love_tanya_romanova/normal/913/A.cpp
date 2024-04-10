/*
I was standing by the Nile
When I saw the lady smile
I would take her out for a while
For a while

Like tears wept like a child
How her golden hair was blowing wild
Then she spread her wings to fly
For to fly

Soaring high above the breezes
Going always where she pleases
She will make it to the island
In the sun

I will follow in her shadow
And I'll watch her from my window
One day I will catch her

She is calling from the deep
Summoning my soul to endless sleep
She is bound to drag me down
Drag me down
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

const int N = 600031;

long long n,m;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	long long mod=1;
	for (int i=1;i<=n;i++){
		mod*=2;
		if (mod>m)
			break;
	}
	cout<<m%mod<<endl;

	cin.get(); cin.get();
	return 0;
}