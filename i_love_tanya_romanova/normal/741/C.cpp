/*
No one knows what draws the moth to the flame
And nothing costs as much as playing the game
She had to know, know, know... he'd give love for sex
He had to know, know, know... she'd give sex for love

The taste, touching his tongue, sweet to his lips
Poison, now penetrating deeper
Betrayed by just one bite, for just one night
To find forbidden fruit tastes sweeter

Just like pressing a loaded gun to your head
One knows only the spider can navigate its web
She had to know, know, know... he'd get what he wants
He had to know, know, know... she'd get what she needs

Soon under the spell, emotions are high
Mind control penetrating deeper
The hex was cast on him, all he believes
Now is forbidden fruit tastes sweeter

She had to know, know, know... he'd win at the start
He had to know, know, know... she'd win in the end

His one last thought blew his mind, bullet to the brain
Hot lead was penetrating deeper
Just one reckless shot squeezed from the hand
That knows forbidden fruit tastes sweeter
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 302231;

int n;
int paired[N];
int ans[N];

vector<pair<int, int> > order;

int get(int ps)
{
//	cout << ps << endl;
	return ans[(ps+2*n) % (2 * n)];
}

bool bad_position(int ps)
{
	if (get(ps + 1) != get(ps) || get(ps + 2) != get(ps))
		return false;
	return true;
}

void run_fix(int ps)
{
	//cout << ps << endl;
	if (ps < 0)
		ps += 2 * n;

	/*for (int i = 0; i < n * 2; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	*/
	int whr = rand() % 3;
	int T = ps + whr;
	T %= 2 * n;
	ans[T] ^= 1;
	ans[paired[T]] ^= 1;
	for (int j = T - 2; j <= T; j++)
	{
		if (bad_position(j))
			run_fix(j);
	}
	for (int j = paired[T] - 2; j <= paired[T]; j++)
	{
		if (bad_position(j))
			run_fix(j);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	vector<int> oorder;
	for (int i = 0; i < n * 2; i++)
	{
		oorder.push_back(i);
	}
	random_shuffle(oorder.begin(), oorder.end());
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		/*a = oorder[i * 2 - 2];
		b = oorder[i * 2 - 1];
		*/
		order.push_back(make_pair(a, b));
		paired[a] = b;
		paired[b] = a;
	}

	for (int i = 0; i <= n * 2; i++)
	{
		ans[i] = -1;
	}
	for (int i = 0; i < n * 2; i++)
	{
		if (ans[i] == -1)
		{
			int othr = paired[i];
			int val = rand() % 2;
			ans[i] = val;
			ans[othr] = 1 - val;
		}
	}

	for (int iter = 1; iter <= 3;iter++)
	for (int i = 0; i < 2 * n; i++)
	{
		if (bad_position(i))
		{
			run_fix(i);
		}
	}

	/*
	for (int i = 0; i < n * 2; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	*/
	for (int i = 0; i < order.size(); i++)
	{
		cout << ans[order[i].first]+1 << " " << ans[order[i].second]+1 << "\n";
	}

	cin.get(); cin.get();
	return 0;
}