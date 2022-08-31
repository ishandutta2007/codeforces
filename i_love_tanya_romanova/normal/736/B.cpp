/*
Running wild crazy and free
Being anything I want to be
Got no time for hanging around
Ain't nobody gonna tie me down
Spend my time doing what I please
Take the world on, got 'em on their knees
People think that I'm no good
Won't do the things they think I should

Life's confusing me and messin' me around
Don't know if I'm ever coming down
Got to get your mind out of my head
Leave me alone and live your life instead

Play my music way too loud
My hair's too long, I don't fit in the crowd
Leather jacket and denim jeans
Metal studs run down the seams
Times are hard but I don't care
'Cause if I want it I'll take my share
Talkin' life on a bit too steep
Outta my way or I'll bury you deep

Gotta stop pushin' shovin' me around
Gotta stop tryin' to put me down
Got to get your mind out of my head
Leave me alone and live your life instead

Lotta people got a lot to say
But I'm doing things my own way
'Cause I'm free as the wind

Maybe someday they will understand
Just why I choose to be my own man
It doesn't matter I ain't gonna change
The master plan should be rearranged
Breaking rules is what I do
On the bad side it's a better view
If it's too loud then you're too old
Get the hell out 'cause you've been told

Gotta stop pushin' shovin' me around
Gotta stop tryin' to put me down
Got to get your mind out of my head
Leave me alone and live your life instead

Lotta people got a lot to say
But I'm doing things my own way
'Cause I'm free as the wind
*/

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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 122231;

int n;
int is_prime(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

int main(){
	//freopen("king.in","r",stdin);
	//freopen("king.out","w",stdout);
//	freopen("F:/input.txt", "r", stdin);
//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;

	if (is_prime(n))
	{
		cout << 1 << endl;
		return 0;
	}

	if (n % 2 == 0)
	{
		cout << 2 << endl;
		return 0;
	}

	if (is_prime(n - 2) && is_prime(2))
	{
		cout << 2 << endl;
		return 0;
	}
	cout << 3 << endl;

	cin.get(); cin.get();
	return 0;
}