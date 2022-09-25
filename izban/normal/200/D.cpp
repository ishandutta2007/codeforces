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



const int maxn=1001;

int n,m,k,ans;
string s;
vector<string> a[maxn];
map<string,string> b;
vector<string> c[maxn];

vector<string> do1(string &s) {
	replace(s.begin(),s.end(),'(',' ');
	replace(s.begin(),s.end(),')',' ');
	replace(s.begin(),s.end(),',',' ');
	string s1;
	vector<string> ans;
	stringstream ss(s);
	ss >> s1;
	while (ss >> s1) {
		ans.push_back(s1);
	}
	return ans;
}

vector<string> do3(string &s) {
	replace(s.begin(),s.end(),'(',' ');
	replace(s.begin(),s.end(),')',' ');
	replace(s.begin(),s.end(),',',' ');
	string s1;
	vector<string> ans;
	stringstream ss(s);
	ss >> s1; ans.push_back(s1);
	while (ss >> s1) {
		ans.push_back(b[s1]);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n; getline(cin,s);
	for (int i=0; i<n; i++) {
		getline(cin,s);
		a[i]=do1(s);
	}
	cin >> m; 
	for (int i=0; i<m; i++) {
		string x,y;
		cin >> x >> y;
		b[y]=x;
	}
	cin >> k; getline(cin,s);
	for (int i=0; i<k; i++) {
		ans=0;
		getline(cin,s);
		c[i]=do3(s);
		for (int j=0; j<n; j++) if (a[j].size()==c[i].size() && a[j][0]==c[i][0]) {
			bool f=true;
			for (int ij=1; ij<a[j].size(); ij++) 
				if ((a[j][ij]!=c[i][ij]) && (a[j][ij]!="T")) 
					f=false;
			ans+=f;
		}
		cout << ans << endl;
	}
	return 0;
}