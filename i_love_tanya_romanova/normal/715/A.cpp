/*
He's the evil in the angel
The black inside the light
The treachery is there to see
He feeds upon your fright
No method to his madness
No wisdom in his ways
It's plain to see the agony
As night time turns to day

All thru the night
No end in sight
Fever thru his veins
All thru the night
With lines of white
He tries to be cool
But he's playin' the fool

Dying to live, dying to live
Dying to live, dying to live

He's on course for self destruction
A time bomb set to blow
No sign of life in his eyes
His hunger thrives to grow
A spark just sets the fire
One shot just leads to more
Covered tracks to heart attack
Found dead on the floor

All thru the night
No end in sight
Fever thru his veins
All thru the night
With lines of white
He tries to be cool
But he's playin' the fool

Dying to live, dying to live
Dying to live, dying to live

Dying to live, dying to live
Dying to live, dying to live
Dying to live, dying to live
Dying to live, dying to live
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

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
long long cur;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	
	cur = 2;
	for (long long i = 1; i <= n; i++)
	{
		long long need = 1ll*(i + 1)*(i)*(i + 1);
		//cout << i << " " << need << " " << endl;
		long long have = cur / i;
		long long moves = need - have;
		cout << moves << "\n";
		cur = i*(i + 1);

	}

	cin.get(); cin.get();
	return 0;
}