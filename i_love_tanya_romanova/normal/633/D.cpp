/*
With a cocked and loaded gun and the girl of my dreams
I can't control myself know what I mean
I had one too many pills now I'm high on sextasy
Yeah I'm a supercharged hot blooded sex machine

Armed and dangerous
Better hold on tight
I'm armed and dangerous
All through the night
Armed and dangerous
Oh feel my snake bite yeah
I'm armed and dangerous
Better hold on tight alright

I'm just checking her oil and stirring up her cream
Bringin' her, to the boil making her jump and scream
Say, the longer I go honey the longer I get
And if I run out of ammo I just use my bayonet

Armed and dangerous
Better hold on tight
I'm armed and dangerous
All through the night
Armed and dangerous
Oh feel my snake bite yeah
I'm armed and dangerous
Better hold on tight all right alright

I'm armed and dangerous
I'm armed and dangerous
I'm armed and dangerous
Like a bullet like a bomb I'll take you on

Armed and dangerous
Better hold on tight
I'm armed and dangerous
All through the night
Armed and dangerous
Oh feel my snake bite yeah
I'm armed and dangerous
Better hold on tight alright
Cause I'm armed
I'm armed, I said I'm armed,
I said I'm armed and dangerous alright

Armed and dangerous
Better hold on tight
I'm armed and dangerous
All through the night
Armed and dangerous
Oh feel my snake bite

I'm armed and dangerous
All through the night alright

I'm armed and dangerous
I'm armed and dangerous
Sextasy
I'm armed and dangerous
I'm gonna give to you
I'm armed and dangerous
All through the night
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
#define bsize 512

const int N = 1010;

using namespace std;

int n, a[N];
multiset<int> S;
set<pair<int, int> > did;
int ans;
vector<int> v;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
		S.insert(a[i]);

	for (int v1 = 0; v1 < n; v1++)
	{
		for (int v2 = 0; v2 < n; v2++)
		{
			if (v1 == v2)
				continue;
			if (did.find(make_pair(a[v1], a[v2])) != did.end())
				continue;
			did.insert(make_pair(a[v1], a[v2]));

			S.erase(S.find(a[v1]));
			S.erase(S.find(a[v2]));
			v.clear();
			v.push_back(a[v1]);
			v.push_back(a[v2]);
			while (true)
			{
				int val = v[v.size() - 2] + v[v.size() - 1];
				if (S.find(val) == S.end())
					break;
				S.erase(S.find(val));
				v.push_back(val);
			}
			if (v.size() > ans)
				ans = v.size();
			for (int i = 0; i < v.size(); i++)
				S.insert(v[i]);
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}