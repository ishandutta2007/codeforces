/*
The basement incinerator
Is where they'll put the head
Hose the floor and clean the room
Anywhere they bled

Into boxes go the bags
Fill the space with rocks
In the dark of night
He throws them off the docks

Rotting in the river
Never to be found
Under tons of concrete
Deep beneath the ground

From behind, he grabs his mouth
The blade goes to his neck
Bulging veins pumping blood
He struggles to protect

If you don't cut open the stomach
The corpse will rise and float
The victim is discovered dead
Rotting organs bloat

The killer chops the body
With a scalpel and an axe
The parts are then drained
And put into the sacks

Grab the neck, slit the throat, take the life
Hang the corpse, prepare to drain the blood
Bone saw, meat cleaver, filleting knife
Carve the corpse, dissect him in the tub

Smash the teeth, slice off scars, crush the bones
With a crowbar scrape off all tattoos

If you don't cut open the stomach
The corpse will rise and float
The victim is discovered dead
Rotting organs bloat

The killer chops the body
With a scalpel and an axe
The parts are then drained
And put into the sacks

Chunks of a skull
Sawn in half bones
Body is found
Killer unknown
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
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

vector < pair<long long, pair<int, int> > >v;
int l, r;
int cheap1, cheap2;
int a[N], b[N];
int tp[N];
int c[N];
int n, m, k, s;

bool good(int l)
{
	v.clear();

	cheap1 = 1;
	cheap2 = 1;
	for (int i = 1; i <= l; i++)
	{
		if (a[i] < a[cheap1])
			cheap1 = i;
		if (b[i] < b[cheap2])
			cheap2 = i;
	}

	for (int i = 1; i <= m; i++)
	{
		if (tp[i] == 1)
		{
			v.push_back(make_pair(1ll * a[cheap1] * c[i], make_pair(i, cheap1)));
		}
		else
		{
			v.push_back(make_pair(1ll * b[cheap2] * c[i], make_pair(i, cheap2)));
		}
	}
	sort(v.begin(), v.end());
	long long need = 0;
	for (int i = 0; i < k; i++)
		need += v[i].first;
	return (need <= s);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k >> s;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= m; i++)
	{
		cin >> tp[i] >> c[i];
	}

	l = 1;
	r = n + 1;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		if (good(mid))
			r = mid;
		else
			l = mid+1;
	}

	if (l == n + 1)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << l << endl;

	good(l);
	for (int i = 0; i < k; i++)
	{
		cout << v[i].second.first << " " << v[i].second.second << "\n";
	}

	cin.get();
	return 0;
}