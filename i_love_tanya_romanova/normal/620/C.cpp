/*
Kings of agony
Walking on my way
Moon is shining bright
Murder and pain
Went the demons gate
Rotten flesh around
Sinners meet their fate
Lying on the ground

Bloody corpse, Bloody corpse
Bloody corpse, Bloody corpse

I got the power
Revenge is mine
That will be my faith
Destroy your life
Lords of raging storm
Piles of useless flesh
Immortality
See the face of dead

Bloody corpse, Bloody corpse
Bloody corpse, Bloody corpse

I always want the sacrifice
You can see it in my eyes
Driving on a fatal trail
I am the messenger of hell
Slaughtered by the holy sword
Master of the universe
Rituals of death and fear
Born by evils hands

I don't believe in
Resurrection of God
Beyond death
And uncontrolled
Sitting close to Satan
Spreading tears and blood
No prayers for the innocent
The final work is done

Bloody corpse, Bloody corpse
Bloody corpse, Bloody corpse

I can't escape your lazy face
Buried in an ice cold grave
Captured by this nightmares end
From the kingdom of the damned
I am the reaper ans I'm God
Mourning cries from far beyond
A world you never realize
Within the hell inside

Bloody corpse
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600000;

using namespace std;

int n, ar[N];
vector<int> v;
map<int, int> cnt;
int cut;
vector<pair<int, int> > ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		v.push_back(ar[i]);
	}

	int found = 0;

	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
			found = 1;
	}

	if (!found)
	{
		cout << -1 << endl;
		return 0;
	}

	cut = 1;

	for (int i = 1; i <= n; i++)
	{
		if (cnt[ar[i]])
		{
			cnt.clear();
			ans.push_back(make_pair(cut, i));
			cut = i + 1;
		}
		else
		{
			cnt[ar[i]]++;
		}
	}

	if (cut != n + 1)
	{
		ans[ans.size() - 1].second = n;
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	cin.get(); cin.get();
	return 0;
}