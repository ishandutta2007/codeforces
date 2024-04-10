/*
Universal bond, we're all the same
Evil man, not to be tamed
Open your mind, and you will find
You're just evil as evil as I

There's little bit of evil inside of you
A little bit of evil inside you too

Man of mercy, sinister disguise
Cause I see evil, evil in your eyes
Unmask yourself and you will find
You're just evil as evil as I
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define ry asdgasdg
#define rx iqowputtew

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 201000;

using namespace std;

long long n,ar[N];
long long ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		cin >> ar[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		ans += abs(ar[i]-ar[i-1]);
	}
	cout << ans << endl;
	
	return 0;
}