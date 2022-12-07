#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef long long ll;
ll nod[111][111],nok[111][111],key[111];
bool used[111];
int n,m;
vector<int> a;

ll gcd(ll a, ll b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a,b);
}

void dfs(int x) {
	if (!used[x]) {
		used[x] = 1;
		a.push_back(x);
	} else return;
	for (int i=1;i<=n;i++)
		if (!used[i] && nod[x][i] != 0) dfs(i);
}


void doit(int x, ll y) {
	if (y == 0) return;
	key[x] = y;
	for (int i=0;i<a.size();i++)
		if (key[a[i]] == 0 && nod[x][ a[i] ] != 0)
			doit(a[i], nok[x][ a[i] ] * nod[x][ a[i] ] / y );
}

bool check() {
	for (int i=0;i<a.size();i++)
		if (key[a[i]] < 1 || key[a[i]] > 1000000) return 0;
	for (int i=0;i<a.size();i++)
		for (int j=i+1;j<a.size();j++)
			if (nod[ a[i] ][ a[j] ]) {
				ll g = gcd(key[a[i]],key[a[j]]), l = lcm(key[a[i]],key[a[j]]);
				if (g != nod[a[i]][a[j]] || l != nok[a[i]][a[j]]) return 0; 
			}
	return 1;
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);

	
	cin >> n >> m;
	while (m--) {
		int x,y; ll nd,nk;
		cin >> x >> y;
		cin >> nd >> nk;
		nod[x][y] = nod[y][x] = nd;
		nok[x][y] = nok[y][x] = nk;
	}
	
	bool cool = 1;
	for (int i=1;i<=n;i++)
		if (!used[i]) {
			a.clear(); dfs(i);
			if (a.size() == 1) {
				key[a[0]] = 1;
				continue;
			}
			
			ll nd = nod[a[0]][a[1]], nk = nok[a[0]][a[1]];
			nk /= nd; 
			bool ok = 0;
			for (ll k=1;k*k<=nk;k++)
				if (nk % k == 0) {
					doit(a[0],k*nd);
					if (check()) {
						ok = 1;
						break;
					} else for (int j=0;j<a.size();j++) key[a[j]] = 0;
					doit(a[0],nk/k*nd);
					if (check()) {
						ok = 1;
						break;
					} else for (int j=0;j<a.size();j++) key[a[j]] = 0;
				}
			
			if (!ok) {
				puts("NO");
				return 0;
			}
		}
	
	puts("YES");
	for (int i=1;i<=n;i++) cout << key[i] << " ";
	cout << endl;
	
	return 0;
}