#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 2e9+100500;

map<string, int> index;
int n;
int a, b, c;

int ans1=inf, ans2;

void relax();
int g[10];

int sa[50], sb[50];

void scan();
void solve(int);
void init();

int main()
{
//	freopen("input.txt", "r", stdin);
	init();
	scan();
	solve(0);
	cout << ans1 << " " << ans2;

	return 0;
};
void init()
{
	index["Anka"] = 0;
	index["Chapay"] = 1;
	index["Cleo"] = 2;
	index["Troll"] = 3;
	index["Dracul"] = 4;
	index["Snowy"] = 5;
	index["Hexadecimal"] = 6;
};
void scan()
{
	string p, q;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> s >> q;
		sa[i] = index[p];
		sb[i] = index[q];
//		cout << sa[i] << " " << sb[i] << endl;
	}
	cin >> a >> b >> c;
};
void relax ()
{
	int k[4] = {0,0,0,0};
	for (int i = 0; i < 7; i++)
		k[g[i]]++;
	if (!(k[0] && k[1] && k[2]))
		return;
	int s = 0;
	for (int i = 0; i < n; i++)
		if (g[sa[i]] == g[sb[i]])
			s++;

	int mx, mn;
	mx = max(a/k[0], max(b/k[1], c/k[2]));
	mn = min(a/k[0], min(b/k[1], c/k[2]));
	int d = mx - mn;
	if (d < ans1 || (d == ans1 && s > ans2))
	{
/*		for (int i = 0; i < 7; i++)
			cout << g[i] << " ";*/
//		cout << endl << d << " " << s << endl;	
		ans1 = d, ans2 = s;
	}	
};
void solve(int pos)
{
	if (pos == 7)
		relax();
	else
		for (int i = 0; i < 3; i++)
		{
			g[pos] = i;
			solve(pos+1);
		}	
};