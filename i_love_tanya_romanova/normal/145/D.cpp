/*
Sworn by the crown
I lead a crusade
Fight for belief to be one

Out in the field
Fearless and cold
Building the road to my Calvary

Strong is my steel
Dark is my mind
Carmine the ground that I tread

Faith in my god
Keeps me alive
But when does my faith turn to doubt

Silently watching the rain
Carving the earth on my grave
Lord you know that I prayed
One for the glory
And one for the souls that I've slain

How will I know
How could I tell
Where would I find some serenity

Sowing the seed
Unwounded I bleed
Lord won't you show me the way

Christ is the cross that I bear
God is the will of my war
Faint are the voices I hear
Whispers of glory...

Christ is the cry of despair
Cursing the day I was born
This is the faith that we share
Left with the glory
And suffering of souls that we've torn
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 5000000000000000000ll
#define bsize 512

const int N = 110000;

using namespace std;

set<pair<int, int> > elements;
set<pair<int, int> > ::iterator it;
int n;
int ar[N];
int next_lucky[N], prev_lucky[N];
bool is_lucky[N];
vector<int> luck;
long long ans;
long long BIN[N];
set<int> banned_set;
set<pair<int, int> > seg;
int banned[N];
long long cur_cnt;
long long bin_sum[N];

bool lucky(int x)
{
	if (x == 0)
		return 1;
	if (x % 10 != 4 && x % 10 != 7)
		return 0;
	return lucky(x / 10);
}

void add_segment(int l, int r)
{
//	seg.insert(make_pair(l, r));
	cur_cnt += BIN[r - l + 1];
	cur_cnt %= bs;
}

void remove_segment(int l, int r)
{
//	seg.erase(make_pair(l, r));
	cur_cnt -= BIN[r - l + 1];
	if (cur_cnt < 0)
		cur_cnt += bs;
}

void ban_position(int ps)
{
	set<int>::iterator it;
	it = banned_set.lower_bound(ps);
	int r = (*it);
	--it;
	int l = (*it);
	remove_segment(l + 1, r - 1);
	if (l < ps - 1)
		add_segment(l + 1, ps - 1);
	if (r>ps + 1)
		add_segment(ps + 1, r - 1); 
	banned_set.insert(ps);
}

void show_intervals()
{
	set<pair<int, int> > ::iterator it;
	for (it = seg.begin(); it != seg.end(); ++it)
	{
		pair<int, int> P = (*it);
		cout << P.first << " " << P.second << endl;
	}
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	for (int i = 1; i <= 100000; i++)
		BIN[i] = (i + 1) * 1ll * i / 2,
		BIN[i] %= bs;

	for (int i = 1; i <= 100000; i++)
	{
		bin_sum[i] = bin_sum[i - 1] + BIN[i];
		bin_sum[i] %= bs;
	}
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		elements.insert(make_pair(ar[i], i));
		if (lucky(ar[i]))
		{
			is_lucky[i] = 1;
			luck.push_back(i);
		}
	}

	next_lucky[n + 1] = n + 1;
	for (int i = n; i; --i)
	{
		if (is_lucky[i])
			next_lucky[i] = i;
		else
			next_lucky[i] = next_lucky[i + 1];
	}

	// R is empty

	for (int i = 1; i <= n; i++)
	{
		int cnt1 = next_lucky[i] - i;
		ans += cnt1*BIN[i - 1] % bs,
			ans %= bs;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (is_lucky[i])
			prev_lucky[i] = i;
		else
			prev_lucky[i] = prev_lucky[i - 1];
	}

	// R wth insd
	for (int i = 0; i < luck.size(); i++)
	{
		int id = luck[i];
		seg.clear();
		cur_cnt = 0;
		add_segment(1, id - 1);
		for (int j = 0; j < luck.size(); j++)
			banned[j] = 0;

		banned_set.clear();
		banned_set.insert(id);
		banned_set.insert(0);

		for (int j = i; j < luck.size(); j++)
		{
			int id = luck[j];
			int val = ar[id];
			int pp = -1;
			while (true)
			{
				pair<int, int> P = make_pair(val, pp + 1);
				it = elements.lower_bound(P);
				if (it == elements.end())
					break;
				pair<int, int> P2 = (*it);
				if (P2.first != P.first)
					break;
				if (P2.second >= luck[i])
					break;
				if (banned_set.find(P2.second) != banned_set.end())
					break;
				ban_position(P2.second);
				pp = P2.second;
			}

			int bound = n + 1;
			if (j + 1 < luck.size())
				bound = luck[j + 1];
			long long ways = cur_cnt;
			int prev = 0;
			if (i)
				prev = luck[i - 1];
			ways = ways *(luck[i] - prev) % bs;
			
			// subtr ohead now
			set<int>::iterator it;
			it = banned_set.lower_bound(luck[i]);
			int Q1, Q2;
			
			if (it == banned_set.begin())
				Q1 = 0;
			else
			{
				--it;
				Q1 = (*it);
			}

			Q2 = luck[i];

			ways -= (BIN[Q2 - Q1 - 1])*(luck[i]-prev) % bs;
			if (ways < 0)
				ways += bs;

			int cut;
			if (i == 0)
				cut = 0;
			else
				cut = luck[i - 1];

//			cout << endl << endl;

	///		cout << ways << "&"<<cut<<endl;

			ways += bin_sum[Q2 - Q1-1] - bin_sum[cut - Q1-1];
			ways %= bs;
			if (ways < 0)
				ways += bs;

			ways = ways*(bound - luck[j]) % bs;;
			ans += ways;
			ans %= bs;

		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}