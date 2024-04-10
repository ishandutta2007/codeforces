#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n;
string s,t,ans;
int c[1000];

void allbad() {
	cout << -1;
	exit(0);
}

void doeuristic(int x) {
	for (char z='a'; z<='z'; z++) 
		while (c[z]) {
			c[z]--;
			ans[x++]=z;
		}
	cout << ans << endl;
	exit(0);
}

void rec(int x, bool f) {
	if (f) doeuristic(x);
	if (x==s.length()) {
		if (ans>t) {
			cout << ans << endl;
			exit(0);
		} else return;
	}
	if (c[t[x]]) {
		c[t[x]]--;
		ans[x]=t[x];
		rec(x+1,false);
		c[t[x]]++;
	}
	for (char z=t[x]+1; z<='z'; z++)
		if (c[z]) {
			ans[x]=z;
			c[z]--;
			rec(x+1,true);
		}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s >> t;
	ans=s;
	//for (int i=t.length(); i<=s.length(); i++) t+='a';
	//for (int i=s.length(); i<t.length(); i++) s+='a';


	for (int i=0; i<s.length(); i++) 
		c[s[i]]++;
	rec(0,false);
	cout << -1;
	return 0;
}