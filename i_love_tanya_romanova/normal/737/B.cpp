/*
I've been trying to deny it
Oh what to do
When I'm such a fool for you

I want you
So bad I want you
I want to hold you babe you look away what did I say?
I want you

For better or for worse
I will make you mine
Each warm heart gets cold in time
I'll follow like a shadow
You won't get through
The web I have spun for you

I want you
So bad I want you
I want to hold you babe you look away what did I say?
I want you
So bad I want you
I watch each step you take I will not bend I will not break

I want you bad
I want your innocence
I want your bitterness your loneliness
I want you (I want you)

I want you bad
I want your innocence
I want your every breath in life or death I want you

No one could see it coming
A tragic day (a tragic day)
How did that car get in your way?

I got you
At last I got you
She'll never see your face forever bound in my embrace

I got you
At last I got you
She'll never send you thrills if I can't have you no one will
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

int n, a, b, k;
string st;
int cnt, cur_len;
vector<pair<int,int> > segs;

vector<int > ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> a >> b >> k;

	cin >> st;
	st = st + "1";

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '1')
		{
			if (cur_len)
				segs.push_back(make_pair(i - cur_len, i - 1));
			cnt += cur_len / b;
			cur_len = 0;
		}
		else
			++cur_len;
	}

	/*for (int i = 0; i < segs.size(); i++)
	{
		cout << segs[i].first << " " << segs[i].second << endl;
	}
	*/
	while (cnt >= a)
	{
		pair<int, int> cur_seg = segs.back();
		segs.pop_back();
		if (cur_seg.second - cur_seg.first + 1 < b)
			continue;
		ans.push_back(cur_seg.second - b + 2);
		cur_seg.second = ans.back() - 2;
		segs.push_back(cur_seg);
		--cnt;
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