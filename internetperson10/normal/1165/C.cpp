#include <bits/stdc++.h>

using namespace std;

vector<int> ac;

int main() {
	int n, ans=0, a=0;
	cin >> n;
	string s;
	cin >> s;
	while(a+1<n) {
		ac.emplace_back(a);
		char t = s.at(a);
		a++;
		while(s.at(a)==t && a+1<n) a++;
		if(s.at(a)==t && a+1==n) {
			ac.pop_back();
			break;
		}
		ac.emplace_back(a);
		a++;
	}
	cout << n-ac.size() << '\n';
	for(a=0; a<ac.size(); a++) cout << s.at(ac[a]);
}