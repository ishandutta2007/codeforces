#include<iostream>
#include<algorithm>

using namespace std;

string a, b;

string ost (string s, int ind) {
	string res="";
	for (int i=0; i<s.size(); i++) {
		if (i!=ind) res+=s[i];
	}
	return res;
}

bool manji (string a, string b) {
	for (int i=0; i<a.size(); i++) {
		if (a[i]>b[i]) return 0;
		if (a[i]<b[i]) return 1;
	}
	return 1;
}

string f (string a, string b) {
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i=0; i<a.size(); i++) {
		if (a[i]>b[0]) continue;
		string t=ost(a, i);
		sort(t.begin(), t.end());
		if (a[i]==b[0]) {
			if (manji(t, ost(b, 0))) return a[i]+f(t, ost(b, 0));
		} else {
			reverse(t.begin(), t.end());
			return a[i]+t;
		}
	}
	return "";
}

int main () {
	cin >> a >> b;
	if (a.size()<b.size()) {
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		cout << a;
	} else {
		cout << f(a, b);
	}
	return 0;
}