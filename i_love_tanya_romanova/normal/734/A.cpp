/*
Face to face
No time to waste
This is the time for revenge
Your claim to fame
Of crushing dreams
Your control has no hold on me
Has no hold on me

I hate the way
You have no shame
You act like nothing's happened
It's time to rise
The final fight
This is the last time

I, I will not fail again
I will not let you win
Fuck your power trip

I'll throw away
The wasted days
The chance for revenge
My claim to fame
Ended in vain
This was the last time

I, I will not fail again
I will not let you win
Fuck your power trip

I will not fail again
I will not let you win
Fuck your power trip, oh ow

You are the one who's forsaken us all
Nothing has changed so together we fall
I am the one who's led us to believe
You can't change me

I, I will not fail again
I will not let you win
Fuck your power trip

I, I will not fail again
I will not let you win
Fuck your power trip

Yeah, fuck your power trip
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
const int N = 200031;

int n;
string st;
int cnt[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		cnt[st[i]]++;
	}

	if (cnt['A']>cnt['D'])
		cout << "Anton" << endl;
	else
	if (cnt['A'] < cnt['D'])
		cout << "Danik" << endl;
	else
		cout << "Friendship" << endl;

	cin.get(); cin.get();
	return 0;
}