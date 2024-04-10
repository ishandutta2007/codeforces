/*
The crescent moon beckons my gaze
Cradling Venus
Behold the evening star

I witness again the sign
The sky - alive

Speaking to me stories of the ancients
The secrets of a bygone age

Bestow the prophecy
The end becoming
Revealing the images
The planets aligning
A concept of a new time
The rapture - commence the end beginning

Visions radiating with wisdom written in the heavenly bodies
The story unfolds - time - the sun descends into the fading sky

A face forming in the clouds
Telling me again the message
Understand my truth is yours
Come before me

Please hear me

The face before me
Now bleeds with fire
As the last glimmers of sunlight
Are seen from beyond

The seed is opening
Time is conceived
The mystery is revealed
A thousand sights unseen

Transformation - envision the beauty within
I awaken - seeing thoughts become form
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
#define escape asdgasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
//#define bs 1234567891
#define bsize 512

const int N = 120000;

using namespace std;

int n, m;
vector<pair<int, int> > v[N];
set<pair<int, int> > active;
vector<int> ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int r, c;
		cin >> r >> c;
		r = n - r + 1;
		if (r > c)
			swap(r, c);
		v[r].push_back(make_pair(c,i));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			active.insert(v[i][j]);
		}
		while (true)
		{
			if (active.size() == 0)
				break;
			pair<int, int> p = *active.begin();
			if (p.first < i)
			{
				active.erase(active.begin());
				continue;
			}
			ans.push_back(p.second);
			active.erase(p);
			break;
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}