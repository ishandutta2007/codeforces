#include<iostream>
#include<vector>

using namespace std;

int n;
int l[20]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector <int> v, p;

void build () {
	for (int i=0; i<12; i++) {
		if (i==1) v.push_back(l[i]+1); else v.push_back(l[i]);
	}
	for (int i=0; i<12; i++) {
		v.push_back(l[i]);
	}
	for (int i=0; i<12; i++) {
		v.push_back(l[i]);
	}
	for (int i=0; i<12; i++) {
		if (i==1) v.push_back(l[i]+1); else v.push_back(l[i]);
	}
	for (int i=0; i<12; i++) {
		v.push_back(l[i]);
	}
}

vector <int> sub (int x) {
	vector <int> res;
	if (x+n>v.size()) return res;
	for (int i=0; i<n; i++) {
		res.push_back(v[x+i]);
	}
	return res;
}

int main () {
	build();
	cin >> n;
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;
		p.push_back(t);
	}
	for (int i=0; i<v.size(); i++) {
		if (sub(i)==p) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}