/*
Coming out to the light of day
We got many moons than a deeper place
So I keep an eye on the shadow's smile
To see what it has to say
You and I both know
Everything must go away
Ah, what do you say?
Spinning off, head is on my heart
It's like a bit of light and a touch of dark
You got sneak attacked from the zodiac
But I see your eyes spark
Keep the breeze and go
Blow by blow and go away
Oh, what do you say?

Yeah, you don't know my mind
You don't know my kind
Dark necessities are part of my design
Tell the world that I'm falling from the sky
Dark necessities are part of my design

Stumble down to the parking lot
You got no time for the afterthought
They're like ice cream for an astronaut
Well that's me looking for weed
Turn the corner and
Find the world and show command
Playing the hand

Yeah, you don't know my mind
You don't know my kind
Dark necessities are part of my design
Tell the world that I'm falling from the sky
Dark necessities are part of my design

Do you want this love of mine?
The darkness helps to sort the shine
Do you want it, do you want it now?
Do you want it overtime?
The darkness helps to sort the shine
Do you want it, do you want it now?

Pick you up like a paperback
With the track record of a maniac
So I'm moving in and we unpack
It's the same as yesterday
Honey where we roll
Everything must go away
Ah, what do you say?

Yeah, you don't know my mind
You don't know my kind
Dark necessities are part of my design
Tell the world that I'm falling from the sky
Dark necessities are part of my design

Ah-ah-ah
Ah-ah
Ah-ah-ah
Ah-ah
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n;
string st;
vector<int> ans;
int cnt;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> st;
	st += "W";
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == 'B')
			++cnt;
		else
		{
			if (cnt)
				ans.push_back(cnt);
			cnt = 0;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}