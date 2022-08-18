/*
Why can't you feel this?
Can't you understand I feel this?
This is nothing.
I can see my reflection in your cheek bone.
We've been playing out this script in your mind.
Here we go with a fresh perspective.
You'll paint the walls with your stone face tactics.
And we'll walk around.
Eyes on the crowd.
And don't you think about tomorrow.
You shut me out.
I just don't want to fake it anymore.
I'm burning out.
Your motions empty and you've hit the floor.
You shut me out.
The sweet relief of saying, you shield your heart from breaking.
Get up, get out now.
Get up, get out.
In the glow of the moonlight serenade.
Unleash the knowledge of the white collar escapade.
Speak the words that unlock the truth.
And you'll paint the walls.
You'll paint the walls.
We'll walk around.
Eyes on the crowd.
Don't you think about tomorrow.
You watched me follow fools to the sea.
Tie the stones that bring me down below the tide.
Down and down.
What am I supposed to do? You shut me out.
I just can't live like this anymore.
I'm burning out.
It doesn't feel like it once did before.
You shut me out.
The sweet relief of saying, you shield your heart from breaking.
Get up, get out now.
Get up, get out.
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

long long n, b, d, val, s, ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> b >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		if (val > b)
			continue;
		s += val;
		if (s > d)
			ans++,
			s = 0;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}