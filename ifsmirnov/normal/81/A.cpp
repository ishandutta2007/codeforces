#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 200500;
#define forn(i, n) for (int i = 0; i < n; i++)

int prv[maxn];
int nxt[maxn];
string s;
int n;

void go (int);
void scan();

int main()
{
	scan();
	forn(i, n) go(i);
	forn(i, n) if (s[i] != '#') cout << s[i];
/*	cout << endl;
	forn(i, n) cout << nxt[i] << " ";
	cout << endl;
	forn(i, n) cout << prv[i] << " ";*/
};
void scan()
{
	cin >> s;
	n = s.length();
	forn(i, n)	prv[i] = i-1, nxt[i] = i+1;
};
void go (int i)
{
	if (s[i] == '#' || nxt[i] == n || s[i] != s[nxt[i]])
		return;
	s[i] = s[nxt[i]] = '#';
	if (prv[i] != -1)
		nxt[prv[i]] = nxt[nxt[i]];
	if (nxt[nxt[i]] != n)
		prv[nxt[nxt[i]]] = prv[i];
	go(nxt[i]);
	if (prv[i] != -1)
		go(prv[i]);
};