#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int n;
map <string, vector <string> > m;
map <string, vector <string> > :: iterator it;

bool f (string a, string b) {
	if (a.size()<=b.size()) return 0;
	if (a.substr(a.size()-b.size(), b.size())==b) return 1;
	return 0;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		int br;
		cin >> s >> br;
		for (int j=0; j<br; j++) {
			string t;
			cin >> t;
			m[s].push_back(t);
		}
	}
	cout << m.size() << endl;
	for (it=m.begin(); it!=m.end(); it++) {
		vector <string> v;
		for (int i=0; i<(it->second).size(); i++) {
			bool ok=1;
			for (int j=0; j<(it->second).size(); j++) {
				if (f((it->second)[j], (it->second)[i])) {
					ok=0;
					break;
				}
			}
			if (ok) v.push_back((it->second)[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		cout << (it->first) << " " << v.size() << " ";
		for (int i=0; i<v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}