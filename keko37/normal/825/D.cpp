#include<iostream>
#include<vector>

using namespace std;

typedef long long llint;

int a, b, cnt, pos;
string s, t;
int l[30], p[30];
vector <int> v;

bool f (llint val) {
	llint res=0;
	for (int i=0; i<26; i++) {
		if (p[i]*val>l[i]) res+=p[i]*val-l[i];
	}
	return res<=cnt;
}

void con (llint val) {
	for (int i=0; i<26; i++) {
		if (p[i]*val>l[i]) {
			int d=p[i]*val-l[i];
			for (int j=0; j<d; j++) {
				s[v[pos]]=(char) (i+'a');
				pos++;
			}
		}
	}
}

int main () {
	cin >> s >> t;
	a=s.size();
	b=t.size();
	for (int i=0; i<a; i++) {
		if (s[i]=='?') {
			v.push_back(i);
			cnt++;
			continue;
		}
		l[s[i]-'a']++;
	}
	for (int i=0; i<b; i++) {
		p[t[i]-'a']++;
	}
	llint low=0, high=a, mid;
	while (low<high) {
		mid=(low+high+1)/2;
		if (f(mid)) {
			low=mid;
		} else {
			high=mid-1;
		}
	}
	con(low);
	for (int i=0; i<a; i++) {
		if (s[i]!='?') cout << s[i]; else cout << 'a';
	}
	return 0;
}