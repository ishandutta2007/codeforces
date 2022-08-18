/*
Into a strange new world, into the after
All your tears might find you've fallen too far
Take another look, take another ride
Can't we make them leave the hate behind

And I still believe in nothing
Will we ever see the shape of tomorrow?

Into the empty storm, into the formless loss of hope,
Where we can forget the game

And I still believe in nothing
Will we ever see the cure for our sorrow

Nothing is sacred when no one is saved
Nothing's forever so count your days
Nothing is final and no one is real
Pray for tomorrow and find your empty still

Nothing
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

const int N = 17;

using namespace std;

int n, a, b;
long long ans;
map<int, int> cnt_x, cnt_y;
map<pair<int, int>, int> C;

int main(){
	//	freopen("packing.in", "r", stdin);
	//	freopen("packing.out", "w", stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		ans += cnt_x[a];
		ans += cnt_y[b];
		ans -= C[make_pair(a, b)];
		cnt_x[a]++;
		cnt_y[b]++;
		C[make_pair(a, b)]++;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}