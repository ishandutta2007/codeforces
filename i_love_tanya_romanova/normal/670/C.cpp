/*
Towards the rich archaic heavens
Towards the black diorama
You are the artist and the texture
That plays, with mantle, of the earth

When the bleakest of powders
Lie rooted, into the darkness hours
And the root that feed the peaking trees
Embrace the sleeping stones

Archaic pearls of sleep and death
The voice of December, losing its breath
And the flower yard of white and gray is haunted, is haunted
White as the down of a flaking snow
The heroic emblems of life

The green is the color of my death
As the winter, guides I swoop towards the ground
Green is the landscape
Of my sorrow filled passing

Archaic pearls of sleep and death
Voice of December, losing its breath
And the flower yard of white and gray is haunted, is haunted
White as the down of a flaking snow
The heroic emblems of life

Yea

We are in flames
Towards the dead archaic heavens
We are the artist and the texture
The altars, the mantle, of the earth

Archaic pearls of sleep and death
The voice of December, losing its breath
And the flower yard of white and gray is haunted, is haunted
White as the down of the flaking snow
The heroic emblems of life
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 210000;

int n, a[N];
map<int, int> cnt;
vector<pair<pair<int, int>, int> > res;
int b[N], c[N];
int m;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>> c[i];
		res.push_back(make_pair(make_pair(cnt[b[i]], cnt[c[i]]), i));
	}

	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	cout << res[0].second << endl;

	cin.get(); cin.get();
	return 0;
}