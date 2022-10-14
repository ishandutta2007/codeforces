#include<iostream>
#include<map>
#include<set>

using namespace std;

const int MAXN = 1005;

int n;
string s1[MAXN], s2[MAXN], sol[MAXN];
string a, b;
set <string> ne, u;
map <string, int> m;
map <string, int> :: iterator it;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		s1[i]+=a[0];
		s1[i]+=a[1];
		s2[i]=s1[i];
		s1[i]+=a[2];
		s2[i]+=b[0];
		m[s1[i]]++;
	}
	for (it=m.begin(); it!=m.end(); it++) {
		string r=it->first;
		int cnt=it->second;
		if (cnt>1) {
			for (int i=0; i<n; i++) {
				if (s1[i]==r) {
					sol[i]=s2[i];
					ne.insert(s2[i]);
				}
			}
		}
	}
	while (1) {
		int br=0;
		for (int i=0; i<n; i++) {
			if (sol[i]=="" && ne.find(s1[i])!=ne.end()) {
				br++;
				sol[i]=s2[i];
				ne.insert(s2[i]);
			}
		}
		if (br==0) break;
	}
	for (int i=0; i<n; i++) {
		if (sol[i]=="") sol[i]=s1[i];
		u.insert(sol[i]);
	}
	if (u.size()==n) {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			cout << sol[i] << endl;
		}
	} else {
		cout << "NO";
	}
	return 0;
}