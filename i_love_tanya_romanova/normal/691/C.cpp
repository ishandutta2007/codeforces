/*
When you feel the world is above you
When you feel like screaming your lungs out

When you're in the darkness all alone
Don't wanna let it eat you alive
You'll never be alone, you'll never be alone
A man's gotta do what he's gotta do as long as you

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong, yeah

Why don't you fight for once in your life?
Don't wanna live your life through someone else's eyes
You'll never be alone, you'll never be alone
A man's gotta do what he's gotta do as long as you

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong, yeah

Now that I'm here, I'm gonna face my fears
Tired of hiding and I'm tired of running
All that was part of me the fear that was in me
I'm strong enough to finally break free

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong

Shout, scream your hearts out
Don't let nobody take you down
Where you ain't belong, yeah

It's your time to shout
So shout, it's your time to shout, yeah
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
const int N = 100031;

string st;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	getline(cin, st);
	int p = 0;
	while (p < st.size() && st[p] != '.')
		++p;
	if (p == st.size())
		st += ".";

	reverse(st.begin(), st.end());
	while (st[st.size() - 1] == '0')
		st.erase(st.end() - 1);

	reverse(st.begin(), st.end());
	while (st[st.size() - 1] == '0')
		st.erase(st.end() - 1);

	int oh = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] != '.')
			oh++;
		else
			break;
	}

	if (oh == 0) // <1
	{
		int q = 1;
		int xp = 0;
		while (st[q] == '0')
		{
			++q;
			++xp;
		}
		cout << st[q];
		if (q + 1 < st.size())
		{
			cout << ".";
		}
		for (int i = q + 1; i < st.size(); i++)
		{
			cout << st[i];
		}
		++xp;
		cout << "E-" << xp << endl;
	}
	else
	{
		st.erase(st.begin() + oh);
		cout << st[0];
		while (st.size() > 1 && st[st.size() - 1] == '0')
			st.erase(st.end() - 1);
		if (st.size()>1)
		{
			cout << ".";
		}
		for (int i = 1; i < st.size(); i++)
		{
			cout << st[i];
		}
		--oh;
		if (oh>0)
			cout << "E" << oh << endl;
	}

		cin.get(); cin.get();
	return 0;
}