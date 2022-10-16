#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const string no="Impossible";
int main(void) {
	string l,r,s,t;
	cin >> s >> t;
	REP(i,s.size()) if (s[i]=='|') {
		l=s.substr(0,i);
		r=s.substr(i+1,s.size());
	}
	if ((l.size()+r.size()+t.size())%2==1) {
		cout << no;
		return 0;
	}
	int g=(l.size()+r.size()+t.size())/2;
	if (l.size()>g) {
		cout << no;
		return 0;
	}
	if (r.size()>g) {
		cout << no;
		return 0;
	}
	int x=g-l.size();
	int y=g-r.size();
	cout << l << t.substr(0,x) << '|' << r << t.substr(x,y);
	return 0;
}