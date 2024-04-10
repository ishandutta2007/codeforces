/*
I don't see the fearsome fright
all I see is beauty shine
not much time to say goodnight
I can hear you scream in the sky

Nephew do you feel all right
always up in overdrive
they would try to smother you
never let your feelings through

Live out loud

I'm sniffing your garden
I'm sniffing your rose
she's stuck in the middle
you know how it goes

They're crawling across now
they'll give him some blow
we'll do him a favor
we'll give him some gold

I remember your eyes came out
I can see you run and shout
don't know where to place the blame
you knew how to hide your pain

We just want to see you alive
taught me how to speak my mind
release you in atmosphere
it was just too small in here

Live out loud

Hey ho, let's fucking go
hey ho, let's get up and rock n' roll
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
const int N = 510000;

int pr[200];
vector<int> tocheck;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	pr[1] = 1;
	for (int i = 2; i <= 50; i++)
	{
		if (pr[i] == 0)
		{
			for (int j = i * 2; j <= 50; j += i)
				pr[j] = 1;
		}
	}

	for (int i = 2; i <= 50; i++)
	{
		if (pr[i] == 0)
		{
			tocheck.push_back(i);
			if (i*i <= 100)
				tocheck.push_back(i*i);
		}
	}
	//cout << tocheck.size() << endl;

	int cnt = 0;

	for (int i = 0; i < tocheck.size(); i++)
	{
		cout << tocheck[i] << endl;
		string st;
		cin >> st;
		if (st == "yes")
			++cnt;
	}
	if (cnt>1)
		cout << "composite" << endl;
	else
		cout << "prime" << endl;

	cin.get(); cin.get();
	return 0;
}