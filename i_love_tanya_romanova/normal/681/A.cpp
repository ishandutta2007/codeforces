/*
The blood of my brother
Now crusts on my skin
Lingering echoes of laughter
Feeds the pain that I'm in

Pray to gods and demons
For this nightmare to end
The chains shall be broken
They shall die by my hand

The breeze of death from the black's drifting in
Lie and betray but the reaper will win

Darkness awaits in the black halls of doom
The plague takes hold of mankind
Forever trapped in the black halls of doom
Life's cut by the sense of the time
Forever undead

A howl from the shadows
The screams from aside
Taste of blood when you swallow
In this church of the night

Eyeless skulls smile at me
Hear them loud in my head
Ancient bones will guide you
On a trail of the dead
*/

#pragma comment(linker, "/STACK:16777216")
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

int n;
string trash;
int a, b, ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> trash;
		cin >> a >> b;
		if (a >= 2400 && b > a)
			ans = 1;
	}
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	cin.get(); cin.get();
	return 0;
}