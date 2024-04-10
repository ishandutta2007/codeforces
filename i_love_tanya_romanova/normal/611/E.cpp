/*
Ooo
I can't get up, nerve to call you
But I want to call so bad
To find out, who's holding on to
The most beautiful thing I ever had
I reach to pull you closer
And remember you're not there

Let it rain
(Rain)
Oh, let it rain down on me
To hide these tears, I'm crying
So no one can see
That I'm still not over you
But if you're over me
Let it rain
(Let it rain)
Let it rain down on me, here

Used to lay
(Lay)
Together like spoons
Was the only way I could sleep
And this pillow
(Pillow)
Is a poor substitute

For your body next to me
Babe I guess I never really took the time
To show how much I care

Let it rain
(Rain, hhh)
Let it rain down on me
To hide these tears, I'm crying
So no one can see
That I'm still not over you
(Ohh)
But if you're over me
(Ohh)
Let it rain
(Let it rain)
Let it rain down on me
(Let)

The rain is not so bad after all
It camouflages every tear that falls
It cleanses me of all the blame
I've put upon myself
I hear you're married now
Well I hope he treats you well
Let it rain

Ohh let it rain
Let it rain down on me
Ohh hide these tears, I'm crying
So no one can see
That I'm still not over you
(Ohh)
But if you're over me
(Ohh)
Please let it rain
(Let it rain)
Oh, let it rain down on me
I can't get up, nerve to call you
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 250050;

using namespace std;

int lev[N];
int n;
int ar[N];
multiset<int> S;
int ans;
multiset<int>::iterator it;
int val;

pair<int, int> try3()
{
	if (val > lev[2])
		return make_pair(-1, -1);

	pair<int, int> P = make_pair(-1, -1);
	multiset<int>::iterator it1, it2;
	it1 = S.upper_bound(lev[1]);
	if (it1 == S.begin())
	{
		return P;
	}
	--it1;
	P.first = (*it1);
	S.erase(it1);
	
	it2 = S.upper_bound(lev[0]);
	if (it2 == S.begin())
	{
		return P;
	}
	--it2;
	P.second = (*it2);
	S.erase(it2);
	return P;
}

int try2()
{
	int thold = 0;
	if (val <= lev[2])
		thold = max(thold, lev[1] + lev[0]);
	if (val <= lev[1])
		thold = max(thold, lev[0] + lev[2]);
	if (val <= lev[0])
		thold = max(thold, lev[1] + lev[2]);
	if (val <= lev[0] + lev[1])
		thold = max(thold, lev[2]);
	if (val <= lev[0] + lev[2])
		thold = max(thold, lev[1]);
	if (val <= lev[1] + lev[2])
		thold = max(thold, lev[0]);

	multiset<int> ::iterator it;
	it = S.upper_bound(thold);
	if (it == S.begin())
		return -1;
	--it;
	int cur = (*it);
	S.erase(it);
	return cur;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> lev[i];
	}
	sort(lev, lev + 3);
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	
	sort(ar, ar + n);
	
	// S H
	if (ar[n - 1]>lev[0] + lev[1] + lev[2])
	{
		cout << -1 << endl;
		return 0;
	}

	// have a solution

	for (int i = 0; i < n; i++)
		S.insert(ar[i]);

	while (S.size())
	{
		ans++;

		it = S.end();
		--it;
		val = (*it);
		S.erase(it);

		// 3 guys
		pair<int, int> P = try3();
		//cout << P.first << "#" << P.second << endl;

		if (P.first != -1 && P.second != -1)
		{
			continue;
		}
		if (P.first != -1)
			S.insert(P.first);
		if (P.second != -1)
			S.insert(P.second);

		// 2 guys
		int Q = try2();

		if (Q != -1)
		{
			continue;
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}