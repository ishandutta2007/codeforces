#include<iostream>

using namespace std;

int n, len, naso, sol;
int l[50], p[50];
char c;
string s;

int main () {
	for (int i=0; i<26; i++) {
		l[i]=1;
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> c >> s;
		len=s.size();
		if (c=='.') {
			for (int j=0; j<len; j++) {
				l[s[j]-'a']=0;
			}
		} else if (c=='!') {
			if (naso) sol++;
			for (int j=0; j<26; j++) {
				p[j]=0;
			}
			for (int j=0; j<len; j++) {
				p[s[j]-'a']=1;
			}
			for (int j=0; j<26; j++) {
				l[j]&=p[j];
			}
		} else {
			if (naso && i!=n-1) sol++;
			if (i==n-1) {
				for (int j=0; j<26; j++) {
					l[j]=0;
				}
				l[s[0]-'a']=1;
			} else {
				l[s[0]-'a']=0;
			}
		}
		int cnt=0;
		for (int j=0; j<26; j++) {
			cnt+=l[j];
		}
		if (cnt==1) naso=1;
	}
	cout << sol;
	return 0;
}