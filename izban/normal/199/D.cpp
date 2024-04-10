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
const int inf=(1e9)+7;

bool f=false;
int n,k;
string s[2];
int d[2][maxn];

set<pair<int,pair<int,int> > > st;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	cin >> s[0] >> s[1];

	for (int i=0; i<n; i++) d[0][i]=d[1][i]=inf;
	d[0][0]=0;

	st.insert(make_pair(0,make_pair(0,0)));

	while (!st.empty()) {
		int cd=st.begin()->first;
		int cx=st.begin()->second.first;
		int cy=st.begin()->second.second;
		st.erase(st.begin());
		if (cy+k>=n) {
			f=true; break;
		}
		if (d[cx][cy+1]>cd+1 && s[cx][cy+1]!='X' && cy+1>cd) {
			st.erase(make_pair(d[cx][cy+1],make_pair(cx,cy+1)));
			d[cx][cy+1]=cd+1;
			st.insert(make_pair(d[cx][cy+1],make_pair(cx,cy+1)));
		}
		if (cy>0 && d[cx][cy-1]>cd+1 && s[cx][cy-1]!='X' && cy-1>cd) {
			st.erase(make_pair(d[cx][cy-1],make_pair(cx,cy-1)));
			d[cx][cy-1]=cd+1;
			st.insert(make_pair(d[cx][cy-1],make_pair(cx,cy-1)));
		}
		if (d[cx^1][cy+k]>cd+1 && s[cx^1][cy+k]!='X' && cy+k>cd) {
			st.erase(make_pair(d[cx^1][cy+k],make_pair(cx^1,cy+k)));
			d[cx^1][cy+k]=cd+1;
			st.insert(make_pair(d[cx^1][cy+k],make_pair(cx^1,cy+k)));
		}
		
	}
	cout << (f?"YES":"NO") << endl;

	return 0;
}