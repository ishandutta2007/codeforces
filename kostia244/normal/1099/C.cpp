#include <bits/stdc++.h>
using namespace std;

string s;
int c, l, f, k;

int main() {
	cin >> s >> k;
	c = f = l = 0;
	for (auto& i : s) {
		if (i == '?')
			l++;
		else if (i == '*')
			f++;
		else
			c++;
	}

	if(c < k) {
		if(f == 0) {
			cout << "Impossible";
		} else {
			s+="?";
			bool cont = true;
			for(int i = 0; i< (s.size() - 1); i++) {
				if(s[i] == '?' || s[i] == '*')
					continue;
				if(s[i + 1] == '*') {
					if(cont) {
						cont = false;
						int t = (k - c + 1);
						while(t--)
							cout << s[i];
					} else {
						cout << s[i];
					}
				} else {
					cout << s[i];
				}
			}
		}
	} else {
		int d = (f + l);
		if(d < (c - k))
			cout << "Impossible";
		else {
			d = (c - k);
			s += " ";
			for(int i = 0; i< (s.size() - 1); i++) {
				if(s[i] == '?' || s[i] == '*')
					continue;
				if(d > 0 && (s[i + 1] == '?' || s[i + 1] == '*')) {
					d--;
				} else {
					cout << s[i];
				}
			}
		}
	}

	return 0;
}