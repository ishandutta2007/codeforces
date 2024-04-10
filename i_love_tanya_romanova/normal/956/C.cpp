/*
Let the horizon lead
Onto the ether of the night
Draped across the burning heavens
Flying homeward like a bird of the soul

Shattered into a million brighter stars
Each flare unique and rare
Scattered across forever
Out from creation's core
An end beyond compare
Iridium

Now is the time to leave
We lie awake, we stand afire
At the edge of the world
Above a myriad of light
Below the mantle of the stars
And strangely they fall

Shattered into a million brighter stars
Each flare unique and rare
Scattered across forever
Out from creation's core
An end beyond compare
Iridium

Shattered into a million brighter stars
Each flare unique and rare
Scattered across forever
Out from creation's core
An end beyond compare
An end beyond compare
Iridium
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

long long answ;
int ans[N];
int ar[N];
int n;

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
		ans[i]=max(ans[i-1],ar[i]+1);
	}

	for (int i=n-1;i>=1;--i)
		ans[i]=max(ans[i],ans[i+1]-1);

	for (int i=1;i<=n;i++)
		answ+=ans[i]-ar[i]-1;

	cout<<answ<<endl;

//	cin.get(); cin.get();
	return 0;
}