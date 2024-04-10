/*
I see destruction as it rages through your veins
I see depression as it fills your heart with pain
I see the cure you found for artificial peace
I see your body rot, your solution now has it's feast

And now I look, I look in your eyes
Looking in your eyes, in your eyes
Looking in your eyes

What I see in your eyes
I can see, they tell no lies
Looking in your eyes
I see salvation oh so close but yet so far

I see the glimmering of the holy star
I see your future, it's a nightmare and a lie
But you refused my help
Now I have no more strength to try

Now I see, I see the lies
Looking in your eyes
In your eyes I see the lies

What I see in your eyes
Well, I can see, you tell no lies
Looking in your eyes
Looking through my eyes

Well, I would die for you
I've died enough now I'm through
But one day you will see
What won't but what should B T F, please stay
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
//#define bs 1234567891
#define bsize 512

const int T = 500000;

using namespace std;

int n;
int a[T], b[T], c[T], d[T];
vector<int> xs, ys;
pair<int, int> t[T * 4];
map<int, int> mapp;
vector<int> ux;
set<pair<int, pair<int, int> > > pts;
queue<int> qu;
int N;
int dist[T];
int par[T];

pair<int, int> better(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first)
		return p1;
	return p2;
}

void update(int v, int tl, int tr, int ps, int val,int id)
{
	if (tl == tr)
	{
		t[v] = make_pair(val, id);
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		update(v * 2, tl, tm, ps, val, id);
	else
		update(v * 2 + 1, tm + 1, tr, ps, val, id);
	t[v] = better(t[v * 2], t[v * 2 + 1]);
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		set<pair<int, pair<int, int> > >::iterator it;
		it = pts.lower_bound(make_pair(tl, make_pair(-1, -1)));
		pair<int, pair<int, int> > p = *it;
		if (p.first != tl)
		{
			t[v] = make_pair(1234567890, -1);
		}
		else
		{
			t[v] = p.second;
		}
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = better(t[v * 2], t[v * 2 + 1]);
}

void remove_point(int id)
{
	update(1, 1, N, a[id], 1234567890, -1);
	set<pair<int, pair<int, int> > >::iterator it;
	pts.erase(make_pair(a[id], make_pair(b[id], id)));
	it = pts.lower_bound(make_pair(a[id], make_pair(b[id], id)));

	if (it == pts.end())
		return;
	int next_id = (*it).second.second;
//	cout << "@" << next_id << " " << a[next_id] << " "<<a[id]<<endl;
//	cin.get();

	if (a[next_id] == a[id])
	{
		update(1, 1, N, a[id], b[next_id],next_id);
	}
}

pair<int, int> get(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return make_pair(1234567890, -1);
	if (tl == l&&tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	return better(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		xs.push_back(a[i]);
		xs.push_back(c[i]);
	}

	sort(xs.begin(), xs.end());
	for (int i = 0; i < xs.size(); i++)
	{
		if (i>0 && xs[i] == xs[i - 1])
			continue;
		ux.push_back(xs[i]);
		mapp[xs[i]] = ux.size();
	}

	for (int i = 1; i <= n; i++)
	{
		a[i] = mapp[a[i]];
		c[i] = mapp[c[i]];
	}

	N = ux.size();

	for (int i = 1; i <= n; i++)
	{
		pts.insert(make_pair(a[i], make_pair(b[i],i)));
	}

	build(1, 1, N);

	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1 && b[i] == 0)
		{
			dist[i] = 0;
			qu.push(i);
			remove_point(i);
		}
	}

	while (qu.size())
	{
		int id = qu.front();
		qu.pop();
		//cout << "!" << id << endl;

		while (true)
		{
			pair<int, int> p = get(1, 1, N, 1, c[id]);
			//cout << "!" << p.first << "$" << p.second << endl;
			//cin.get();
			if (p.first > d[id])
			{
				break;
			}
			remove_point(p.second);
			par[p.second] = id;
			dist[p.second] = dist[id] + 1;
			qu.push(p.second);
		}
	}

	/*for (int i = 1; i <= n; i++)
		cout << par[i] << " " << " " << dist[i] << endl;
	cin.get();
	*/
	if (dist[n] > 1e6)
	{
		cout << -1 << endl;
		return 0;
	}


	vector<int> ans;

	while (par[n]!=0)
	{
		ans.push_back(n);
		n = par[n];
	}
	ans.push_back(n);
	reverse(ans.begin(), ans.end());
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