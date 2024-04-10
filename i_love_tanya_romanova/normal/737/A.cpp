/*
Happy tears fade fast
Sad tears tend to last
You've got your blood-stained heart
In your nicotine-stained hands
And your twenty-nine years
Did not help you pass
Oh, the roadkill, cheap thrill
Obstacle filled path

White lies, black dress
Brightest of darkness
You close your tearstained eyes
To our silver lined madness
After twenty-nine years
You might want to confess
That we have made
A fucked-up place
That I can not erase

Sing to me
Sing to me
Sing to me
Sing to me

White lies, black heart
Tearing us apart
You breathe the frost-filled air
From my lungs to your lungs
After twenty-nine years
How much more to come?
Let, we have made
A fucked-up place
That I can not erase

Sing to me
Sing to me
Sing to me
Sing to me

Happy tears fade fast
Sad tears tend to last
You've got a sad, sad song
Stuck in your aching head
And your twenty-nine years
Did not teach you that
Changing melodies
Will change your destiny at last
Now, we have made
A fucked-up place
We're trying to erase
Erase

Sing to me
Sing to me
Sing to me
Sing to me
*/

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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 500031;

int n, k, s, t;
int c[N], v[N];
int ps[N];
vector<int> segs;
long long ans;

long long suf_sum[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k >> s >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> v[i];
	}

	for (int i = 1; i <= k; i++)
	{
		cin >> ps[i];
	}

	sort(ps + 1, ps + k + 1);
	ps[0] = 0;
	ps[k + 1] = s;

	segs.clear();

	for (int i = 1; i <= k + 1; i++)
	{
		segs.push_back(ps[i] - ps[i - 1]);
	}


	sort(segs.begin(), segs.end());

	suf_sum[segs.size()] = 0;
	for (int i = segs.size() - 1; i >= 0; --i)
		suf_sum[i] = suf_sum[i + 1] + segs[i];

	ans = 1e18;

	/*for (int i = 0; i < segs.size(); i++)
	{
		cout << segs[i] << " ";
	}
	cout << endl;
	*/

	for (int i = 1; i <= n; i++)
	{
		if (v[i] < segs.back())// damn
			continue;
		if (c[i] >= ans)
			continue;
		int default_time = s;

		int first_bad, bad_ohead;

		if (v[i] % 2 == 0)
		{
			int first_bad = lower_bound(segs.begin(), segs.end(), v[i] / 2) - segs.begin();
			long long bad_ohead = suf_sum[first_bad];
			long long torem = (segs.size() - first_bad) * 1ll * (v[i] / 2);
			bad_ohead -= torem;
			//cout << torem << "%" << bad_ohead << endl;
			default_time += 2 * bad_ohead;
		}
		else
		{
			int first_bad = lower_bound(segs.begin(), segs.end(), v[i] / 2+1) - segs.begin();
			long long bad_ohead = suf_sum[first_bad];
			long long torem = (segs.size() - first_bad) * 1ll * (v[i] / 2+1);
			bad_ohead -= torem;
			default_time += 2 * bad_ohead;
			default_time += (segs.size() - first_bad);
			//cout << first_bad << "%" << bad_ohead << endl;
		}
		//cout << default_time << endl;
		if (default_time <= t)
			ans = c[i];
	}

	if (ans>1e15)
		ans = -1;
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}