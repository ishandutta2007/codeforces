#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxk=4010, maxl=110;

int k,n,m;
string s;
int d[maxk][30],bb[30];
bool f[maxk][maxl];



void del(int x, char c) {
	int y=0;
	while (d[y][c-'a']<x) y++;
	if (y) x-=d[y-1][c-'a'];
	for (int i=0; i<m; i++) {
		if (!f[y][i] && s[i]==c) x--;
		if (x==0) {
			f[y][i]=true;
			break;
		}
	}
	for (int i=y; i<k; i++) 
		d[i][c-'a']--;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> k >> s >> n; m=s.length();

	for (int i=0; i<s.length(); i++) bb[s[i]-'a']++;
	for (int i=0; i<k; i++) 
		for (int j=0; j<26; j++) 
			d[i][j]=bb[j]*(i+1);

	for (int i=0; i<n; i++) {
		int x1; char x2;
		cin >> x1 >> x2;
		del(x1,x2);
	}
	
	for (int i=0; i<k; i++) 
		for (int j=0; j<m; j++)
			if (!f[i][j]) cout << s[j];
	return 0;
}