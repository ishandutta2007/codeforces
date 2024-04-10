/*
It ain't always merry to notice there's a line?
Life was kinda scary when you are left behind
All the loved ones lost to you
Used to be somewhere
You know you will follow too
And you dont really care to just go nowhere
(Just go nowhere)

And so you keep them all alive
(In your head)
I told you I know the Reaper
No light and no eternal life
(What I said?)
I told you I know the Reaper

Sweetest of all lies,
One of everlasting life.
No one wants to die,
But we do, so we hide.
What you fail to realize
Is there's no need to fear
You live on in hearts and minds
Of those who hold you dear who are right here
(Right here)

And so you keep them all alive
(In your head)
I told you I know the Reaper
No light and no eternal life
(What I said?)
I told you I know the Reaper

(All the others)
They already know the Reaper
(All the others)
They already know the Reaper

And so you keep yourself alive
(In your head)
You dont want to know the Reaper
(All the others)
No light and no eternal life
(What I said?)
I told you I know the Reaper
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

const int N = 205000;

using namespace std;

int n, m, d, a, b;
vector<pair<int, int> > v;
multiset<pair<int, int> > F;
multiset<pair<int, int> > ::iterator it;
int cap;
long long ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> d >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	v.push_back(make_pair(0, 0));
	
	v.push_back(make_pair(d, 1e9));

	sort(v.begin(), v.end());

	cap = n;

	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i].first<<" "<<i << "%" << ans << endl;

		/*cout << i << ": " << endl;
		for (it = F.begin(); it != F.end(); it++)
		{
			cout << (*it).first << " " << (*it).second << endl;
		}
		*/
		if (i>0)
		{
			int span = v[i].first - v[i - 1].first;
			if (span > n)
			{
				cout << -1 << endl;
				return 0;
			}
			while (span > 0)
			{
				//cout << span << endl;

				//cout << "@" << F.size() << " "<<i<<endl;
				it = F.begin();
				pair<int, int> p = (*it);
				F.erase(it);
				int can_spend = min(p.second, span);
				cap += can_spend;
				//ans += 1ll * p.first*can_spend;
				p.second -= can_spend;
				span -= can_spend;
				if (p.second)
					F.insert(p);
				//cout << i<<" "<<span << " "<<p.second<<" "<<can_spend<<endl;
			}
		}

		//cout << cap << "$" << ans << endl;
		while (true)
		{
			if (F.size() == 0)
				break;
			it = F.end();
			--it;
			pair<int, int> p = (*it);
			if (p.first > v[i].second || i == v.size() - 1)
			{
				F.erase(it);
				cap += p.second;
				ans -= 1ll * p.first*p.second;
			}
			else
				break;
		}

		if (cap > 0 && i + 1 < v.size())
		{
			ans += 1ll * v[i].second*cap;
			F.insert(make_pair(v[i].second, cap));
			cap = 0;
		}

	}
	
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}