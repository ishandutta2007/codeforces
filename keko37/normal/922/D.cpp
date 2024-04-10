#include<iostream>
#include<algorithm>

typedef long long llint;

using namespace std;

llint n, len, sol;
string s;
vector < pair <llint, llint> > v;

bool cmp (pair <llint, llint> p1, pair <llint, llint> p2) {
	return p1.first*p2.second>p1.second*p2.first;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		len=s.size();
		llint a=0, b=0;
		for (int j=0; j<len; j++) {
			if (s[j]=='s') a++; else b++;
			if (s[j]=='h') sol+=a;
		}
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);
	llint sum=0;
	for (int i=0; i<v.size(); i++) {
		sol+=v[i].second*sum;
		sum+=v[i].first;
	}
	cout << sol;
	return 0;
}