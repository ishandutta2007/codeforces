#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#define tr(c, it) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
using namespace std;

struct state
{
	int h, g, r, s;
	state () {h=g=r=s=0;};
	state (int H, int G, int R, int S):s(S),r(R),g(G),h(H){};
	bool operator== (const state &a) const
	{
		return h == a.h && g == a.g && r == a.r && s == a.s;
	};
	bool operator< (const state& a) const
	{
		if (h < a.h) return true;
		else if (h > a.h) return false;
		else if (g < a.g) return true;
		else if (g > a.g) return false;
		else if (s < a.s) return true;
		else if (s > a.s) return false;
		else if (r < a.r) return true;
		else return r > a.r;
	};	
	void p () const
	{
		cout<<h<< " " << g << " " << r << " " << s << endl;
	}	
};

int n;
char a[10010];
set<state> cur, nxt;

void solve();

int main()
{
/*	cout<<"FILES!!!!!"<<endl;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	cin >> n >> a;

	solve();

	return 0;
};

void solve()
{
	state t;
	nxt.insert(t);
	int mn;
	for (int i = 0; i < n; i++)
	{
/*		cout << "Etap " << i << endl;
		tr(nxt, it) it->p();*/
//		cout<<endl;
		cur.swap(nxt);
		nxt.clear();
		for (set<state> :: iterator it = cur.begin(); it != cur.end(); it++)
		{
			t = *it;
			if (a[i] == 'H')
			{
				t.h++;
				nxt.insert(t);
			}
			else if (a[i] == 'R')
			{
				t.r++;
				nxt.insert(t);
			}
			else if (a[i] == 'G')
			{
				t.g++;
				nxt.insert(t);
			}
			else if (a[i] == 'S')
			{
				t.s++;
				nxt.insert(t);
			}
			else
			{
				mn = min(min(t.s, t.h), min(t.g, t.r));
				if (t.s == mn)
				{
					t.s++;
					nxt.insert(t);
					t.s--;
				}
				if (t.g == mn)
				{
					t.g++;
					nxt.insert(t);
					t.g--;
				}
				if (t.h == mn)
				{
					t.h++;
					nxt.insert(t);
					t.h--;
				}
				if (t.r == mn)
				{
					t.r++;
					nxt.insert(t);
					t.r--;
				}	
			}
		}
	}	

	bool g=0,h=0,r=0,s=0;
	for (set<state> :: iterator it = nxt.begin(); it != nxt.end(); it++)
	{
		t = *it;
		mn = min(min(t.s, t.h), min(t.g, t.r));
		if (t.s == mn) s=1;
		if (t.h == mn) h=1;
		if (t.g == mn) g=1;
		if (t.r == mn) r=1;
	}
	if (g) cout<<"Gryffindor\n";
	if (h) cout<<"Hufflepuff\n";
	if (r) cout<<"Ravenclaw\n";
	if (s) cout<<"Slytherin\n";	
};