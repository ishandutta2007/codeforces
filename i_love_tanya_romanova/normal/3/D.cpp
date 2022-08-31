/*
Something inside the cards
I know is right
Don't want to live
Somebody else's life
This is what I want to be
And this is what I give to you
Because I get it free
She smiles while I do my time

I could die for you
Oh this life I choose

I'm here to be your only go-between
To tell you of the sights
These eyes have seen
What I really want to do is
Turn it into motion
Beauty that I can't abuse
You know that I'd use my senses to
You can see that
It's only everywhere
I'd take it all and then
I'd find a way to share

Come along and go
Along with me
Wander with me yo
It's all for free

I could die for you
Whatchu wanna do
Oh this life I choose

Come again and tell me
Where you want to go
What it means for me
To be with you alone
Close the door and
No one has to know
How we are

Come along and go
Along with me
Wander with me yo
It's all for free

I could die for you
Whatchu want to do
Oh this life I choose
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 500031;

string st;
int cnt;

vector<pair<int, int> > v;
set<pair<int, int> > S;
set<pair<int, int> > ::iterator it;
int bal;
long long res;
int a[N], b[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '?')
			++cnt;
	}
	for (int i = 0; i < cnt; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	reverse(v.begin(), v.end());

	int bal = 0;

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '(')
		{
			bal += 1;
			continue;
		}
		if (st[i] == ')')
		{
			bal -= 1;
		}
		else
		{
			bal -= 1;
			st[i] = ')';
			a[i] = v.back().first;
			b[i] = v.back().second;
			v.pop_back();
			S.insert(make_pair(a[i] - b[i], i));
			res += b[i];
		}
		if (bal < 0)
		{
			if (S.size() == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			it = S.begin();
			bal += 2;
			int v = (*it).second;
			int cost = (*it).first;
			S.erase(it);
			res += cost;
			st[v] = '(';
		}
	}

	if (bal != 0)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << res << endl;
	cout << st << endl;

	cin.get(); cin.get();
	return 0;
}