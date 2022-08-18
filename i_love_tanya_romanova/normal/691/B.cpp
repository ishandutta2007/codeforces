/*
I've used hammers made out of wood
I have played games with pieces and rules
I undeciphered tricks at the bar
But now you're gone, I haven't figured out why
I've come up with riddles and jokes about war
I've figured out numbers and what they're for
I've understood feelings and I've understood words
But how could you be taken away?

And wherever you've gone
And wherever we might go
It don't seem fair...
Today just disappeared.
Your light's reflected now, reflected from afar
We were but stones, your light made us stars.

With heavy breath, awakened regrets
Back pages and days alone that could have been spent, together...
But we were miles apart.
Every inch between us becomes light years now
No time to be void or save up on life
You got to spend it all...

And wherever you've gone
And wherever we might go
It don't seem fair...
You seem to like it here
Your light's reflected now, reflected from afar
We were but stones, your light made us stars.
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1000031;

char w[1000];
string st;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i = 0; i <= 500; i++)
		w[i] = '.';

	w['A'] = 'A';
	w['H'] = 'H';
	w['I'] = 'I';
	w['M'] = 'M';
	w['O'] = 'O';
	w['o'] = 'o';
	w['T'] = 'T';
	w['U'] = 'U';
	w['V'] = 'V';
	w['v'] = 'v';
	w['W'] = 'W';
	w['w'] = 'w';
	w['X'] = 'X';
	w['x'] = 'x';
	w['Y'] = 'Y';
	
	w['b'] = 'd';
	w['d'] = 'b';

	w['p'] = 'q';
	w['q'] = 'p';

	cin >> st;
	string memo = st;
	for (int i = 0; i < st.size(); i++)
	{
		st[i] = w[st[i]];
	}
	
	reverse(st.begin(), st.end());
	if (st == memo)
		cout << "TAK";
	else
		cout << "NIE";

	cin.get(); cin.get();
	return 0;
}