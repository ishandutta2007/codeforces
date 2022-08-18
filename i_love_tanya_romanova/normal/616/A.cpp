/*
Wish I could split the night in two
I wish I could what I would do to you

Wish I could hold the nights apart
Oh, to you I'd give the sun, my heart

I'll be the cyclone how it strays
I'll be the moon escaping there

Wish I could be the waking sun
Just for once I'd be the brightest one

Wish I could find you where you hide
Like the sun I'd the tide that swallows tide

I'll be the cyclone how it strays
I'll be the moon escaping there
I'll be your cancer now, the sun that eats away

We used to climb the highest peaks
Used to lay there in the breeze
Then you turned around to run
So now I'm gone

I'll be the cyclone how it strays
I'll be the moon escaping there
I'll be your cancer now the sun that eats away
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 2150;

using namespace std;

string st1, st2;

string norm(string st)
{
	reverse(st.begin(), st.end());
	while (st.size() < 1e6)
		st += "0";
	reverse(st.begin(), st.end());
	return st;
}


int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	getline(cin, st1);
	getline(cin, st2);
	st1 = norm(st1);
	st2 = norm(st2);
	
	if (st1 < st2)
		cout << "<" << endl;
	else if (st1>st2)
		cout << ">" << endl;
	else
		cout << "=" << endl;

	cin.get(); cin.get();
	return 0;
}