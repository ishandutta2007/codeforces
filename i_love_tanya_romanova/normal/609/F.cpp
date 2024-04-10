/*
Smashing the human horde, crushing religious filth
Nailing invertedly the ones who plant the seeds of doubt
Wasting inherent truth, confronting an inner hell
Cursing subconsciously the ones who reap the seeds of doubt

How can humans play God when all they all are slaves?
Their lack of souls will lead them to an early grave
Condemned to live a life of unrelenting praise
Their rotted corpse remains when death replaces life

Tearing the vocal chords of prophets
That spoke of lies unwanted
They are the ones controlling the seeds of doubt

How can humans play God when all they all are slaves?
Their lack of souls will lead them to an early grave
Condemned to live a life of unrelenting praise
Their rotted corpse remains when death replaces life

Fearing their fate, they chose a random date
When all life would cease and rapture would release
Trampling the meek, the gospel they did speak
Foretelling demise, speaking only lies, lies, lies, lies, lies

Feeding the senseless souls of mindless
Inhabitants not knowing they are the ones consuming the seeds of doubt
Finding the source of stimulation, unnurtured realization
Of fools who will always against their will just end their lives

How can humans play God when all they all are slaves?
Their lack of souls will lead them to an early grave
Condemned to live a life of unrelenting praise
Their rotted corpse remains when death replaces life
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
#define bs 1234567891
#define bsize 512

const int SZ = 410000;

using namespace std;

int n, m;
int orig_x[SZ];
vector<int> xs, ux;
int p[SZ], b[SZ];
int x[SZ];
int t[SZ];
int orig_p[SZ];
int N;
vector<pair<int, int> > events[SZ];
int first_shot[SZ];
multiset<int> active;
multiset<pair<int, int> >alive;
int id_by_x[SZ];
int killed[SZ];
long long ohead[SZ];

void compress()
{
	sort(xs.begin(), xs.end());
	for (int i = 0; i < xs.size(); i++)
	{
		if (i == 0 || xs[i] != xs[i - 1])
			ux.push_back(xs[i]);
	}
}

int get_x(int x)
{
	int id = upper_bound(ux.begin(), ux.end(), x) - ux.begin();
	return id-1;
}

int get_first()
{
	if (active.size() == 0)
		return 1e9;
	multiset<int>::iterator it = active.begin();
	return *it;
}

int T[SZ*4];
int topush[SZ*4];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		T[v] = first_shot[tl];
		topush[v] = 1e9;
		//cout << tl << "^" << tr << " " << T[v] << endl;
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	T[v] = 1e9;
	topush[v] = 1e9;
}

void push(int v)
{
	T[v * 2] = min(T[v * 2], topush[v]);
	T[v * 2 + 1] = min(T[v * 2 + 1], topush[v]);
	topush[v * 2] = min(topush[v * 2], topush[v]);
	topush[v * 2 + 1] = min(topush[v * 2 + 1], topush[v]);
}

int get(int v, int tl, int tr, int ps)
{
	if (tl == tr)
	{
		return T[v];
	}
	push(v);
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		return get(v * 2, tl, tm, ps);
	else
		return get(v * 2 + 1, tm + 1, tr, ps);
}

void update(int v, int tl, int tr, int l, int r, int val)
{
	if (l > r)
		return;
	if (tl == l&&tr == r)
	{
		T[v] = min(T[v], val);
		topush[v] = min(topush[v], val);
		return;
	}
	push(v);
	int tm = tl + tr;
	tm /= 2;
	update(v * 2, tl, tm, l, min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
}

void kill(int A, int B)
{
	//cout << "!" << A << " ^ " << B << endl;

	ohead[A] += b[B];
	killed[A] += 1;
	long long nb = orig_x[A] + ohead[A]+t[A];
	if (nb > 2e9)
		nb = 2e9;
	int rb = get_x(nb);
	update(1, 0, N - 1, x[A], rb, x[A]);
}

bool can_extend(int id)
{
	if (alive.size() == 0)
		return false;
	multiset<pair<int, int> > ::iterator it;
	it = alive.lower_bound(make_pair(x[id], -1));// begin();
	if (it == alive.end())
		return false;
	int ps = (*it).first;
	long long reach = orig_x[id] + ohead[id] + t[id];
	if (reach > 2e9)
		reach = 2e9;
	return (ps <= get_x(reach));
}

void extend(int id)
{
	multiset<pair<int, int> > ::iterator it;
	it = alive.lower_bound(make_pair(x[id], -1));
	int ps = (*it).first;
	int id2 = (*it).second;
	alive.erase(it);
	kill(id, id2);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> t[i];
		orig_x[i] = x[i];
		xs.push_back(x[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> p[i] >> b[i];
		orig_p[i] = p[i];
		xs.push_back(p[i]);
	}

	compress();

	for (int i = 1; i <= n; i++)
		x[i] = get_x(x[i]);
	for (int i = 1; i <= m; i++)
		p[i] = get_x(p[i]);

	for (int i = 1; i <= n; i++)
	{
		id_by_x[x[i]] = i;
	}
	
	/*
	for(int i = 1; i <= n; i++)
	{
		cout << x[i] << "% ";
	}
	cout << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << p[i] << "^ ";
	}
	cout << endl;
	*/

	for (int i = 1; i <= n; i++)
	{
		events[x[i]].push_back(make_pair(-1, i));
		events[get_x(orig_x[i] + t[i])+1].push_back(make_pair(1, i));
		//cout << x[i] << "^" << get_x(orig_x[i] + t[i]) + 1 << endl;

	}

	N = ux.size();

	for (int i = 0; i < ux.size(); i++)
	{
		for (int j = 0; j < events[i].size(); j++)
		{
			int tp = events[i][j].first;
			int id = events[i][j].second;
			if (tp == -1)// open
			{
				active.insert(x[id]);
			}
			else
			{
				active.erase(active.find(x[id]));
			}
		}
		first_shot[i] = get_first();
	}
	/*
	for (int i = 0; i < N; i++)
		cout << ux[i] << " ";
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << first_shot[i] << "^";
	}
	cout << endl;
	*/
	build(1, 0, N-1);

	for (int i = 1; i <= m; i++)
	{
		//cout << "%" << i << endl;

		int kicks = get(1, 0, N-1, p[i]);
//		cout << "%!" << kicks << " "<<p[i]<<endl;
		if (kicks > 1e7)
		{
			alive.insert(make_pair(p[i],i));
			continue;
		}
		
		kicks = id_by_x[kicks];
		//cout << "^" << kicks << "&"<<i<<endl;

		kill(kicks, i);
		while (true)
		{
		//	cout << "@" << kicks<<endl;
			if (can_extend(kicks))
			{
				//cout << "!" << endl;
				extend(kicks);
			}
			else
				break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << killed[i] << " " << ohead[i] + t[i] << "\n";
	}

	cin.get();cin.get();

	return 0;
}