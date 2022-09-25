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

int n;
string s,curdir="/";

void ret() {
	int k=curdir.size()-2;
	while (curdir[k]!='/') k--;
	string s2="";
	for (int i=0; i<=k; i++) s2+=curdir[i];
	curdir=s2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		if (s=="cd") {
			cin >> s;
			if (s!="/") s+='/';
			if (s[0]=='/') {
				curdir="/";
				int k=1;
				while (k<s.size()) {
					string s1="";
					while (s[k]!='/')
						s1+=s[k], k++;
					k++;
					if (s1=="..") ret();
					else 
						curdir+=s1, curdir+='/';
				}
			} else {
				int k=0;
				while (k<s.size()) {
					string s1="";
					while (s[k]!='/')
						s1+=s[k], k++;
					k++;
					if (s1=="..") ret();
					else 
						curdir+=s1, curdir+='/';
				}
			}
		} else {
			cout << curdir << endl;
		}
	}

	return 0;
}