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

struct item {
	string s;
	int score,win,lose,games;
	item () : score(0), win(0), lose(0), games(0) {}
	bool operator<(const item &i) {
		if (score > i.score) return 1; else if (score==i.score)
		if (win-lose > i.win-i.lose) return 1; else if (win-lose==i.win-i.lose)
		if (win > i.win) return 1; else if (win==i.win)
		if (s < i.s) return 1;
		return 0;
	}
};

const int maxn=100100;

int ansx=100,ansy=0;
string cs,berland="BERLAND";
map<string,item> mp;

bool win(int x, int y) {
	mp[berland].win+=x;
	mp[berland].lose+=y;
	mp[cs].win+=y;
	mp[cs].lose+=x;

	vector<item> v;
	for (map<string,item>::iterator it=mp.begin(); it!=mp.end(); it++) 
		v.push_back(it->second);
	sort(v.begin(),v.end());

	mp[berland].win-=x;
	mp[berland].lose-=y;
	mp[cs].win-=y;
	mp[cs].lose-=x;

	if (v[0].s==berland || v[1].s==berland) return true;
	else return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i=0; i<5; i++) {
		string s1,s2;
		int k1,k2;
		cin >> s1 >> s2;
		scanf("%d:%d",&k1,&k2);
		mp[s1].score+=3*(k1>k2)+(k1==k2);
		mp[s2].score+=3*(k1<k2)+(k1==k2);
		mp[s1].win+=k1; mp[s1].lose+=k2;
		mp[s2].win+=k2; mp[s2].lose+=k1;
		mp[s1].games++; mp[s2].games++;
		mp[s1].s=s1; mp[s2].s=s2;
	}
	for (map<string,item>::iterator it=mp.begin(); it!=mp.end(); it++) if (it->second.games<3 && it->first!="BERLAND")
		cs=it->first;
	mp[berland].score+=3;

	for (int x=0; x<30; x++) {
		for (int y=0; y<x; y++) {
			if (win(x,y) && x-y<ansx-ansy) {
				ansx=x;
				ansy=y;
			}
		}
	}
	if (ansx==100) cout << "IMPOSSIBLE"; else
	printf("%d:%d",ansx,ansy);
	return 0;
}