#pragma comment(linker, "/STACK:64000000")
#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();
//#define FILE "inequality"
int main ()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    //cout<<FILE<<endl;
#else
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif
    solve();
    return 0;
}

//#define int li
int n;

//pair <int, int> r[100500];

set < pair <int, int> > m;
map <int, int> mm;
vector <vector <int> > answer;

void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		{
			int q;
			cin>>q;
			mm[q]++;
		}
	for (map <int, int>::iterator i=mm.begin(); i!=mm.end(); i++)
		m.insert ( mp (-(i->second), i->first) );

	while (m.size()>0)
	{
		pair <int, int> cur1=*(m.begin());
		m.erase(m.begin());
		if (m.size()==0)
			break;
		pair <int, int> cur2=*(m.begin());
		m.erase(m.begin());
		if (m.size()==0)
			break;
		pair <int, int> cur3=*(m.begin());
		m.erase(m.begin());

		vector <int> cur;
		cur.pb (cur1.second);
		cur.pb (cur2.second);
		cur.pb (cur3.second);
		answer.pb (cur);

		cur1.first++; cur2.first++; cur3.first++;

		if (cur1.first!=0)
			m.insert (cur1);
		if (cur2.first!=0)
			m.insert (cur2);
		if (cur3.first!=0)
			m.insert (cur3);
	}

	cout<<answer.size()<<endl;

	for (int i=0; i<answer.size(); i++)
	{
		sort (answer[i].begin(), answer[i].end());
		reverse (answer[i].begin(), answer[i].end());
		for (int j=0; j<answer[i].size(); j++)
			cout<<answer[i][j]<<' ';
		cout<<endl;
	}
}