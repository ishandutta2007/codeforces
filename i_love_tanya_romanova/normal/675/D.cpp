/*
She wasn't a fool
That glittering girl
She followed the rules
That shimmering pearl

Said the rules mama preaches
Go down when they break
The themes mama teaches
You just gotta shake

But she wasn't a fool
That slender love figure
She followed her rules
And made money bigger

She wasn't a fool
That shining young woman
She followed her rules
She's crying for no man

Said the rules mama preaches
Go down when they're broken
She explodes into peaches
And cries when I've spoken

She wasn't a fool
That Goddess of Hell
There are no mother's rules
She makes them herself

And I was down upon my knees
To beg her surrender up to me

Something inside her
Told her she shouldn't
Tried and alight her
But the girl wouldn't

She wasn't a fool
But love flowed from her face
She's not scared of me
She's afraid of disgrace

She wasn't a fool
That female for our world
She followed her rules
That glittering girl
That glittering girl
That glittering girl
That glittering girl
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
set<pair<int, int> > A;
set<pair<int, int> > ::iterator it;
int ar[N];

pair<int,int> get(int val,int flag)
{
	it = A.lower_bound(make_pair(val, -100));
	if (flag)
		--it;
	return (*it);
}
int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	A.insert(make_pair(-bs, -1));
	A.insert(make_pair(bs, -1));

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	A.insert(make_pair(ar[1], 1));
	
	for (int i = 2; i <= n; i++)
	{
		if (i > 2)
			cout << " ";
		pair<int, int> p1 = get(ar[i],0);
		pair<int, int> p2 = get(ar[i],1);
		if (p1.second < p2.second)
			cout << p2.first;
		else
			cout << p1.first;
		A.insert(make_pair(ar[i], i));
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}