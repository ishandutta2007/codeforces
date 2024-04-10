/*
Well there's a light in your eye that keeps shining
Like a star that can't wait for the night
I hate to think I've been blinded baby
Why can't I see you tonight?

And the warmth of your smile starts a-burnin'
And the thrill of your touch gives me fright
And I'm shaking so much, really yearning
Why don't you show up, make it all right?
Yeah, it's all right.

And if you promised you'd love so completely
and you said you would always be true
You swore that you would never leave me, baby:
What ever happened to you?

And you thought it was only in movies
As you wish all your dreams would come true
It ain't the first time believe me, baby
I'm standin here feeling blue
Yeah I'm blue

Now I will stand in the rain on the corner
I'll watch the people go shuffling downtown
Another ten minutes no longer
And then I'm turning around

The clock on the wall's moving slower
My heart it sinks to the ground
And the storm that I thought would blow over
Clouds the light of the love that I found

Now my body is starting to quiver
And the palms of my hands getting wet
I've got no reason to doubt you baby,
It's all a terrible mess

I'll run in the rain till I'm breathless
When I'm breathless I'll run till I drop, hey
The thoughts of a fool's kind of careless
I'm just a fool waiting on the wrong block, oh yeah
Light of the love that I found...
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
//#define bs 1234567891
#define bsize 512

const int N = 1200000;

using namespace std;

int n, a[N], b[N], kill, alive[N];
int ans;
vector<pair<int, int> > order;

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
		cin >> a[i] >> b[i];
		order.push_back(make_pair(a[i], b[i]));
	}

	sort(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++)
	{
		a[i + 1] = order[i].first;
		b[i + 1] = order[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		kill = lower_bound(a + 1, a + i + 1, a[i] - b[i])-a;
		alive[i] = alive[kill - 1] + 1;
		ans = max(ans, alive[i]);
	}

	cout << n - ans << endl;

	cin.get(); cin.get();
	return 0;
}