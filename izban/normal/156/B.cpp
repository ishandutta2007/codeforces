#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int n,m,smn,spl;
int mn[100100],pl[100100],x[100100];
char c[100100];
bool ubil[100100];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	getline(cin,s);
	sscanf(s.c_str(),"%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		//scanf("%c %d",&c[i],&x[i]);
		getline(cin,s);
		c[i]=s[0];
		string s1="";
		for (int j=1; j<s.length(); j++) s1+=s[j];
		x[i]=atoi(s1.c_str());
		if (c[i]=='-') {
			mn[x[i]]++;
			smn++;
		} else {
			pl[x[i]]++;
			spl++;
		}
	}
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (pl[i]+smn-mn[i]==m) {
			ubil[i]=true;
			ans++;
		}
	}
	for (int i=0; i<n; i++) {
		if (ubil[x[i]] && ans>1) cout << "Not defined" << endl;
		else if (c[i]=='-') {
			if (ubil[x[i]]) cout << "Lie" << endl;
			else cout << "Truth" << endl;
		} else {
			if (ubil[x[i]]) cout << "Truth" << endl;
			else cout << "Lie" << endl;			
		}
	}
	return 0;
}