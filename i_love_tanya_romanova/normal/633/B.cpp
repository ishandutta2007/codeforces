/*
I gotta get out I gotta break free
Ain't gonna live in misery
My minds made up I'm leaving today
Come hell or high water I'm will break these chains
Gonna scratch my way, claw my way,
Dig my way, back to the top
Cause I never say die, I never give in
I never stop giving it all that I got
I'm breaking out of hell

From the bottom of the well
It's a long way down
From the bottom of the well
I gotta get out
From the bottom of the well

It's so dark and cold down here
I'm all alone but I got no fear
Cause I Have the will to beat this fate
And get back up to the light of day
Gonna scratch my way, claw my way,
Cause I never say die, I never give in
I never stop giving it all that I got
I'm breaking out of hell

From the bottom of the well
It's a long way down
From the bottom of the well
I gotta get out
Diggin and clawing and scratching and kicking my way
Back to the top I will fight for the light of day
Gonna finde the way yeah

I made a death wish and it came true
I'm under water black and blue
But if you think I'm done you better think again
You better think again cause I don't know the meaning of death

I'm gonna scratch my way, claw my way
Never stop givin it all that I got
I'm breaking out of hell
I'm breaking out of hell

From the bottom of the well
It's a long way down
From the bottom of the well
I gotta get out

I'm breaking out of hell
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
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 15000;

using namespace std;

int n;

int solve(int x)
{
	int res = 0;
	while (x)
	{
		res += x / 5;
		x /= 5;
	}
	return res;
}

vector<int> ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= 510000; i++)
	{
		if (solve(i) == n)
			ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}