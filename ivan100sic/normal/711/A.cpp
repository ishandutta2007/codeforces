#include "bits/stdc++.h"
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> v;
	bool found = false;
	for (int i=0; i<N; i++){
		string s;
		cin >> s;
		if (!found){
			if (s[0] == 'O' && s[1] == 'O'){
				found = true;
				s[0] = s[1] = '+';
			} else
			if (s[3] == 'O' && s[4] == 'O'){
				found = true;
				s[3] = s[4] = '+';
			}
		}
		v.push_back(s);
	}
	cout << (found ? "YES" : "NO") << endl;
	if (found) for (string s : v) cout << s << endl;
	return 0;
}