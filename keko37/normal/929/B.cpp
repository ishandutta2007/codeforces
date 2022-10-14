#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1005;

int n, k, sol;
string s[MAXN];
vector < pair <int, pair <int, int> > > v;

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<12; j++) {
			if (s[i] [j]!='.') continue;
			int cnt=0;
			if (j>0 && s[i] [j-1]=='S') cnt++;
			if (j<11 && s[i] [j+1]=='S') cnt++;
			v.push_back(make_pair(cnt, make_pair(i, j)));
		}
	}
	sort(v.begin(), v.end());
	for (int i=0; i<k; i++) {
		int x=v[i].second.first;
		int y=v[i].second.second;
		s[x] [y]='x';
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<12; j++) {
			if (s[i] [j]!='S') continue;
			if (j>0 && s[i] [j-1]!='-' && s[i] [j-1]!='.') sol++;
			if (j<11 && s[i] [j+1]!='-' && s[i] [j+1]!='.') sol++;
		}
	}
	cout << sol << endl;
	for (int i=0; i<n; i++) {
		cout << s[i] << endl;
	}
	return 0;
}