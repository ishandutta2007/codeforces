#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2005;

int n;
string s, t, r;
int l[30];
vector <int> v;

bool moguce () {
	for (int i=0; i<n; i++) {
		l[s[i]-'a']++;
		l[t[i]-'a']--;
	}
	for (int i=0; i<30; i++) {
		if (l[i]!=0) return 0;
	}
	return 1;
}

void shift (int x) {
	if (x==0) return;
	v.push_back(x);
	string res="";
	for (int i=1; i<=x; i++) {
		res+=s[n-i];
	}
	res+=s.substr(0, n-x);
	s=res;
}

int main () {
	cin >> n >> s >> t;
	if (!moguce()) {
		cout << -1;
		return 0;
	}
	int a=n/2, b=n/2, sgn=1;
	r=t[a];
	while (0<a || b<n-1) {
		if (sgn) {
			a--;
			r+=t[a];
		} else {
			b++;
			r+=t[b];
		}
		sgn=!sgn;
	}
	for (int i=0; i<n; i++) {
		shift(n);
		for (int j=i; j<n; j++) {
			if (s[j]==r[i]) {
				shift(n-j);
				shift(j-i);
				break;
			}
		}
	}
	if (s!=t) {
		shift(n);
	}
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}