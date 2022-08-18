/*
Hear my promise of blistering light
Sowing a rose of obsidian
My dear I promise
Death comes to all
In a heartbeat only silence
Let's play with the fire that runs in our veins
Trust in the might of a miracle
Now winter has come and I'll stand in the snow
I don't feel the cold
And it's all that I will ever need to believe

One day I know we will meet again
In the shade of a life to die for
Watching the world through the eyes of a child in Elysium
Will I know you then?
(Will I know you then?)

Now bring down your fortress and swallow your pride
Don't break in your moments of ignorance
Existence will capture a spark of life
Just a fragment, but it's all that I will ever need to revive

One day I know we will meet again
In the shade of a life to die for
Watching the world through the eyes of a child in Elysium
Will I find you there in that darkness
Of the shadow that comes over all?
Dear friend will I know you then?
Will I know you then at all?

One day we'll meet
(One day we will meet in the shade of a life)
In the shade of a life to die for
(Watching the world)
Watching the world through the eyes of a child
Will I know you then?

One day I know we will meet again
In the shade of a life to die for
Watching the world through the eyes of a child in Elysium
Will I know you then?
Will I know you then?
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 110000;

using namespace std;

int n;
vector<pair<int, int> > v;
int ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	int bound = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second>bound)
			ans++,
			bound = v[i].first;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}