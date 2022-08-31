/*
I will never give up on you
I see the real you
Even if you don't I do
I do
I will never give up on you
I see the real you
Even if you don't I do
I do

And I'll show you the road to follow
I'll keep you safe till tomorrow
I'll pull you away from sorrow
I see the real you
Even if you don't I do

If you're the one, to run, to run
I'll be the one, the one, you run to!
If you're the one, to run, to run
I'll be the one, the one, you run to!

I will never give up on you
I see the real you
Even if you don't I do
I do
I will never give up on you
I see the real you
Even if you don't I do
I do

And it seems like I've known you forever
I'll keep you safe for one more night
Need you to know that it's all right
I see the real you
Even if you don't I do
I do

If you're the one, to run, to run
I'll be the one, the one, you run to!
You're not the only lonely one
I see the real you
Even if you don't I do
(I do, I do, I do)
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 100500;

const double INF = 1e18;

using namespace std;

int n;
string st;
int c1[N], c2[N];
int ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string st;
		cin >> st;
		for (int j = 0; j < st.size(); j++)
		{
			if (st[j] == 'C')
			{
				ans += c1[i];
				ans += c2[j];
				c1[i]++;
				c2[j]++;
			}
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}