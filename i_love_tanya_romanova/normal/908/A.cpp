/*
There goes the siren that warns off the air raid
Then comes the sound of the guns sending flak
Out for the scramble we've got to get airborne
Got to get up for the coming attack.

Jump in the cockpit and start up the engines
Remove all the wheel blocks
there's no time to waste
Gathering speed as we head down the runway
Gotta get airborne before it's too late

Running, scrambling, flying
Rolling, turning, diving, going in again
Run, live to fly, fly to live, do or die
Run, live to fly, fly to live, Aces high

Move in to fire at the mainstream of bombers
Let off a sharp burst and then turn away
Roll over, spin round and come in behind them
Move to their blindsides and firing again

Bandits at 8 o'clock move in behind us
Ten ME-109's out of the sun
Ascending and turning out spitfires to face them
Heading straight for them I press my guns.

Rolling, turning, diving
Rolling, turning, diving, goin' again
Run, live to fly, fly to live, do or die
Run, live to fly, fly to live, Aces high.
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

const int N = 200031;

string st;
int ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	for (int i=0;i<st.size();i++){
		if (st[i]=='a'||st[i]=='e'||st[i]=='o'||st[i]=='u'||st[i]=='i')
			++ans;
		if (st[i]>='0'&&st[i]<='9'&&st[i]%2==1)
			++ans;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}