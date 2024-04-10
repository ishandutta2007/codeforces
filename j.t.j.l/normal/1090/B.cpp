#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

string s1 = "\\begin{thebibliography}{99}";
string s2 = "\\end{thebibliography}";

map<string, string> mp;
vector<string> f;

int main(){
	std::ios_base::sync_with_stdio(false);
	string s;
	vector<char> t;
	int flag = 0;
	int nico = 1;
	int pop = 0;
	while (getline(cin, s)) {
		if (s == s1) {
			flag = 1;
			for (int i = 0; i + 6 < t.size(); i++) {
				if (t[i] == '\\' && t[i + 1] == 'c' && t[i + 2] == 'i' && t[i + 3] == 't' && t[i + 4] == 'e' && t[i + 5] == '{') {
					i += 6;
					string str = "";
					while (t[i] != '}') {
						str.push_back(t[i]);
						i++;
					}
					f.push_back(str);
				}
			}
			continue;
		} 
		if (s == s2) {
			flag = 2;
			continue;
		}
		if (flag == 0) {
			for (auto &x : s)
				t.push_back(x);
		}
		if (flag == 1) {
			int i = 9;
			string p = "", q = "";
			while (s[i] != '}') {
				p.push_back(s[i]);
				i++;
			}
			for (; i < s.size(); i++) 
				q.push_back(s[i]);
			if (p != f[pop]) 
				nico = 0;
			mp[p] = q;
			pop++;
		}
	}
	if (nico)
		cout << "Correct" << endl;
	else {
		cout << "Incorrect" << endl;
		cout << s1 << endl;
		for (auto &x : f) {
			cout << "\\bibitem{" << x << mp[x] << endl;
		}
		cout << s2 << endl;
	}
	return 0;
}