#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
string s;
vector<string> v;
int n;
bool gre(const string &a,const string &b) {
	if (a.size()>b.size()) return (true);
	if (a.size()<b.size()) return (false);
	return (a>=b);
}
void init(void) {
	cin >> s;
	vector<int> sta,fin;
	n=s.size();
	REP(i,n) {
		if (s[i]>'0') sta.push_back(i);
		if (i==n-1 || s[i+1]>'0') fin.push_back(i);
	}	
	assert(sta.size()==fin.size());
	REP(i,sta.size()) {
		assert(sta[i]<=fin[i]);
		v.push_back(s.substr(sta[i],fin[i]-sta[i]+1));
	}
	string tmp=v[0];
	int res=1;
	FOR(i,1,v.size()-1) {
		if (gre(tmp,v[i])) res++;
		else res=1;
		tmp+=v[i];
	}
	printf("%d",res);
}
int main(void) {
	ios::sync_with_stdio(false);
	init();
	return 0;
}