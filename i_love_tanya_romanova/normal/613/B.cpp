/*
Damn the machine
Drilling in the center of my mind
One evil dream
The annihilation of mankind

The stern-faced leaders
In their temple of doom
Creating nightmares
Made for me and for you

Damn the machine
The enemy is stalking in the void
One evil dream
The engine's running faster to destroy

Here come the raiders
They're invading us all
We stand in silence
With our backs to the wall

Once I believed in the voice of a god
The god of creation is gone

A call from the heart to the god of love
Send us an angel, a sign from above
All of the damned and a silent scream
Save us and damn the machine

The curse, foretold in prophecies
Is haunting us now
The world, a creeping agony
And there's no way out

Caught in illusions, I'm screaming in pain
The demon's corroding my brain

A call from the heart to the god of love
Send us an angel, a sign from above
All of the damned and a silent scream
Save us and damn the machine

A call from the heart to the god of love
Send us an angel, a sign from above
All of the damned and a silent scream
Save us and damn

A call from the heart to the god of love
Send us an angel, a sign from above
All of the damned and a silent scream
Save us and damn the machine

Damn the machine
Damn
Damn the machine
*/

//#pragma comment(linker, "/STACK:16777216")
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

const int N = 231231;

using namespace std;

long long n, A, cf, cm, m;
long long starts[N];
vector<pair<int, int> > skills;
long long pref_sum[N];
long long bal[N];
long long ans;
long long ans1, ans2;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> A >> cf >> cm >> m;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		skills.push_back(make_pair(val, i));
		starts[i] = val;
	}


	sort(skills.begin(), skills.end());
	
	for (int i = 0; i < n; i++)
	{
		pref_sum[i + 1] = pref_sum[i] + skills[i].first;
	}

	ans = -100;


	bal[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		bal[i] = 1ll * skills[i - 1].first*i - pref_sum[i];
	}

	for (int mx = n; mx>=0; mx--)
	{
		long long need = 1ll * A*mx - (pref_sum[n] - pref_sum[n - mx]);
		long long rem = m - need;
		if (rem < 0)
			continue;
		
		if (mx == n)
		{
			long long score_here = 1ll * n*cf + A*cm;
			cout << score_here << endl;
			for (int i = 0; i < n; i++)
			{
				if (i)
					cout << " ";
				cout << A;
			}
			cout << endl;
			return 0;
		}

		// bled pref
		int l, r;
		l = 0;
		r = n - mx;
		while (l < r)
		{
			int mid = l + r + 1;
			mid /= 2;
			if (bal[mid] <= rem)
				l = mid;
			else
				r = mid - 1;
		}
		// xct val
		long long take2 = bal[l];
		long long rem2 = rem - take2;
		long long full_units = rem2 / l;
		long long score_here = 1ll * cf*mx + 1ll * (skills[l - 1].first + full_units)*cm;
		if (score_here > ans)
		{
			ans = score_here;
			ans1 = mx;
			ans2 = l;
		}
	}

	cout << ans << endl;// " " << ans1 << " " << ans2 << endl;

	long long need = 1ll * A*ans1 - (pref_sum[n] - pref_sum[n - ans1]);
	long long rem = m - need;
	long long take2 = bal[ans2];
	long long rem2 = rem - take2;

	//cout << "@" << rem2 << " " << ans2 << endl;

	long long full_units = rem2 / ans2;
	//long long ohead = rem2%ans2;
	long long ohead = full_units+skills[ans2 - 1].first;

	for (int i = n - 1; i >= n - ans1; i--)
	{
		int id = skills[i].second;
		starts[id] = A;
	}

	for (int i = 0; i < ans2; i++)
	{
		int id = skills[i].second;
		starts[id] = ohead;
	}

	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << starts[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}